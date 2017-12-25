/*
 * UDPMSN.cpp
 *
 *  Created on: May 19, 2017
 *      Author: elad
 */

#include "UDPMSN.h"
using namespace networkingLab;
UDPMSN::UDPMSN(int port) {
	UDPsock = new UDPSocket(port);
}

void UDPMSN::send(string msg) {
	UDPsock->writee(msg.c_str(),msg.length());
}

void UDPMSN::cclose() {
	UDPsock->closee();
	usleep(50000);
}

void UDPMSN::connectt(string ip, int port) {
	UDPsock->connectt(ip,port);
}

string UDPMSN::recv(){
	char buffer[SIZE];
	int n = UDPsock->readd(buffer,SIZE);
	if(n <= 0)
		return "";
	buffer[n] = '\0';

	return buffer;
}
