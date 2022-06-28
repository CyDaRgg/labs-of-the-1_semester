 //удаление из массива элементов в выбранном(заданном с клавиатуры) интервале
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include <windows.h>
#include<stdlib.h>


int Vvod(int n, int *MS,int k)
{
	if (!MS) return 1;                 // проверка не нулевой ли указатель на массив 
	printf("введите значения в масив MS ");
	if (n == 1) printf("по возрастанию\n");
	else  printf("по убыванию\n");
	int i = 0, j;
	while (i < k)                      // цикл по кол-ву элементов массива
	{
		printf("MS[ %d ] = ", i);
		j=scanf_s("%d", MS+i);
		if (j && (i == 0 || 
			      (n == 1 && *(MS+i) >= *(MS+i-1)) ||
				  (n == 2 && *(MS+i) <= *(MS+i-1)) ) ) i++;
	}
  return 0;
}

int Vvod(int *MS, int k)
{
	int i = 0;
	int j;
	if (!MS) return 1;                 // проверка не нулевой ли указатель на массив 
	while (i < k)                      // цикл по кол-ву элементов массива
	{
		printf("MS[ %d ] = ", i);
		fflush(stdin); //rewind(stdin);// чистка входного буфера
		if (scanf_s("%d", MS + i)) i++;  // проверка введено ли число
	}
	return 0;
}

void Print(int MS[], int k)      //  здесь MS[] и *MS  - эквивалентны  
{
	if (!MS) return;                  // проверка не нулевой ли указатель на массив
	printf("масив  : ");
	for (int i = 0; i < k; i++)       // цикл поэлементного вывода массива на экран 
		printf("%4d\t", MS[i]);
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int *ms, n1, i, j, k1, k2;
	printf("введите размерность массива n1= ");
	scanf_s("%d", &n1);
	if (!n1) return 0;
	if (!(ms = (int *)malloc(n1 * sizeof(int)))) { return 0; }

	Vvod(ms, n1);
	system("CLS");
	Print(ms, n1);
	printf("введите границы интервала ");
	scanf_s("%d%d", &k1, &k2);

	for (i = k2 + 1; i < n1; i++)
	{
		*(ms + k1++) = *(ms + i);
	}

	ms = ((int*)realloc(ms, sizeof(int)*(k2 - k1 + 1)));


	Print(ms, n1-(k2-k1+2));                   // вывод массива на экран
	free(ms); 












	//if (k1 > k2)  // изменение границ - k1 <-> k2 (k1 должно быть меньше k2)
	//{
	//	i = k1; k1 = k2; k2 = i;
	//}

	//while (k2 < n1) 
	//	*(ms + k1++) = *(ms + k2++); // цикл сдвига в массиве - удаление элементов из выбранного интервала
	//n1 -= k2 - k1;                   // изменение величины размера массива
	//ms = (int *)realloc(ms, sizeof(int)*n1);  // изменение (усечение) самого массива
	//	if (!ms) return 0;           // выход при ошибке с перевыделением памяти  
	//Print(ms, n1);                   // вывод массива на экран
	//free(ms);                        // освобождение памяти
	return 0;
}