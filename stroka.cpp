#define _CRT_SECURE_NO_WARNINGS
// примеры некоторых стандартных функций для работы со строками
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
		printf("введите размерность ПЕРВОЙ строки = ");
	} while (!scanf("%d", &n1) || n1 <= 0);


	if (!(s1 = (char*)calloc(n1, sizeof(char))))
	{
		printf("\nНедостаточно свободной памяти \n");
		return 0;
	}

	printf("Вводите первую строку ");
	char c;
	//while ((c = getchar()) != EOF && c != '\n');
	printf("\ %s ", getstr(s1, n1)); //ввод-вывод первой строки
}

// ввод строки по адресу переданному в нее
char* getstr(char* st, int Amount)
{
	if (!st)
		return NULL; // передан указатель на невыделенную под строку память
	int i = 0;
	char C;
	// в цикле символы заносятся в строку из буфера клавиатуры
	// до тех пор пока не будет нажата клавиша ENTER
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
	st[--i] = '\0'; // добавляем в конец строки символ '\0'
	return st; // выход из функции
}