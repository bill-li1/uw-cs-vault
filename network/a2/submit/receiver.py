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

def main(hostname, data_port, ack_port, filename):
    # UDP socket used by the link emulator to receive ACKs from the receiver
    data_socket = create_udp_socket(data_port)
    # UDP socket used by the receiver to receive data from the emulator
    ack_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # buffer for data that arrives out of order
    # the key is the sequence number of the packet
    # the value is the data of the packet
    buffer = {}

    # the sequence number of the packet that we are expecting
    seqnum = 0

    with open(filename, "wb") as f:
        while(True):
            packet_data, _ = data_socket.recvfrom(1024)
            # decode the packet
            packet = Packet(packet_data)

            # we have received the EOT packet
            if packet.typ == 2:
                # we must send an EOT packet back to the sender
                eot_ack_packet = Packet(2, packet.seqnum, 0, "")
                ack_socket.sendto(eot_ack_packet.encode(), (hostname, ack_port))
                break

            # we have received a packet so we must send an ACK pcaket back
            ack_packet = Packet(0, packet.seqnum, 0, "")
            ack_socket.sendto(ack_packet.encode(), (hostname, ack_port))

            # the packet's sequnce number is the expected sequnece number
            # we know this is the next packet so we can write it to the file
            # and increment the sequnece number we are expecting. 
            if packet.typ == 1 and packet.seqnum == seqnum:
                f.write(packet.data.encode('utf-8'))
                seqnum += 1
                # We must now check for any buffered data that 
                # can now be written to the file as well
                while seqnum in buffer:
                    f.write(buffer.pop(seqnum).encode('utf-8'))
                    seqnum += 1
            # we have received a packet that is out of order so we store it in the buffer
            elif packet.typ == 1:
                buffer[packet.seqnum] = packet.data
    
    # close the sockets before terminating
    data_socket.close()
    ack_socket.close()

if __name__ == "__main__":
    empty = False
    for i in range(len(sys.argv)):
        if sys.argv[i] == "":
            empty = True
    if(len(sys.argv) != 5 or empty):
        print("ERROR: Incorrect Usage")
        print("The program receiver.py takes in 4 parameters")

        print("<hostname for the network emulator>")
        print("<UDP port number used by the link emulator to receive ACKs from the receiver>")
        print("<UDP port number used by the receiver to receive data from the emulator>")
        print("<name of the file into which the received data is written>")
        sys.exit(1)

    hostname = sys.argv[1]
    ack_port = int(sys.argv[2])
    data_port = sys.argv[3]
    filename = sys.argv[4]

    main(hostname, data_port, ack_port, filename)
