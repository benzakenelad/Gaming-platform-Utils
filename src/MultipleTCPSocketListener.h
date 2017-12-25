/*
 * MultipleTCPSocketListener.h
 *
 *  Created on: May 20, 2017
 *      Author: elad
 */

#ifndef SRC_MULTIPLETCPSOCKETLISTENER_H_
#define SRC_MULTIPLETCPSOCKETLISTENER_H_

#include <vector>

#include "TCPSocket.h"

#define SIZE 20

namespace networkingLab {
class MultipleTCPSocketListener {
	// add class properties which include a vector (this will be the socket list) to hold the given sockets
	vector<IFile*> sockets;

public:
	MultipleTCPSocketListener();
	/*
	 * Add the given socket to the socket list to be listen on
	 */
	void addSocket(IFile* socket);

	/*
	 * Set the given sockets to the socket list to be listen on
	 */
	void addSockets(vector<IFile*> socketVec);

	/*
	 * This method checks to see if any of the previous given sockets are ready for reading
	 * It returns one of the Sockets that are ready.
	 */
	IFile* listenToSocket(int timeout);
	IFile* listenToSocket();
};
} /* namespace networkingLab */
#endif /* SRC_MULTIPLETCPSOCKETLISTENER_H_ */
