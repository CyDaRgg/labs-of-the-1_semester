#define _CRT_SECURE_NO_WARNINGS
// ������� ��������� ����������� ������� ��� ������ �� ��������
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

char* getstr(char*, int Amount);

int main()
{
	setlocale(LC_ALL, "Russian");
	char* s1, *s2;
	int n, n1, n2;
	double d;
	do
	{
		system("CLS");
		fflush(stdin);
		printf("������� ����������� ������ ������ = ");
	} while (!scanf("%d", &n1) || n1 <= 0);


	if (!(s1 = (char*)calloc(n1, sizeof(char))))
	{
		printf("\n������������ ��������� ������ \n");
		return 0;
	}

	printf("������� ������ ������ ");
	char c;
	//while ((c = getchar()) != EOF && c != '\n');
	printf("\ %s ", getstr(s1, n1)); //����-����� ������ ������
}

// ���� ������ �� ������ ����������� � ���
char* getstr(char* st, int Amount)
{
	if (!st)
		return NULL; // ������� ��������� �� ������������ ��� ������ ������
	int i = 0;
	char C;
	// � ����� ������� ��������� � ������ �� ������ ����������
	// �� ��� ��� ���� �� ����� ������ ������� ENTER
	// while ((*(st + i++) = (char)getchar()) != '\n');
	while (i <= Amount)
	{
		setlocale(LC_ALL, "RUS");
		char c;
		while ((c = getchar()) != EOF && c != '\n');
		C = getchar();
		if (C == '\n')
			return st;
		*(st + i) = C;
		i++;
	};
	st[--i] = '\0'; // ��������� � ����� ������ ������ '\0'
	return st; // ����� �� �������
}