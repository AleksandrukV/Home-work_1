#include"Library.h"

void CaesarEncryption(FILE* f1,FILE * f2)
{
	char c = fgetc(f1);
	int key = 2;
	while (c != EOF)
	{
		if (c != '\n')
		{
			fputc(c + key, f2);
		}
		else
			fputc(c, f2);
		c = fgetc(f1);
	}
}

int main()
{
	FILE* f1 = fopen("D:\\temp\\file.txt", "r");
	FILE* f2 = fopen("D:\\temp\\file2.txt", "w");
	CaesarEncryption(f1, f2);
	fclose(f1);
}