/*
 * File.cpp
 *
 *  Created on: May 27, 2017
 *      Author: elad
 */

#include "File.h"

#include <iostream>

using namespace networkingLab;

File::File(string path) {
	socketFD = open(path.c_str(), O_RDWR);
	if (socketFD < 0)
		perror("Could not open the specified file.");
}

int networkingLab::File::readd(char* buffer, int length) {
	if (socketFD >= 0) {
		int n = read(socketFD, buffer, length);
		if(n < 0)
			perror("reading from file error.\n");
		return n - 1;
	}
	else
			perror("negative socketFD.\n");
	return -1;
}

int networkingLab::File::writee(const char* buffer, int length) {
	if (socketFD >= 0) {
		int n = write(socketFD, buffer, length);
		if(n != length)
			perror("writing to file error.\n");
		return n;
	}
	else
		perror("negative socketFD.\n");
	return -1;
}

void networkingLab::File::closee() {
	IFile::closee();
}

File::~File() {
}

