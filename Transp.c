// Транспонировать матрицу относительно главной диагонали
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>

#define n 2
#define m 7
int main()
{
	setlocale(LC_ALL, "RUS");
	int mat[n][m];
	int i,j;
	int change;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = rand() %10;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
		
	}
	///////////////////////////////////////////////////////
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)  // !!! здесь j< n, чтобы за пределы массива не выйти
		{
			change = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = change;

		}

	}

	/////////////////////////////////////////////////////////
	printf("Транспонированная матрица\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");

	}




	return 0;
}