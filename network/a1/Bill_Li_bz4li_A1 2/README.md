# CS456 Assignment 1 - Bill Li (bz4li)

This project implements a file server that can handle file upload (PUT) and download (GET) requests from clients. The server uses UDP for initial communication and negotiation of a TCP port, and then switches to TCP for reliable file transfer. This design ensures an efficient and reliable file transfer process, using the strengths of both UDP and TCP protocols.

1. Start the server by running:

```
./server.sh <storage_director>
```

- `<storage_directory>` is the path to the directory where uploaded files should be stored or where files to be downloaded are located.

2. Interact with the server from the client by running:

```
./client.sh <server_address> <n_port> <command> <filename>")
```

- `server_address` is the IP address or hostname of the machine currently running the server.
- `n_port` is the port number the server is running on which will be printed out by the server.
- `command` is either `PUT` or `GET`, which describes whether a file will be sent to the server or received.
- `filename` is the name of the file being sent or received.

Dependencies

- Python 3.x
- Standard Python libraries: `sys`, `random`, `socket`, `os`, `errno`
