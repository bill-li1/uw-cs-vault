# CS456 Assignment 2 - Bill Li (bz4li)

This project implements a Reliable Data Transfer (RDT) protocol over UDP to simulate reliable file transmission over a network with potential packet loss and reordering. The protocol ensures reliable data transfer from a sender to a receiver through the use of acks and sequence numbers. The project includes a sender program for transmitting data, a receiver program for receiving data, and logging functionality to track the sequence numbers of sent and received packets.

1. Start the network emulator by running:

```
./nEmulator 9991 localhost 9994 9993 localhost 9992 1 0.3 1
```

To run nEmulator, you need to supply the following command line parameters in the given order:

- emulator's receiving UDP port number in the forward (sender) direction
- receiver's network address
- receiver's receiving UDP port number
- emulator's receiving UDP port number in the backward (receiver) direction
- sender's network address
- sender's receiving UDP port number
- maximum delay of the link in units of ms
- packet discard probability
- verbose-mode

2. Start the receiver by running:

```
python3 sender.py <host_name> <ack_port> <data_port> <timeout_interval> <filename>

```

- hostname for the network emulator
- UDP port number used by the link emulator to receive ACKs from the receiver
- UDP port number used by the receiver to receive data from the emulator
- name of the file into which the received data is written

3. Start the sender by running:

```
pytthon3 receiver.py <host_address> <data_port> <ack_port> <timeout_interval> <filename>
```

- host address of the network emulator
- UDP port number used by the emulator to receive data from the sender
- UDP port number used by the sender to receive ACKs from the emulator
- timeout interval in units of millisecond
- name of the file to be transferred

Dependencies

- Python 3.x
- Standard Python libraries: `sys`, `random`, `socket`, `os`, `errno`

```

```
