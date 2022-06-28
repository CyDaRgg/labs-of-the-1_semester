/*В квадратной матрице порядка nнайти наибольший по модулю элемент.
Получить квадратную матрицу порядка n-1 путем выбрасывания из исходной

матрицы какой-нибудь строки и столбца, на пересечении которых расположен
элемент с найденным значением.*/


#include <windows.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>

int vvod(int ** mat, int n)
{

	if (!mat)
	{
		printf("память для массива (матрицы) не выделена\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			printf("MS[ %d ][ %d ] = ", i, j);
			rewind(stdin);
			if (!scanf_s("%d", &mat[i][j]))
			{
				j--;
			}

		}

	}

	return 0;

}



void print(int ** mat, int n)
{

	if (!mat)
	{
		printf("память для массива (матрицы) не выделена\n");
	}

	printf("Вывод матрицы\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}

		printf("\n");
	}

}


int module(int number)
{

	if (number <= 0)
	{
		return -1 * number;

	}
	else
	{
		return number;
	}


}

int main()
{
	setlocale(LC_ALL, "RUS");


	int **mat = NULL;
	int n;
	int i_max = 0, j_max = 0;


	///////////////// ввод размерности матрицы /////////////////


	do
	{
		system("CLS");
		printf("введите размерность (массива)матрицы = ");
		rewind(stdin);
		scanf_s("%d", &n);
		if (n < 1)
		{
			printf("Ошибка вввода размерности матрицы");
			return 0;
		}

		///////////////// выделение памяти для матрицы /////////////////


		if (!(mat = (int **)malloc(sizeof(int*)*n)))
		{
			printf("\nНедостаточно свободной памяти \nуменьшите число строк матрицы");
		}


		for (int i = 0; i < n; i++)
		{
			if (!(*(mat + i) = (int *)calloc(n, sizeof(int))))
			{
				printf("\nНедостаточно свободной памяти \nуменьшите число ст-цов матрицы");
				for (int i = 0; i < n; i++)
				{
					free(*(mat + i));
				}
				free(mat);
				mat = NULL;
				break;
			}
		}

	} while (!mat);


	///////////////// заполняем и выводим исходную матрицу на экран /////////////////

	vvod(mat, n);

	print(mat, n);

	////////////////////// будем проходиться по матрице и искать индексы наибольшего элемента//////



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{




			if (module(mat[i][j]) > module(  mat[i_max][j_max]  ) )
			{

				i_max = i;
				j_max = j;

			}

		}


	}

	//////////////////////////////////////вывод новой матрицы/////////////////////

	printf("Вывод новой матрицы\n");

	for (int i = 0; i < n; i++)
	{
		if (i == i_max)
		{
			continue;
		}


		for (int j = 0; j < n; j++)
		{
			if (j == j_max)
			{
				continue;
			}


			printf("%d\t", mat[i][j]);
		}
		printf("\n");

	}

	/////////////////освобождение памяти /////////////////////


	for (int i = 0; i < n; i++)
	{
		free(*(mat + i));
	}

	free(mat);


	return 0;
}