# Minitalk - Server and Client Communication via Unix Signals

## Overview

Minitalk is a simple client-server communication system implemented in C, utilizing Unix signals for data transmission. The system comprises two programs: `server` and `client`. The `client` is responsible for sending strings to the `server` using Unix signals, and the `server`, upon receiving signals, prints the strings to the console.

## Compilation

### Requirements

- C Compiler (e.g., GCC)
- [libftprintf](https://github.com/mouadelbh/Printf) library

### Compilation Commands

```bash
make
```
The make command compiles both the server and client programs. The libftprintf library is assumed to be available in the ./ft_printf/ directory.

## Execution
# Server
```bash
./server
```
The server program listens for incoming signals from the client and prints the received strings to the console.

# Client
```bash
./client [SERVER_PID] "Hello, Server!"
```
Replace [SERVER_PID] with the PID of the running server process.
Replace [STRING] with the string you want to send to the server.
## Example
Open two terminal windows.
In the first window, run the server:
```bash
./server
7896
```
In the second window, run the client:
```bash
./client 7896 "is this a jojo reference"
```
And now the string will be printed in the first terminal window
```
./server
7896
is this a jojo reference
```

## Notes
The server prints the received strings to the console.
The client sends strings to the server using Unix signals (SIGUSR1 and SIGUSR2).
The code includes a simple signal handler and byte-to-char conversion for data processing.
Note: Ensure that the libftprintf library is available in the specified path.
