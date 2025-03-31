import socket
import sys

def send_negotiation_request(server_address, n_port, command, filename):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    message = f"{command},{filename}"
    client_socket.sendto(message.encode(), (server_address, n_port))
    r_port_data, _ = client_socket.recvfrom(1024)
    r_port = r_port_data.decode()
    client_socket.close()

    return int(r_port)

def send_file(tcp_socket, filename):
    try:
        with open(filename, "rb") as f:
            while True:
                bytes_read = f.read(1024)
                if not bytes_read:
                    break
                tcp_socket.sendall(bytes_read)
        print(f"File '{filename} sent succesfully.'")
    except FileNotFoundError:
        print(f"ERROR: File {filename} not found")
    except Exception as e:
        print(f"ERROR: An error occurred: {e}")

def receive_file(tcp_socket, filename):
    bytes_read = tcp_socket.recv(1024)
    if bytes_read.startswith(b"ERROR:"):
        print(bytes_read.decode())
        return

    with open(filename, "wb") as f:
        f.write(bytes_read)
        while True:
            bytes_read = tcp_socket.recv(1024)
            if not bytes_read:
                break
            f.write(bytes_read)
    print(f"File {filename} received successfully.")

def setup_tcp_connection(server_address, r_port):
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp_socket.connect((server_address, r_port))
    print(f"TCP connection established with server on {r_port}")
    if command == "PUT":
        send_file(tcp_socket, filename)
    elif command == "GET":
        receive_file(tcp_socket, filename)
    else:
        print("Command not valid.")
    tcp_socket.close()

def main(server_address, n_port, command, filename):
    r_port = send_negotiation_request(server_address, n_port, command, filename)
    print(f"Received r_port from server: {r_port}")
    setup_tcp_connection(server_address, r_port)

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print(f"Usage: python3 client.py <server_address> <n_port> <command> <filename>")
        sys.exit(1)

    server_address = sys.argv[1]
    n_port = int(sys.argv[2])
    command = sys.argv[3]
    filename = sys.argv[4]

    main(server_address, n_port, command, filename)
