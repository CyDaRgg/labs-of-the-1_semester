#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


//------------------------------   пример 1  ------------------------------------------
 /*в функции вывод€тс€ параметры (аргументы), получаемые из командной строки
 первый аргумент *argv[0] - строка, содержаща€ путь к исполн€емому файлу
 argc - количество аргументов в командной строке*/ //asdf "abc d efg 12345 qwert"

//int main(int argc, char *argv[])  //   char** st 
//{
//  setlocale(LC_ALL, "Russian");
//	int i;
//	printf("\nargc = %d\n\n",argc);
//	for (i = 0; i<argc; i++)              // for (i = 1; argc; i++)
//		printf("%s\n", argv[i]); //  printf("%s", *(st+i));
//	return 0;
//}


//------------------------------   пример 2  ------------------------------------------
 /*в функции вывод€тс€ параметры (аргументы) - системное окружение , получаемые из командной строки
 последний аргумент env[i]- указатель nullptr*/


//#include <string.h>
//int main(int argc, char *argv[], char *env[])
//{
//  setlocale(LC_ALL, "Russian");
//	for (int i = 0; env[i]; i++)
//	{
//		//if (strstr(env[i], "PATH"))
//			printf("%s\n", env[i]);
//
//	}
//
//	return 0;
//}


//------------------------------   пример 3  ------------------------------------------
// ¬ командной строке вводитс€ несколько строк.
// ¬ рекурсивной функции дл€ каждой строки выполнить
// реверсивный переворот последнего слова
// например:     asdf "abc d efg 12345 qwert"
//
//void fun(char *s)
//{
//	static int j;
//	int i = 0;
//	char c;
//
//
//	if (*(s + i) == ' ')
//	{
//		j = i + 1;
//	}
//
//	if (*(s + i) != '\0')
//	{
//		c = *(s + i);
//		i++;
//		fun(s);
//	}
//	else
//	{
//		return;
//	}
//
//	if (*(s + j) != '\0')
//	{
//		*(s + j++) = c;
//	}
//
//	if (i == 1)
//		j = 0;
//	//printf("\nѕреобразованна€%s", s);
//	
//}
//
//
//
//
//int main(int argc, char *argv[])
//{
//	setlocale(LC_ALL, "RUS");
//
//	for (int i = 1; i < argc; i++)
//	{
//
//		printf("\n%s", argv[i]);
//		fun(argv[i]);
//		printf("\nѕреобразованна€%s", argv[i]);
//	}
//	return 0;
//}




//------------------------------   пример 4  ------------------------------------------

// ¬ командной строке ввод€тс€ группы символов(строки) состо€щие из чисел и знаков
// '+' и '-', например "1+39-5-8+23=?" "44-2-13+99=?" вычислить сумму каждой из них
// группы символов раздел€ютс€ пробелом

// функци€ перевода цифровой символьной строки в signed int
int atoi(char *ss)
{
	int n, i = 0, znak;

	while (ss[i] == ' ')
	{
		i++;
	}

	if (!ss[i])
		return 0;   // в строке одни пробелы

	znak = (ss[i] == '-') ? -1 : 1;
	if (ss[i] == '+' || ss[i] == '-')  // пропуск знака
		i++;

	for (n = 0; ss[i] >= '0' && ss[i] <= '9'; i++)  // выбор цифр числа из строки
		n = 10 * n + (ss[i] - '0');


	return znak*n;    // возврат числа со знаком
}

int main(int argv,char *argc[])
{
  setlocale(LC_ALL, "Russian");

  int n,i,j,sum;

  char *s,c;

  for(i=1;i<argv;i++)                 // считывание очередного слова из ком. стр.
  { 
	  
	  
	sum=n=0; 
	c=' ';
    s=(char *)calloc(1,sizeof(char)); // строка дл€ одного символа



    for(j=0;*(argc[i]+j);j++)         // проход по выбранному слову
    {
		switch(*(argc[i]+j))
      { 
		case '?': break;                                                   //"1+39-5-8+23=?"
	    case '=': 
		case '-':
		case '+': 
		  if (c==' ')
			  sum=atoi(s);    // первична€ сумма
		  if (c=='+') 
			  sum+=atoi(s);   // увеличение результата
		  if (c=='-') 
			  sum-=atoi(s);   // уменьшение результата

		  free(s);

		  n=0;
		  s=(char *)calloc(1,sizeof(char));
		  c=*(argc[i]+j);             // запоминаем знак  +  -
		  break;                      // сброс числа букв дл€ ввода нового слова



	    default : n++;
		  s=(char *)realloc(s,(n+1)*sizeof(char)); // строка увеличи-
							                       // ваетс€ на 1 букву
		  s[n-1]=*(argc[i]+j);	      // введена буква
		  s[n]='\0';
      }

    }
    free(s);
    printf("\n %20s  ответ  %d",argc[i],sum);



  }


  puts("\n");
 // scanf_s("%d",&n);
  return 0;
}













int atoi(char* s)
{
	int znak = 1;
	int i;
	int num = 0;

	for (i = 0; *(s + i) != 0; i++)
	{
		if (*(s + i) == ' ')
			i++;


		if (*(s + i) == '-')
			znak = *(s + i) == '-' ? -1 : 1;


		if (*(s + i) >= '0' && *(s + i) <= '9')
			num = 10 * num + (*(s + i) - '0');


	}

	return znak * num;

}






///////////////////////////4///////zzzzzzzzzzzzzzzz/////////€€€€€€€€€€€€€..............

void cal(char*str)
{
	char*s;
	int sum = 0;
	int num = 0;
	char c = ' ';

	s = (char*)calloc(1, sizeof(char));

	for (int i = 0; *(str + i) != '\0'; i++)
	{



		switch (*(str + i))
		{
		case '?':
			break;

		case '=':
		case '+':
		case '-':

			if (c == ' ')
				sum = atoi(s);

			if (c == '+')
				sum = sum + atoi(s);

			if (c == '-')
				sum = sum - atoi(s);


			free(s);
			num = 0;
			s = (char*)calloc(1, sizeof(char));

			c = *(str + i);


			break;


		default: num++;

			s = (char*)realloc(s, num + 1);

			s[num - 1] = *(str + i);
			s[num] = '\0';


		}

	}

	free(s);
	printf("%d—умма", sum);
	//return sum;


}




int main(int argc, char* argv[])
{
	int res;
	setlocale(LC_ALL, "RUS");

	for (int i = 1; i < argc; i++)
	{
		printf("\n\n%s—трока сначала", argv[i]);

		cal(argv[i]);
		//res = cal(argv[i]);

		//printf("\d%s—умма", res);

	}
	return 0;
}