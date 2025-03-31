import sys
import socket
import errno
from packet import Packet

# Create a UDP socket that is connected to an available port
def create_udp_socket(port_number):
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # check for port availibility
        udp_socket.bind(("", int(port_number)))
    except socket.error as e:
        if e.errno == errno.EADDRINUSE:
            print(f"Port {port_number} is already in use. Please provide an open port.")
            sys.exit(1)
        else:
            raise
    return udp_socket

def main(host_address, data_port, ack_port, timeout_interval, filename):
    # UDP socket used by the sender to receive ACKs from the emulator
    ack_socket = create_udp_socket(ack_port)
    # UDP socket used by the emulator to receive data from the sender
    data_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # set the timeout for the ack socket
    ack_socket.settimeout(int(timeout_interval) / 1000.0)

    # open the file for the two logs
    seqnum_log = open("seqnum.log", "w")
    ack_log = open("ack.log", "w")

    try:
        with open(filename, "r", encoding="utf-8") as file:
            # start by reading the entire file
            file_data = file.read()
            # split the file into packet of size 500 characters
            packet_data = [file_data[i:i+500] for i in range(0, len(file_data), 500)]
            # array to keep track of which pcakets have been acked
            acked = [False] * len(packet_data)

            while not all(acked):
                counter = 0
                # select the first 10 packets that have not been acked
                for i in range(len(packet_data)):
                    if counter >= 10:
                        break
                    # found packet that has not been acked
                    # send it to the receiver and write it to the seqnum log
                    if not acked[i]:
                        data = packet_data[i]
                        packet = Packet(1, i, len(data), data)
                        data_socket.sendto(packet.encode(), (host_address, data_port))
                        seqnum_log.write(f"{i}\n")
                        counter += 1

                # wait for the ack packets for the 10 packets that we have sent
                try: 
                    while True:
                        # we have received all 10 ack packets and we can break 
                        # without waiting for the entire timeout interval
                        if counter == 0:
                            break
                        ack_data, _ = ack_socket.recvfrom(1024)
                        ack_packet = Packet(ack_data)
                        if ack_packet.typ == 0 and 0 <= ack_packet.seqnum < len(packet_data):
                            # mark the packet as acked in the array
                            acked[ack_packet.seqnum] = True
                            # write the ack to the ack log
                            ack_log.write(f"{ack_packet.seqnum}\n")
                            counter -= 1
                except socket.timeout:
                    pass
                        
            
            # send the EOT packet, as all other packets have been acked
            eot_packet = Packet(2, len(packet_data), 0, "")
            data_socket.sendto(eot_packet.encode(), (host_address, data_port))
            seqnum_log.write("EOT\n")

            # wait for the ack packet for the EOT packet
            while True:
                ack_data, _ = ack_socket.recvfrom(1024)
                ack_packet = Packet(ack_data)
                if ack_packet.typ == 2:
                    ack_log.write("EOT\n")
                    # close the sockets before terminating
                    ack_socket.close()
                    data_socket.close()
                    return

    except FileNotFoundError:
        print(f"File {filename} not found.")
        sys.exit(1)

if __name__ == "__main__":
    empty = False
    for i in range(len(sys.argv)):
        if sys.argv[i] == "":
            empty = True
    if(len(sys.argv) != 6 or empty):
        print("ERROR: Incorrect Usage")
        print("The program receiver.py takes in 5 parameters")

        print("<host address for the network emulator>")
        print("<UDP port number used by the emulator to receive data from the sender>")
        print("<UDP port number used by the sender to receive ACKs from the emulator>")
        print("<timeout interval in units of millisecond>")
        print("<name of the file to be transferred>")
        sys.exit(1)

    host_address = sys.argv[1]
    data_port = int(sys.argv[2])
    ack_port = sys.argv[3]
    timeout_interval = sys.argv[4]
    filename = sys.argv[5]

    main(host_address, data_port, ack_port, timeout_interval, filename)
