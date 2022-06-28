#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>



char* getstr(char *st, int n)           // системная функция           char* gets  (char* buffer);  при \n перестает ввод и заменяет его на '\0'      для char mas[5];  
{                                       // системная функция           int puts(const char* string);   выводит строку
	setlocale(LC_ALL, "RUS");
	int i = 0;
	char symbol;

	while (i < n)

	{
		symbol = (char)getchar();
		if (symbol == '\n')
		{
			break;
		}


		*(st + i) = symbol;

		i++;


	}

	st[i] = '\0';

	return st;
}

//================================================================
      //рекурсивная функция//

int check(char* str, int size)
{
	static sum, i; // счетчик и для прохода
	static flg1 = 1, flg2=1, flg3=1;  

	

	char c;
	
	c = *(str + i++);
	

	if (c)
	{
		//проверка на наличие ПЛОХОЙ СКОБКИ всех видов//
		if (c == ']'&& flg1)
		{

			return sum+1;
		}



		if (c == ')'&& flg2)
		{

			return sum + 1;
		}
		


		if (c == '}'&& flg3)
		{

			return sum + 1;
		}
	//================В дело идет счетчик============================
		if (c == '[')
		{
			flg1 = 0;
			sum++;
		}
		
		else
			if (c == ']')
			{

				sum--;
			}




		if (c == '(')
		{
			flg2 = 0;
			sum++;
		}

		else
			if (c == ')')
			{

				sum--;
			}



		if (c == '{')
		{
			flg3 = 0;
			sum++;
		}

		else
			if (c == '}')
			{

				sum--;
			}



		check(str, size);
	}


	else
	{
		return;
	}


	return sum;

}


















int main()
{
	setlocale(LC_ALL, "RUS");
	char* str;
	int size;  //размер строки
	

	     //Вводим размер строки//

	printf("введите размерность строки");
	scanf_s("%d", &size);

	    //выделяем память для строки//
	str = (char*)calloc(size, sizeof(char));

	//Ввод и вывод строки//
	printf("Вводите строку  ");
	rewind(stdin);
	printf("\n строка: %s", getstr(str, size));

	

	if (check(str, size))
	{
		printf("\nСкобки расставлены НЕВЕРНО");
	}
	else
	{
			printf("\nСкобки расставлены ВЕРНО");
		
	}

	free(str);



	return 0;
}