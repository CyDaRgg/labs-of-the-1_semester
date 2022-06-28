// Ниже приведены примеры некоторых программ с использованием 
// рекурсивных функций
// (в рекурсивных функциях циклы не используются !!!!)

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string.h>

//********************************************************** рекурсивная функция ввода информации в массив 

int Vvod(int *mas, int n) // int для проверок
{
	static int i;
///////////////////////проверки///////////////////////////////
	if (!mas)
	{
		printf("память для массива не выделена");
		return 1;
	}

	if (i >= n) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ограничение на погружение в стек
	{
		printf("Массив введен  полностью");
		return 1;
	}
////////////////////////ввод//////////////////////////////////////////

	
		printf("mas[%d]=", i);

		rewind(stdin);
		if (scanf_s("%d", mas + i))
		{
			i++;
		}

		Vvod(mas, n);
		i--;
	
		return 0;


}

//// *************************************рекурсивная функция вывода на экран информации из массива

void print(int *mas, int n)
{
	static int i;

///////////////////проверки/////////////////
	if (!mas)
	{
		printf("память для массива не выделена");
	}

	if (i >= n)
	{
		printf("массив введен полностью");
		return 1;
	}
////////////////////////////////////////////
	printf("%4d", *(mas + i));
	i++;

	print(mas, n);

	i--;

	if (!i)
	{
		printf("\n");
	}
	return 0;


	// *******************************Рекурсивное вычисление чисел принадлежащих посл-сти Фибоначчи



	int fibon(int n)
{
		return (n == 0 || n == 1) ? 1 : fibon(n - 2) + fibon(n - 1);
}

	int main()
	{


		for (int n = 0; n < 15; n++)
		{
			printf("%d", fibon(n));
		}
		printf("\n");
		return 0;
	

}

	// рекурсивная функция вычисления факт-ла  (вариант 1 )

	int fact1(int n)
	{
		if (n == 0 || n == 1)
		{
			return 1;
		}

		return fact1(n - 1)*n;

	}

	// рекурсивная функция вычисления факт-ла  (вариант 2 )

	int fact2(int n)
	{
		static int i;
		int fact;

		if (n == 0 || n == 1)
		{
			return 1;
		}

		if (++i < n)
		{
			fact= i * fact2(n);
			i--;
			return fact;
		}
		i--;

		return n;


	}

	// рекурсивная функция вычисления факт-ла  (вариант 3 )

	int fact3(int n)
	{

		return n ? fact3(n - 1)*n : 1;

	}

	// Рекурсивный переворот строки на месте 1

	void revers1(char *st,int dl)
	{
		static int i,j;

		char c;

		c = *(st + i);
		if(c)
		{
			//c = *(st + i);
			
			revers1(st, dl);

			*(st + j++) = c;
			return;
		
		}

		return;

	}
	//void revers1(char *st, int dl)
//{
//static int i;
//	char c;
//	c = *(st + i++);        // сохраняем в стеке очередной считанный символ
//	if (c)
//		revers1(st, dl); // рекурсивный вызов для считывания нового симв.
//	else return;    // пока не считан конец строки, иначе выход из рекурсии
//	*(st + dl - (--i)) = c; // обратный проход по функциям после окончания
//}    

	// Рекурсивный переворот строки на месте 2

	void recurs2(char *st,int dl)
	{

		static int i;

		char c;
		c = *(st + i);
		*(st + i) = *(st + dl - 1 - i);
		*(st + dl - 1 - i++) = c;

		if (i < dl / 2)
		{
			recurs2(st, dl);
		}

		return;

	}












	//Рекурсивная функция сортировки методом Хоара
	void hoor(int *, int, int);
	void swap(int *, int, int);
	void FOR(int *, int, int, int, int &);

	// рекурсивная функция ввода информации в массив 
	int Vvod(int *MS, int k)
	{
		static int i = 0;
		int j;
		if (!MS) return 1;                 // проверка не нулевой ли указатель на массив 
		if (i >= k) return 0;              // массив введен полностью
										   // рекурсия окончена
		printf("MS[ %d ] = ", i);
		fflush(stdin); //rewind(stdin);    // чистка входного буфера
		if (scanf("%d", MS + i)) i++;      // проверка введено ли число
		Vvod(MS, k);                        // рекурсия для ввода очередного элемента
		i--;
		return 0;
	}

	// рекурсивная функция вывода на экран информации из массива
	void Print(int MS[], int k)       //  здесь MS[] и *MS  - эквивалентны  
	{
		static int i;
		if (!MS) return;              // проверка не нулевой ли указатель на массив
		if (i >= k) return;
		printf("%4d", *(MS + i++));   // рекурсивный поэлементный вывод массива на экран 
		Print(MS, k);
		i--;
		if (!i) printf("\n");
		//i = 0;
		return;
	}


	int main()
	{
		setlocale(LC_ALL, "Russian");
		int *ms, i, n;
		do
		{
			rewind(stdin);
			puts("\nВводите кол-во чисел");
			i = scanf_s("%d", &n);
		} while (i < 1 || n <= 0);
		ms = (int*)malloc(n * sizeof(int));
		puts("\nВводите элементы массива ");
		Vvod(ms, n);
		system("CLS");
		printf("\nИсходный массив        :");
		Print(ms, n);
		hoor(ms, 0, n - 1);
		printf("\n\nПреобразованный массив :");
		Print(ms, n);
	}

	// рекурсивная функция сортировки методом Хоара
	void hoor(int *a, int l, int r)
	{
		int i, las;
		if (l >= r) 
			return;
		swap(a, l, (l + r) / 2);  // делящий эл-т переносится в a[l] (a[l]<->a[(l+r)/2])
		las = l;                  // позиция посл-го эл-та большего чем делящий
		//for (i = l + 1; i <= r; i++) //деление [l,r] на [l,las-1] и [las+1,r]
		//if (a[i]<a[l])         // ЦИКЛ УБРАТЬ !!!!!!!!!!!!!!!!!!!!
		//	swap(a, ++las, i);
		FOR(a, l, r, l + 1, las);   // замена цикла for рекурсивной функцией FOR
		swap(a, l, las);
		hoor(a, l, las - 1);      // сортировка для [l,las-1]
		hoor(a, las + 1, r);      // сортировка для [las+1,r]
	}

	// функция ( не рекурсивная) замены i и j эл-тов в массиве a
	void swap(int *a, int i, int j)
	{
		int tmp;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	// рекурсивная функция заменяющая традиционный цикл for
	void FOR(int *a, int l, int r, int i, int &las)
	{
		if (i > r)
		{
			return;
		}
		if (a[i] < a[l])
		{
			swap(a, ++las, i);
		}
		FOR(a, l, r, ++i, las);
	}

	//----------------------------------------------------------------------


	//  НОООООООООООООООООООООООООООООООО//////////////

	int nod(int a, int b)
	{
		int c;
/////////////////////////////////////
		if (b >a)
		{
			c=nod(b, a);
		}
////////////////////////////////////
		else
			if (b== 0)
			{
				c =a;
			}
			else
			{
				nod(b, a%b);
			}
		return c;
	}


	//*************************** рекурсивные функции перевода числа из десятичной с/с в новую (2 ... 16)


	void fc(int num1, int ss, char znak);         // прототип рекурсивной ф-ции перевода целой части числа
	void fd(double num, int ss, int t);   // прототип рекурсивной ф-ции перевода дробной части числа

	//int ss;                             // основание новой с/с
	//char znak = '+';
	int main()
	{
		int ss;                             // основание новой с/с
		char znak = '+';


		setlocale(LC_ALL, "Russian");
		int t;                       // точность дробной части
		double num;                  // исходное число (правильная дробь)
		printf("\nВведите исходное число : ");
		scanf_s("%lf", &num);

		num < 0 ? znak = '-', num *= -1 : num;  // выделение знака числа
		printf("\nВведите основание новой с/с");
		scanf_s("%d", &ss);
		printf("\nВведите точность для дробной части числа с/с");
		scanf("%d", &t);
		printf("\nЧисло в с/с (%d) = ", ss);
		fc((int)num, ss, znak);                 // передача в функцию целой части числа
		//putchar('.');
		printf(".");
		fd(num - (int)num, ss, t);           // передача в функцию дробной части числа          
		//puts("\n");
		return 0;
	}

	void fc(int num1, int ss, char znak)    // рекурсивная функция перевода (вывода на экран) в новую с/с
	{                    // целой части исходного десятичного числа 
		int i;
		if (num1 >= ss)
		{
			i = num1 % ss;      // получаем остаток от деления на основание
			num1 /= ss;       // получаем целую часть от деления
			fc(num1, ss, znak);       // рекурсивный вызов функции fc
			printf("%c", i > 9 ? i - 10 + 'a' : i + '0');
		}
		else printf("%c %c", znak, num1 > 9 ? num1 - 10 + 'A' : num1 + '0');
	}

	void fd(double num, int ss, int t)   // рекурсивная функция перевода (вывода на экран) в 
	{                            // новую с/с дробной части исходного десятичного числа 
		static short int n;
		int i;
		if (num != 0 && n++ < t)
		{
			i = num *= ss;             // получаем произведение и выделяем целую частьk
			printf("%c", i > 9 ? i - 10 + 'a' : i + '0');
			fd(num - (int)num, ss, t);    // рекурсивный вызов fd
		}
		// else printf("%c",num>9?(int)num-10+'A':(int)num+'0');
	}

	//********************рекурсивный ввод строки и подсчет ее длины

	int get_str(char* st, int n)
	{
		static int i;
		static int dl = 0;
		if (i < n)
		{
			*(st + i) = getchar();

			if (*(st + i) == '\n' || *(st + i) == EOF)
			{
				*(st + i) = '\0';
			}
			else
			{
				i++;
				get_str(st, n);
				i--;

				return ++dl;
			}

		}
		else
		{
			*(st + i) = '\0';

			return 0;
		}

	}
	int main()
	{
		char *st;

		st = (char*)calloc(5, sizeof(char));

		printf("%d\n", get_str(st, 4));
		printf("%s\n", st);
	}

	//*********************************** функция удаления ЛИШНИХ совпавших символов

	void del(char* st)
{
	static int i;
	static int j = 1;
	static int flag;

	
	///////////////////////////////
	if (*(st + i) == *(st + j) || flag    )
	{
		flag = 1;
		if (*(st + i + 1) != '\0')
		{

			*(st + i) = *(st +i+1);
			i++;
			printf("\n%s", st);
			del(st);
			return;
			
		}
		else
		{
			*(st + i) = *(st + i + 1);
			i = 0;
			j = i+1;
			flag = 0;
			printf("\n%s", st);
			del(st);
			return;
		}
	}

	/////////////////////////////////////////////
	if (*(st + j) != '\0')
	{
		j++;
		del(st);
		return;
	}

	else
	{
		//======================
		i++;
		j = i + 1;

		if (*(st+i) == '\0')
		{
			return;
		}
		
		del(st);
		
	}

}


	////////////////////////////////////////////// Удаление ВСЕХ совпавших символов

	int IF(char* st, int &i, int &flag2)
	{
		if (*(st + i + 1) != '\0' && flag2)
		{
			*(st + i) = *(st + i + 1);
			printf("\n%s", st);
			i++;
			IF(st, i, flag2);
			i--;
			return i;
		}
		else
		{
			if (*(st + i + 1) == '\0' && flag2)
			{
				*(st + i) = *(st + i + 1);
				printf("\n%s", st);
				//i = -1;
				flag2 = 0;
				i--;
				return i;
			}
		}
		return i;
	}
	///////////////////////////////////////////////////////////


	int get_str(char* st, int n)
	{
		static int i;
		static int dl = 0;


		if (i < n)
		{
			rewind(stdin);
			*(st + i) = getchar();

			if (*(st + i) == '\n' || *(st + i) == EOF)
			{
				*(st + i) = '\0';
			}
			else
			{
				i++;
				get_str(st, n);
				i--;

				return ++dl;
			}

		}
		else
		{
			*(st + i) = '\0';

			return 0;
		}

	}



	int del(char* st)
	{
		static int i;
		static int j = 1;
		static int flag, flag2;


		///////////////////////////////
		if (*(st + i) == *(st + j) || flag)
		{
			flag = 1;
			flag2 = 1;
			if (*(st + j + 1) != '\0')
			{

				*(st + j) = *(st + j + 1);
				j++;
				printf("\n%s", st);
				del(st);
				return i;

			}
			else
			{
				*(st + j) = *(st + j + 1);

				j = i + 1;
				flag = 0;
				printf("\n%s", st);
				del(st);
				return i;
			}
		}
		/////////////////////////////////////////////////////////
		if (*(st + j) != '\0')
		{
			j++;
			del(st);
			return i;
		}

		else
		{
			////////////////////////////////////////////////////
			i=IF(st, i, flag2); ///////////////////////////////////////////
			

			//////////////////////////////////////////////////


			i++;
			j = i + 1;

			if (*(st + i) == '\0')
			{
				return i;
			}

			del(st);

		}
	}


	int main()
	{
		setlocale(LC_ALL, "Russian");
		int dl;
		char *st;

		rewind(stdin);
		printf("\nВводите размер символьной строки :");
		scanf_s("%d", &dl);
		printf("\nВводите символьную строку :");
		st = (char *)calloc(dl + 1, sizeof(char));
		 get_str(st, dl);    // nn - число реально введенных символов в строку (nn < kk)

//		strcpy(st, "qazsa");

		printf("\nСтрока до удаления    :  %s", st);

		dl=del(st);

		st = (char*)realloc(st, dl + 1);

		printf("\nСтрока после удаления :  %s\n", st);


		free(st);

	}