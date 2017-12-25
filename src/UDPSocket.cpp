/*
 * UDPSocket.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: elad
 */

#include "UDPSocket.h"

using namespace std;

namespace networkingLab {

UDPSocket::UDPSocket(int port) : Socket(port) {

	// allocate resources for end point
	socketFD = socket(AF_INET, SOCK_DGRAM, 0);
	bindd(port);
}


int UDPSocket::readd(char* buffer, int length) {
	int n;
	int fsize = sizeof(from);
	n = recvfrom(socketFD, buffer, length, 0, (struct sockaddr*) &from,
			(socklen_t *) &fsize);
	return n;
}

int UDPSocket::writee(const char* buffer, int length) {
	int n = sendto(socketFD, buffer, length, 0,
			(struct sockaddr*) &connected_addr, sizeof(connected_addr));
	if (n < 0)
		perror("failed to send message");
	return n;
}

bool UDPSocket::connectt(string ip, int port) {
	bzero((char*) &connected_addr, sizeof(connected_addr));
	connected_addr.sin_family = (short) AF_INET;
	connected_addr.sin_addr.s_addr = inet_addr(ip.data());
	connected_addr.sin_port = htons(port);
	return true;

}

int UDPSocket::reply(string msg) {
	return sendto(socketFD, msg.data(), msg.length(), 0,
			(struct sockaddr *) &from, sizeof(from));
}

void UDPSocket::closee() {
	shutdown(socketFD, SHUT_RDWR);
	IFile::closee();
	cout << "closing socket" << endl;
}

UDPSocket::~UDPSocket() {

}

} /* namespace networkingLab */

