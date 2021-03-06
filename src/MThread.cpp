/*
 * MThread.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: elad
 */


#include "MThread.h"

#include <stdio.h>

using namespace std;
using namespace networkingLab;

MThread::MThread(){
	this->threadId = 0;
}

void* worker(void* arg){
	MThread* threadObj = (MThread*)arg;
	threadObj->run();
	threadObj->threadId = 0;
	return NULL;
}

void MThread::start(){
	pthread_create(&threadId,NULL,worker,(void*)this);
}

void MThread::waitForThread(){
	pthread_join(threadId,NULL);
}

MThread::~MThread(){
	if (threadId>0){
		//kills the thread if exist
		pthread_cancel(threadId);
		printf("Thread was canceled\n");
	}
}

