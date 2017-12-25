/*
 * IFile.h
 *
 *  Created on: May 27, 2017
 *      Author: elad
 */

#ifndef SRC_IFILE_H_
#define SRC_IFILE_H_

#include <unistd.h>

namespace networkingLab {
class IFile {
protected:
	int socketFD;
public:
	IFile(){
		socketFD = -1;
	}
	virtual int readd(char* buffer, int length) = 0;
	virtual int writee(const char* buffer, int length) = 0;
	virtual void closee() {
		if (socketFD >= 0)
			close(socketFD);
	}
	virtual int getSocketFd() const {
		return socketFD;
	}

	virtual ~IFile(){}
};
} /* namespace networkingLab */
#endif /* SRC_IFILE_H_ */
