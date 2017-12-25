/*
 * Socket.h
 *
 *  Created on: May 27, 2017
 *      Author: elad
 */

#ifndef SRC_SOCKET_H_
#define SRC_SOCKET_H_

#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdio>
#include <stdio.h>
#include <arpa/inet.h>
#include <iostream>
#include "IFile.h"

using namespace std;

namespace networkingLab {
class Socket : public IFile{
protected:
	int port;
	struct sockaddr_in connected_addr;
public:
	Socket(int port);
	void bindd(int port);
	virtual bool connectt(string ip, int port) = 0;

	string fromAddr(); // return the address of the connected peer.

	int getPort() const {
		return port;
	}

	virtual ~Socket();

};
} /* namespace networkingLab */

#endif /* SRC_SOCKET_H_ */
