import sys
import random
import socket
import os
import errno

# Create a UDP socket that is connected to an available port
def create_udp_socket():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind(("", 0))
    return udp_socket

# Process the UDP data to extract the command as well as the file name
def process_request(data):
    try:
        message = data.decode("utf-8")
        command, filename = message.split(",")
        return command, filename
    except Exception as e:
        print(f"Error processing request: {e}")
        return None, None

# Send a random available port to the client
# Continuously tries a port until it finds one that is free
def send_r_port(udp_socket, client_address):
    while True:
        r_port = random.randint(1024, 65535)
        # Test if port is free
        try:
            test_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            test_socket.bind(("", r_port))
            test_socket.close()
            break
        except socket.error as e:
            if e.errno == errno.EADDRINUSE:
                print(f"Port {r_port} is already in use. Trying another port...")
                continue
            else:
                raise

    udp_socket.sendto(str(r_port).encode("utf-8"), client_address)
    return r_port


# Handle the PUT command to receive and store a file.
def handle_put_command(connection, filename, directory):
    file_path = os.path.join(directory, filename)
    with open(file_path, "wb") as f:
        while True:
            data = connection.recv(1024)
            if not data:
                break
            f.write(data)
        
        # Check to see if the file is empty
        if f.tell() == 0:
            print(f"Could not receive file '{filename}'")
            f.close()
            os.remove(file_path)
        else: 
            print(f"File '{filename}' received and saved to '{directory}'")

# Handle the GET command to send a file to the client
def handle_get_command(connection, filename, directory):
    file_path = os.path.join(directory, filename)
    if os.path.exists(file_path):
        with open(file_path, "rb") as f:
            connection.sendfile(f)
        print(f"File '{filename} sent successfully'")
    else:
        connection.send(b"ERROR: File not found")
        connection.close()
        print(f"File '{filename}' not found.")

def main(directory):
    udp_socket = create_udp_socket()
    _, n_port = udp_socket.getsockname()
    print(f"SERVER_PORT={n_port}")
    print(f"Storage Directory: {directory}")

    while(True):
        data, client_address = udp_socket.recvfrom(1024)
        command, filename = process_request(data)
        if not (command and filename):
            print("ERROR: Missing command or filename")
            sys.exit(1)

        r_port = send_r_port(udp_socket, client_address)

        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        tcp_socket.bind(("", r_port))
        tcp_socket.listen(1)
        print(f"Transaction server listening on port {r_port}")
        conn, addr = tcp_socket.accept()
        print(f"Connected to {addr}")

        if command == "GET":
            handle_get_command(conn, filename, directory)
        elif command == "PUT":
            handle_put_command(conn, filename, directory)
        else:
            print("ERROR: Command not valid")

        conn.close()
        tcp_socket.close()


if __name__ == "__main__":
    if(len(sys.argv) != 2 or sys.argv[1] == ""):
        print("Usage: python3 server.py <storage_directory>")
        sys.exit(1)

    directory = sys.argv[1]
    main(directory)
