////  примеры некоторых стандартных функций для работы со строками
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <string.h>  // системные функции

//#include <iostream>










//////////// функция ввода строки указанной длинны/////////////

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

		
		  *(st + i) = symbol  ;
		
		  i++;
          
		
	}
	
	st[i] = '\0';

	return st;
}

//////////// подсчет длины строки по переданному в функцию адресу/////////////////////

int getleng(char *st)       
{
	int length = 0;

	//for (; st[length]!='\0' ; length++);
      for (; *(st+length) != '\0'; length++);

	return length;
}




// перевод цифровой символьной строки в  int
int char_numb (char *st)
{
	int number=0;    // само число
	int i = 0;     // для прохода
	int znak=0;      

	for (i; st[i] != '\0'; i++)
	{
		while (st[i] == ' ')
		{
			i++;
		}
		if ((st[i] == '+') &znak == 0)    // определяем знак
			znak = 1;
	
		if ((st[i] == '-') &znak == 0)    // определяем знак
			znak = -1;
//--------------------------------------------------------------
		while (!(st[i] >= '0'&& st[i] <= '9'))   // если не число, то пропуск
		{
			if (st[i] == '\0')
				return 0;
			i++;

		}

		if (st[i] == '\0')
			return 0;              // в строке одни пробелы и уходим от мусора
		number = 10 * number + (st[i] - '0');
	}


	return znak * number;                     // возврат числа со знаком
}

 
void numb_char(int number, char*st)
{
	int i = 0;
	char znak;
	char change;

	
	if (number < 0) 
	{
		znak = '-';       // we identified the sign of number
		number = number * -1; // ТАК КАК % РАБОТАЕТ НОРМАЛЬНО ДЛЯ ПОЛОЖИТЕЛЬНЫХ ЧИСЕЛ
	}
	else
		znak = '+';

	for (i; st[i]!='\0'|| number != 0; i++)
	{
	
		st[i] = ((number % 10 )+ '0');
		number = number / 10;
	}
	st[i] = '-';
	st[++i] = '\0';

	printf("\n%s", st);  // по приколу, чтобы показать исходные данные в строке

	//for (int i2 = 0; i2 < i / 2; i2++)
	//{
	//	st[i2] = st[i2] + st[i - 1 - i2];
	//	st[i - 1 - i2] = st[i2] - st[i - 1 - i2];
	//	st[i2] = st[i2] - st[i - 1 - i2];

	//}

	// два алгоритма по замене местами

	for (int i2 = 0,  i3=i-1; i2<i3; i2++,i3--)    
	{
		change = st[i2];
		st[i2] = st[i3];
		st[i3] = change;
	}


}



//float double_char_numb(char * st)
//{
//	float number=0;  //Само число
//	float after_point=0.0; // для подсчета символов после запятой
//	int i, znak=0;
//
//
//
//	for (i = 0; ((st[i] >= '0'& st[i] <= '9' )&st[i]!='\0')||st[i]=='+'||st[i]=='-'|| st[i]=='.'; i++)
//	{
//
//		//znak = (st[i] == '+' & znak==0) ? 1 : -1;   //в переменную znak  заносится первый попавшийся знак, остальные игнорим
//
//		if (st[i] == '+' & znak == 0)
//		{
//			znak = 1;
//			
//		}
//
//		if (st[i] == '-' & znak == 0)
//		{
//			znak = -1;
//			
//		}
//		
//		if (st[i] != '0' || st[i] != '-'|| st[i]!='+')        // дальше проходят числа и ТОЧКА!!!
//		{
//
//		
//
//			if (st[i] != '.')
//				number = 10 * number + (st[i] - '0');
//
//			else
//				after_point = 1;   // достигнута точка, то открывается доступ к формированию количества знаков после запятой 
//
//			if(after_point)
//			after_point *= 10;  
//		
//		}
//		//printf("%f", number);
//
//		
//
//
//
//	}
//
//
//	return znak * number / (after_point/10);
//}


double double_char_numb(char *ss)
{
	double n, ii = 0;
	int i = 0, znak;
	while (ss[i] == ' ') i++;
	if (!ss[i]) return 0.;             // в строке одни пробелы
	znak = (ss[i] == '-') ? -1 : 1;
	if (ss[i] == '+' || ss[i] == '-')  // пропуск знака
		i++;
	for (n = 0; (ss[i] > '0' && ss[i] <= '9') || ss[i] == '.'; i++)
	{
		if (ss[i] != '.')
			n = 10 * n + (ss[i] - '0');     // выбор очередной цифры числа из строки
		else 
			ii = 1;                      // выбрана десятичная точка

		if (ii) ii *= 10;   // число цифр после десятичной точки
	}
	ii /= 10;               //
	return znak * n / ii;     // возврат числа со знаком
}


// функция сравнения двух строк  ПО АСКИКОДАМ
int str_cmp(char *st1, char *st2)
{
	while (*st1)     // истина пока не достигнут конец ('\0') строки s1
	{
		if (*st1 - *st2)
			return *st1 - *st2;  // >0 если ASCII-код  *s1 > *s2
											  // иначе <0
		else                                  // при совпадении символов переход
		{
			st1++;                            // к анализу следующей пары символов
			st2++;
		}

	}
	return *st1 - *st2;  // строки либо полностью совпали либо одна окончилась
}





// функция вставки (добавления) в строку st1 строки st2                  // ПЛОХОЙ СПОСОБ
// с позиции k
char * strcat(char *st1, char *st2, int k)
{
	//char *ss;
	int i, n;
	if (k > getleng(st1))
		k = getleng(st1); // проверка куда вставлять строку st2
										  // перевыделение памяти для новой строки st1
	st1 = (char*)realloc(st1, getleng(st1) + getleng(st2) + 1);
	for (i = getleng(st1); i >= k; i--)   // сдвиг в строке st1 второй части (до позиции k) 
		*(st1 + i + getleng(st2)) = *(st1 + i); // вправо
	for (i = 0; i <getleng(st2); i++)      // перезапись второй строки st2 в строку st1
		*(st1 + k + i) = *(st2 + i);      // с позиции k
	return st1;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

//using namespace std;

	int main()
	{

		setlocale(LC_ALL, "RUS");

		char *s1, *s2, *s3,*s4;
		int n1, n2, n3, n4;
		int numb;



		char *we = "hello Egor!";  // прикол языка си, а вот  с++ ругается  ( строковые константы размещаются в статической памяти, поэтому и запихиваем в массив)
		//char we[]="hello Egor!";  // символьная строка ,, создается СИМВОЛЬНАЯ СТРОКА так как есть кавычки, предполагается наличие \0 (неявное присутствие)
		char q;    // символ

		q = 'w';
		printf("%s%c\n", we, q);  // pay attention to %s and %c

		char gg[] = "hello";
		printf("%s\n", gg);

		//char mas[20] = "";    // прикол с++ создается массив из 20 элементов и все заполняются \0 
		//cin >> mas;
		//cout << mas<<endl;





		//системная gets и puts//
		char mas[5];
		gets(mas); // при ошибке возвращает NULL 
		//printf("%s", mas);
		puts(mas);

		
		







		printf("введите размерность первой строки");
		scanf_s("%d", &n1);



		s1 = (char*)calloc(n1, sizeof(char));

		printf("Вводите первую строку  ");
		rewind(stdin);
		printf("\n строка: %s", getstr(s1, n1));

		////-------------------------------------------------------------


		//printf("\n длина этой строки %d\n", getleng(s1));
		////-----------------------------------------------------------



		//printf("введите размерность строки для char_numb\n");
		//scanf_s("%d", &n2);

		//s2 = (char*)calloc(n2, sizeof(char));

		//printf("введите строку для char_numb\n  ");
		//rewind(stdin);
		//printf("\n строка: %s\n", getstr(s2, n2));

		//printf("преобразованное число:%d ", char_numb(s2));

		////------------------------------------------------------------------
		printf("\nВведите размерность строки для numb_char ");

		scanf_s("%d", &n3);



		s3 = (char*)calloc(n3, sizeof(char));
		printf("введите число int  для char_numb\n  ");
		scanf_s("%d", &numb);
		numb_char(numb, s3);
		printf("\nпеределанное число int в строку %s", s3);
		//-------------------------------------------------------


		printf("введите размерность строки для  double_char_numb\n");
     	scanf_s("%d", &n4);

		s4 = (char*)calloc(n4, sizeof(char));

		printf("введите строку для  double_char_numb\n  ");
		rewind(stdin);
		printf("\n строка: %s\n", getstr(s4, n4));
		printf("преобразованное число  double_char_numb:%f ", double_char_numb(s4));

		//----------------------------




		str_cmp(s1,s3);

		free(s1);
//		free(s2);
		free(s3);
		free(s4);

	

	return 0;
}


