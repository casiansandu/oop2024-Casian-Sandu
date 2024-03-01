#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	FILE* fisier;
	fisier = fopen("fisier.in.txt", "r");
	char c = fgetc(fisier);
	int suma = 0;
	char nr_actual[30];
	int p, i;

	if (fisier != NULL)
	{
		while (1)
		{
			i = 0;
			while (c != '\n' && c != EOF)
			{
				nr_actual[i] = c;
				i++;
				c = fgetc(fisier);
			}

			p = 1;
			for (int k = i - 1; k >= 0; k--)
			{
				suma += (nr_actual[k] - '0') * p;
				p *= 10;
			}
			c = fgetc(fisier);
			if (c == EOF) break;
		}
		std::cout << suma;

		fclose(fisier);
	}

	return 0;
}