/*
 * MultipleTCPSocketListener.cpp
 *
 *  Created on: May 20, 2017
 *      Author: elad
 */

#include "MultipleTCPSocketListener.h"

#include <stddef.h>
#include <sys/select.h>
#include <iterator>

namespace networkingLab {

MultipleTCPSocketListener::MultipleTCPSocketListener() {
}

void MultipleTCPSocketListener::addSocket(IFile* socket) {
	sockets.push_back(socket);
}

void MultipleTCPSocketListener::addSockets(vector<IFile*> socketVec) {
	//set the given sockets as the socket list to select from
	sockets = socketVec;
}

IFile* MultipleTCPSocketListener::listenToSocket(){
	return this->listenToSocket(-1);
}

IFile* MultipleTCPSocketListener::listenToSocket(int timeout) {
	if(timeout < 0)
		timeout = 0;
	struct timeval tv = {timeout, 0};
	vector<IFile*>::iterator startIter = sockets.begin();
	vector<IFile*>::iterator endIter = sockets.end();

	// create local set for the select function (fd_set)
	fd_set fdset;
	FD_ZERO(&fdset);
	int highestfd = 0;

	// fill the set with file descriptors
	for (; startIter != endIter; startIter++) {
		FD_SET((*startIter)->getSocketFd(), &fdset);
		if ((*startIter)->getSocketFd() > highestfd) // find the max file descriptor value
			highestfd = (*startIter)->getSocketFd();
	}

	//perform the select
	int returned = 0;
	if (timeout > 0)
		returned = select(highestfd + 1, &fdset, NULL, NULL, &tv);
	else
		returned = select(highestfd + 1, &fdset, NULL, NULL, NULL);



	// check the returned value from the select to find the socket that is ready
	// if select return a valid socket return the matching TCPSocket object otherwise return NULL

	if (returned == -1 || returned == 0)
		return NULL;

	int n = sockets.size();

	for (int i = 0; i < n; i++) {
		IFile* tmpSocket = sockets[i];
		if (FD_ISSET(tmpSocket->getSocketFd(), &fdset))
			return tmpSocket;
	}

	return NULL;
}

} /* namespace networkingLab */

