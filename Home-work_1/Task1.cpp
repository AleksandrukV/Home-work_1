#include"Library.h"

char* CreateStr(int size)
{
	char* str = new char[size];
	return str;
}

void Delete(char* str)
{
	delete[] str;
}

char* F(char* str, int size)
{
	char* newstr = CreateStr(size);
	for (int i = 0; i < size - 1; i++)
	{
		newstr[i] = str[i];
	}
	Delete(str);
	return newstr;
}

char* FileStr(char* str, FILE* f)
{
	char c = fgetc(f);
	int count = 0;
	int size = 1;

	while (c != EOF)
	{
		if (c != '\n')
		{
			str = F(str, size++);
			str[count] = c;
		}
		else
		{
			str = F(str, size++);
			str[count] = '\0';
			return str;
		}
		count++;
		c = fgetc(f);
	}
	str = F(str, size++);
	str[count] = '\0';
	return str;
}

int main()
{
	FILE* f1, * f2;
	f1 = fopen("D:\\temp\\file.txt", "r");
	f2 = fopen("D:\\temp\\file2.txt", "r");

	if (f1 == NULL || f2 == NULL)
	{
		return -1;
	}

	int count = 0;
	int size = 1;
	char* str = CreateStr(size);
	char* str2 = CreateStr(size);
	while (str[0] != '\0' || str2[0] != '\0')
	{
		str = FileStr(str, f1);
		str2 = FileStr(str2, f2);
		if (strcmp(str, str2) != 0)
		{
			if (str[0] != '\0' && str2[0] != '\0')
				cout << str << "\t" << str2 << endl;
			else if (str[0] == '\0')
				cout << " \t" << str2 << endl;
			else if (str2[0] == '\0')
				cout << str << endl;
		}
	}
	Delete(str);
	Delete(str2);
	fclose(f1);
	fclose(f2);
}