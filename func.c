#include "func.h"

int check(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isdigit(str[i]))
		{
			//num += atoi(str[i]) * 10 * (len - i);
			continue;
		}
		else
			return 0;
	}

	return (!0);
}

char* createRevers(char* buff, int sizeOfElem, int sizeOfBuff)
{
	char* arr = (char*)malloc(sizeOfElem * (sizeOfBuff + 1));
	memset(arr, 0, (sizeOfBuff + 1));
	for (int i = 0, j = sizeOfBuff - 1; i < sizeOfBuff, j >= 0; i++, j--)
	{
		arr[i] = buff[j];
	}
	return arr;
}

void printHex(char c)
{
	char alp[] = "0123456789ABCDEF";
	printf_s("%c%c", alp[c / 16], alp[c % 16]);
}

void printFile(FILE* file, Sets* sets)
{
	fseek(file, 0, SEEK_END);
	long long int len = ftell(file);

	char* buff = (char*)malloc(sizeof(char) * (sets->count * sets->g + 1));
	memset(buff, 0, (sets->count * sets->g + 1));
	fseek(file, sets->ofset, SEEK_SET);
	if (sets->size == 0)
		sets->size = len;

	int k = 0;
	while (k <= sets->size / (sets->count * sets->g))
	{
		fread_s(buff, sets->count * sets->g, sizeof(char), sets->count * sets->g, file);
		char* tmp = buff;
		printf_s("%x\t", sets->ofset);
		for (int i = 0; i < sets->count, tmp[i] != '\0'; i++)
		{
			char* mass = createRevers(tmp, sizeof(char), sets->g);
			tmp = tmp + sets->g;
			for (int j = 0; j < sets->g; j++)
			{
				printHex(mass[j]);
			}
			printf_s(" ");
			free(mass);
		}
		k++;
		sets->ofset += sets->count * sets->g;
		if (sets->g == 1)
		{
			printf_s("|");
			for (int i = 0; i < sets->count, buff[i] != '\0'; i++)
			{
				if (isprint(buff[i]))
					printf_s("%c", buff[i]);
				else
					printf_s(".");
			}
		}
		printf_s("\n");
		free(buff);
	}
}