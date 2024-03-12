#include"Library.h"

void InitArr(int arr[])
{
	for (int i = 0; i < 5; i++)		//arr[0] - Кількість символів.
	{								//arr[1] - Кількість рядків.
		arr[i] = 0;					//arr[2] - Кількість голосних.
	}								//arr[3] - Кількість приголосних.
}									//arr[4] - Кількість цифр.

void Counter(FILE* f1, int arr[])
{
	char c = fgetc(f1);
	while (c != EOF)
	{
		if (c == '\n')
		{
			arr[1]++;
			c = fgetc(f1);
		}
		if (c>='A' && c <= 'Z' || c>='a' && c<='z')
		{
			if (c == 'a' || c == 'o' || c == 'y' || c == 'i' || c == 'u' || c == 'e'
				|| c == 'A' || c == 'O' || c == 'Y' || c == 'I' || c == 'U' || c == 'E')
			{
				arr[2]++;
			}
			else
			{
				arr[3]++;
			}
		}
		if (c >= '0' && c <= '9')
		{
			arr[4]++;
		}
		arr[0]++;
		c = fgetc(f1);
	}
	arr[1]++;
}

int main()
{
	FILE* f1, * f2;

	f1 = fopen("D:\\temp\\file.txt", "r");
	f2 = fopen("D:\\temp\\file2.txt", "w");

	if (f1 == NULL || f2 == NULL)
	{
		return -1;
	}
	int arr[5];
	InitArr(arr);
	Counter(f1, arr);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	fprintf(f2, "%i", arr[0]);
	fprintf(f2, "%c", '\n');
	fprintf(f2, "%i", arr[1]);
	fprintf(f2, "%c", '\n');
	fprintf(f2, "%i", arr[2]);
	fprintf(f2, "%c", '\n');
	fprintf(f2, "%i", arr[3]);
	fprintf(f2, "%c", '\n');
	fprintf(f2, "%i", arr[4]);
	fprintf(f2, "%c", '\n');

	fclose(f1);
	fclose(f2);
}