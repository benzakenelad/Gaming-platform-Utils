/*
 * UDPsocket.h
 *
 *  Created on: Apr 4, 2017
 *      Author: elad
 */

#ifndef SRC_UDPSOCKET_H_
#define SRC_UDPSOCKET_H_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "Socket.h"

using namespace std;
namespace networkingLab {

class UDPSocket : public Socket{
private:
	struct sockaddr_in from;

public:
	/*
	 *   initialize a UDP socket and binds it on the given port. if no
	 	 port is specified a default port 9999 is set. This UDP socket can be used both for
	 	 server socket and client socket
	 */
	UDPSocket(int port);
	virtual bool connectt(string ip, int port);
	/*
	 *   reads an incoming message from the UDP
	 	 socket. the message is copied into the given buffer up to the specified length.
	 */
	virtual int readd(char* buffer, int length);
	/*
	 *   sends the given message as a UDP
	 	 message to the given address specified by IP and port.
	 */
	virtual int writee(const char* buffer, int length);
	/*
	 *   reply to an incoming message, this method will send the
	 	 given message as a UDP message to the peer from which the last message was
	 	 received.
	 */
	int reply(string msg);
	/*
	 *   close the UDP socket.
	 */
	virtual void closee();
	/*
	 *   return the sender IP of the last received message.
	 */
	virtual ~UDPSocket();
};

} /* namespace networkingLab */

#endif /* SRC_UDPSOCKET_H_ */
