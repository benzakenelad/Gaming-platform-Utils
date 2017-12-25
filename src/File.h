/*
 * File.h
 *
 *  Created on: May 27, 2017
 *      Author: elad
 */

#ifndef SRC_FILE_H_
#define SRC_FILE_H_

#include "IFile.h"
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

using namespace std;

namespace networkingLab {
class File: public IFile {
public:
	File(string path);
	virtual int readd(char* buffer, int length);
	virtual int writee(const char* buffer, int length);
	virtual void closee();
	virtual ~File();
};

} /* namespace networkingLab */
#endif /* SRC_FILE_H_ */
