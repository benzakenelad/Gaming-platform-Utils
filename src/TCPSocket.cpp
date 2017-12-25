/*
 * TCPSocket.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Elad Ben Zaken
 */

#include "TCPSocket.h"

using namespace networkingLab;

TCPSocket::TCPSocket(int port) :
		Socket(port) {
	isListeningServerFlag = true;
	socketFD = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFD < 0) {
		perror("Failed allocating TCP server listening socket.");
		return;
	}
	this->bindd(port);
}

TCPSocket::TCPSocket() :
		Socket(-1) {
	isListeningServerFlag = false;
}

TCPSocket::TCPSocket(int socketFD, struct sockaddr_in cli_addr) :
		Socket(-1) {
	isListeningServerFlag = false;
	this->socketFD = socketFD;
	this->connected_addr = cli_addr;
	this->port = ntohs(cli_addr.sin_port);
}

bool TCPSocket::connectt(string ip, int port) {
	this->port = port;
	if (socketFD > 0)
		close(socketFD);
	socketFD = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFD < 0) {
		perror("Failed allocating TCP client connection socket.");
		return false;
	}

	bzero(&connected_addr, sizeof(connected_addr));
	connected_addr.sin_family = AF_INET;
	connected_addr.sin_port = htons(port);
	connected_addr.sin_addr.s_addr = inet_addr(ip.c_str());

	if (connect(socketFD, (struct sockaddr *) &connected_addr,
			sizeof(connected_addr)) < 0) {
		perror("error connecting to server");
		return false;
	}

	// Initialize connected address details
	bzero(&connected_addr, sizeof(connected_addr));
	socklen_t addressLength = sizeof(connected_addr);
	getsockname(socketFD, (struct sockaddr*) &connected_addr,
	&addressLength);

	return true;
}

void TCPSocket::listenn(int backLog) {
	if (isListeningServerFlag)
		listen(socketFD, backLog);
}

TCPSocket* TCPSocket::acceptt() {
	if (isListeningServerFlag) {
		struct sockaddr_in cli_addr;
		bzero(&cli_addr, sizeof(cli_addr));

		socklen_t len = sizeof(cli_addr);
		int connect_sock = accept(socketFD, (struct sockaddr *) &cli_addr,
				&len);

		return new TCPSocket(connect_sock, cli_addr);
	} else {
		perror("Can not accept on connection socket.");
		return NULL;
	}
}

int TCPSocket::readd(char* buffer, int length) {
	if (!isListeningServerFlag) {
		return read(socketFD, buffer, length);
	} else {
		perror("Can not receive messages on server listening socket.");
		return -1;
	}
}

int TCPSocket::writee(const char* buffer, int length) {
	if (!isListeningServerFlag) {
		return write(socketFD, buffer, length);
	} else {
		perror("Can not send messages from server listening socket.");
		return -1;
	}

}

void TCPSocket::closee() {
	IFile::closee();
	if (isListeningServerFlag)
		cout << "listening socket is closed" << endl;
	else
		cout << "connection socket is closed" << endl;
}

int TCPSocket::getPort(){
	return (int) ntohs(connected_addr.sin_port);
}

string TCPSocket::getIP(){
	string IP = inet_ntoa(connected_addr.sin_addr);
	return IP;
}

string TCPSocket::getConnectionIPandPort(){
	string ipANDport = inet_ntoa(connected_addr.sin_addr);
	ipANDport.append(":");
	char buff[10];
	sprintf(buff,"%d",ntohs(connected_addr.sin_port));
	ipANDport.append(buff);

	return ipANDport;
}

TCPSocket::~TCPSocket() {

}

