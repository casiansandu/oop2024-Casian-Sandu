#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	FILE* fisier;
	fisier = fopen("fisier.in.txt", "r");
	char rez[50][50];
	char s[50], c = 'a';
	int i = 0, k = 1;
	fscanf(fisier, "%s", s);
	

	while (strcmp(s, rez[k - 1]))
	{
		strcpy(rez[k], s);
		k++;
		fscanf(fisier, "%s", s);
	}


	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (strlen(rez[i]) < strlen(rez[j]))
			{
				strcpy(s, rez[i]);
				strcpy(rez[i], rez[j]);
				strcpy(rez[j], s);
			}
			else if (strlen(rez[i]) < strlen(rez[j]))
			{

			}
		}
	}

	for (int i = 0; i < k; i++)
		cout << rez[i] << '\n';

	return 0;
}