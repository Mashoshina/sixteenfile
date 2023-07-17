#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "getopt.h"

typedef struct Sets
{
	char* fname;
	int ofset;
	long long int size;
	int g;
	int count;
}Sets;

#ifndef FUNC_H
#define FUNC_H

int check(char* str);
void printFile(FILE* file, Sets* sets);
char* createRevers(char* buff, int sizeOfElem, int sizeOfBuff);
void printHex(char c);
#endif // !FUNC_H
