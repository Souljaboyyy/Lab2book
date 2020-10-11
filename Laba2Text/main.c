#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void FileSort(char* name)
{
	FILE* read;
	char str[256];
	fopen_s(&read, name, "r");
	int countStrings = 0;

	while (!feof(read))
	{
		fgets(&str, 256, read);
		countStrings++;
	}
	char** text = (char**)malloc(countStrings * sizeof(char*));
	fseek(read, 0, SEEK_SET);
	for (int i = 0; i < countStrings; ++i)
	{
		//printf("%s",fgets(&str, 256, read));

		int size = strlen(fgets(&str, 256, read));
		text[i] = (char*)malloc(sizeof(char) * (size + 1));
		strcpy_s(text[i], size + 1, str);
		text[i][strlen(text[i]) - 1] = 0;
		printf("%s\n", text[i]);
	}
	printf("\n");
	char** line = (char**)malloc(countStrings * sizeof(char*));
	fseek(read, 0, SEEK_SET);
	for (int i = 0; i < countStrings; i++)
	{
		for (int j = 0; j < countStrings - 1; j++)
		{
			if (strlen(text[j]) > strlen(text[j + 1]))
			{
				char* zamena = text[j];
				text[j] = text[j + 1];
				text[j + 1] = zamena;
			}
		}
	}
	for (int i = 0; i < countStrings; i++)
		printf("%s\n", text[i]);
	printf("\n");
	fclose(read);
}

int main() {
	setlocale(LC_ALL, "Rus");
	printf("Choose 1,2 or 3\n");
	char choise = _getch();
	switch (choise)
	{
	case '1':
	{
		/*FILE* read;
		char str[256];
		fopen_s(&read, "book.txt", "r");
		int countStrings = 0;

		while (!feof(read))
		{
			fgets(&str, 256, read);
			countStrings++;
		}
		char** text = (char**)malloc(countStrings * sizeof(char*));
		fseek(read, 0, SEEK_SET);
		for (int i = 0; i < countStrings; ++i)
		{
			//printf("%s",fgets(&str, 256, read));

			int size = strlen(fgets(&str, 256, read));
			text[i] = (char*)malloc(sizeof(char) * (size + 1));
			strcpy_s(text[i], size + 1, str);
			text[i][strlen(text[i]) - 1] = 0;
			printf("%s\n", text[i]);
		}
		printf("\n%d\n", countStrings);
		char** line = (char**)malloc(countStrings * sizeof(char*));
		fseek(read, 0, SEEK_SET);
		for (int i = 0; i < countStrings; i++)
		{
			for (int j = 0; j < countStrings - 1; j++)
			{
				if (strlen(text[j]) > strlen(text[j + 1]))
				{
					char* zamena = text[j];
					text[j] = text[j + 1];
					text[j + 1] = zamena;
				}
			}
		}
		for (int i = 0; i < countStrings; i++)
			printf("%s\n", text[i]);
		printf("\n");
		fclose(read);*/
		FileSort("book.txt");
		break;
	}
	case '2':
	{
		printf("Write file name : ");
		char file[256];
		gets(&file, 256);
		FileSort(file);
		break;
	}
	case '3':
	{
		printf("Write file name with other files : ");
		char file[256];
		gets(&file, 256);
		FILE* read;
		fopen_s(&read, file, "r");
		int countFiles = 0;
		while (!feof(read))
		{
			fgets(&file, 256, read);
			countFiles++;
		}
		char** files = (char**)malloc(countFiles * sizeof(char*));
		fseek(read, 0, SEEK_SET);
		for (int i = 0; i < countFiles; ++i)
		{
			int size = strlen(fgets(&file, 256, read));
			files[i] = (char*)malloc(sizeof(char) * (size + 1));
			strcpy_s(files[i], size + 1, file);
			if (files[i][strlen(files[i]) - 1] == '\n')
				files[i][strlen(files[i]) - 1] = 0;
			printf("%d : %s\n", i+1, files[i]);
		}
		printf("Which file do you prefer?\n");
		int d = 0;
		scanf_s("%d", &d);
		FileSort(files[d-1]);
		break;
	}
	}
	system("pause");
	return 0;
}