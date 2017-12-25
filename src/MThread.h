/*
 * MThread.h
 *
 *  Created on: Apr 6, 2017
 *      Author: elad
 */

#ifndef MTHREAD_H_
#define MTHREAD_H_

#include <pthread.h>

namespace networkingLab {

class MThread{
public:
	pthread_t threadId;

public:
	MThread();
	virtual void run() = 0;
	void start();
	void waitForThread();
	virtual ~MThread();
};

} /* namespace networkingLab */
#endif /* MTHREAD_H_ */
