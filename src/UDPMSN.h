/*
d * UDPMSN.h
 *
 *  Created on: May 19, 2017
 *      Author: elad
 */

#ifndef SRC_UDPMSN_H_
#define SRC_UDPMSN_H_

#include "MThread.h"
#include "UDPSocket.h"
#define SIZE 1024


namespace networkingLab {

class UDPMSN {
private:
	UDPSocket* UDPsock;
public:
	UDPMSN(int port);
	void send(string msg);
	void connectt(string ip, int port);
	string recv();
	void cclose();
};

} /* namespace networkingLab */
#endif /* SRC_UDPMSN_H_ */
