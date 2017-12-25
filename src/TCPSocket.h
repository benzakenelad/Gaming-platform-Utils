/*
 * TCPSocket.h
 *
 *  Created on: Apr 24, 2017
 *      Author: elad
 */

#ifndef SRC_TCPSOCKET_H_
#define SRC_TCPSOCKET_H_
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <string>
#include "Socket.h"

using namespace std;

namespace networkingLab {

class TCPSocket : public Socket{
private:

	bool isListeningServerFlag; // if true : this is a listening socket. else : this is a connection socket

	TCPSocket(int socketFD, struct sockaddr_in cli_addr);
public:
	TCPSocket(int port); // constructor to create a TCP server listening socket.
	TCPSocket(); // constructor to creates TCP connection socket. (with out connection)
	void listenn(int backLog); // perform listen on server listening socket.
	virtual bool connectt(string ip, int port);
	TCPSocket* acceptt(); // blocks call until the server listening socket receiving connection, and returns a new TCP connection socket.
	virtual int readd(char* buffer, int length); // read from connection socket into the given buffer up to the buffer given length, return the number of bytes read.
	virtual int writee(const char* buffer, int length); // send the given message to the other peer of the connection socket.
	virtual void closee(); // close the socket and free all resources
	int getPort(); // get connection Port
	string getConnectionIPandPort(); // get connection IP and Port
	string getIP(); // get connection IP

	virtual ~TCPSocket();

};
} /* namespace networkingLab */
#endif /* SRC_TCPSOCKET_H_ */

