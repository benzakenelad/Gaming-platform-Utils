/*
 * Socket.cpp
 *
 *  Created on: May 27, 2017
 *      Author: elad
 */

#include "Socket.h"


using namespace networkingLab;

Socket::Socket(int port) {
	bzero(&connected_addr, sizeof(connected_addr));
	this->port = port;
}

void Socket::bindd(int port) {

	// clear the s_in struct
	bzero(&connected_addr, sizeof(connected_addr));

	//sets the s_in address
	connected_addr.sin_family = (short) AF_INET;
	connected_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	connected_addr.sin_port = htons((u_short) port);

	//bind the socket to the specified address
	if (bind(socketFD, (struct sockaddr*) &connected_addr, sizeof(connected_addr)) < 0) {
		perror("binding error");
	}
}

string Socket::fromAddr(){
	return inet_ntoa(connected_addr.sin_addr);
}

Socket::~Socket() {
}

