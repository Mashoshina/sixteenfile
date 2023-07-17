// Шаблон для задания 2.2


#include "func.h"



int main(int argc, char* argv[]) {

	Sets sets = { {NULL}, {0}, {0}, {1}, {16} };
	char c;
	while ((c = getopt(argc, argv, "i:o::l::g::n::")) != -1) {
		switch (c) {
		case 'i':
			if (optarg != NULL)
				sets.fname = optarg;
			else
			{
				printf_s("\nEnter the file name");
				system("pause");
				return 0;
			}
			break;
		case 'o':
			if (optarg != NULL)
			{
				if (check(optarg) != 0)
					sets.ofset = atoi(optarg);
				else
				{
					printf_s("\nNot a number");
					system("pause");
					return 0;
				}
			}
			else
				sets.ofset = 0;
			break;

		case 'l':
			if (optarg != NULL)
			{
				if (check(optarg) != 0)
					sets.size = atoi(optarg);
				else
				{
					printf_s("\nNot a number");
					system("pause");
					return 0;
				}
			}
			else
				sets.size = 0;
			break;

		case 'g':
			if (optarg == "byte")
				sets.g = 1;
			else if (optarg == "word")
				sets.g = 2;
			else if (optarg == "dword")
				sets.g = 4;
			else if (optarg == NULL)
				sets.g = 1;
			else
			{
				printf_s("\nInvalid argument");
				system("pause");
				return 0;
			}
			break;

		case 'n':
			if (optarg != NULL)
			{
				if (check(optarg) != 0)
					sets.count = atoi(optarg);
				else
				{
					printf_s("\nNot a number");
					system("pause");
					return 0;
				}
			}
			else
				sets.count = 16;
			break;
		default:
			printf_s("Invalid operstion");
			system("pause");
			return 0;
			break;
		}
	}

	FILE* file;
	int err = fopen_s(&file, sets.fname, "r");

	if (err)
	{
		printf_s("Could not open the file");
		system("pause");
		return 0;
	}

	printFile(file, &sets);
}
