/*Даны натуральное число n и символы s1, ..., sn среди которых есть
двоеточие.Получить все символы, расположенные между первым и вторым

двоеточием.Если второго двоеточия нет, то получить все символы,
расположенные после единственного имеющегося двоеточия.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <string.h>  // системные функции


char* get_str(char* st, int n)
{
	int i=0;  // проход по строке

	while (i < n)
	{

		*(st + i) = (char)getchar();
		

		if (*(st+i) == '\n')
			break;
		i++;

		
	}

	*(st+i) = '\0';



	return st;
}

//-----------
//char* get_str(char *st, int n)           // системная функция           char* gets  (char* buffer);  при \n перестает ввод и заменяет его на '\0'      для char mas[5];  
//{                                       // системная функция           int puts(const char* string);   выводит строку
//	setlocale(LC_ALL, "RUS");
//	int i = 0;
//	char symbol;
//
//	while (i < n)
//
//	{
//		symbol = (char)getchar();
//		if (symbol == '\n')
//		{
//			break;
//		}
//
//
//		*(st + i) = symbol;
//
//		i++;
//
//
//	}
//
//	st[i] = '\0';
//
//	return st;
//}


//----


int main()
{

	setlocale(LC_ALL, "RUS");

	int n;                  // вводимая с клавиатуры длина символьного массива(строки)
	int length_new_str=0;   // своего рода счетчик

	char *st;
	
	int i=0;  // для пробега по строке

	printf("Введите длину строки: ");

	scanf_s("%d", &n);

	if (n < 1)
	{
		printf("Ошибка вввода длины строки");
		return 0;
	}

	st = (char*)calloc(n, sizeof(char));



	//Заполняем строку с клавиатуры и выводим первоначальную//
	printf("\nВводите исходную строку \t");
	rewind(stdin);
	printf("\nИсходная строка \t %s", get_str(st, n) );

	// Алгоритм по переделыванию строки, в которой будут символы между двоеточиями или символы после первого двоеточия//

	while (st[i] != ':')
	{
		if (st[i] == '\0')
		{
			printf("\nДвоеточие не введено");
			return 0;
		}
		i++;
	}

		i++; // минуем двоеточие

			for (int j = 0; st[i] != ':' && st[i] != '\0'; j++, i++)
			{


				//if (st[i] == '\0')  // если второго двоеточия не будет
				//	break;

				st[j] = st[i];
				length_new_str++;

			}

		


	

	           // realloc и засовываем '\0' //

	st = realloc(st, length_new_str + 1);
	st[length_new_str] = '\0';

	           // вывод новой строки//
	printf("\nНовая строка \t%s", st);



	free(st);

	return 0;
}
