/*� ���������� ������� ������� n����� ���������� �� ������ �������.
�������� ���������� ������� ������� n-1 ����� ������������ �� ��������

������� �����-������ ������ � �������, �� ����������� ������� ����������
������� � ��������� ���������.*/


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
		printf("������ ��� ������� (�������) �� ��������\n");
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
		printf("������ ��� ������� (�������) �� ��������\n");
	}

	printf("����� �������\n");

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


	///////////////// ���� ����������� ������� /////////////////


	do
	{
		system("CLS");
		printf("������� ����������� (�������)������� = ");
		rewind(stdin);
		scanf_s("%d", &n);
		if (n < 1)
		{
			printf("������ ������ ����������� �������");
			return 0;
		}

		///////////////// ��������� ������ ��� ������� /////////////////


		if (!(mat = (int **)malloc(sizeof(int*)*n)))
		{
			printf("\n������������ ��������� ������ \n��������� ����� ����� �������");
		}


		for (int i = 0; i < n; i++)
		{
			if (!(*(mat + i) = (int *)calloc(n, sizeof(int))))
			{
				printf("\n������������ ��������� ������ \n��������� ����� ��-��� �������");
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


	///////////////// ��������� � ������� �������� ������� �� ����� /////////////////

	vvod(mat, n);

	print(mat, n);

	////////////////////// ����� ����������� �� ������� � ������ ������� ����������� ��������//////



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

	//////////////////////////////////////����� ����� �������/////////////////////

	printf("����� ����� �������\n");

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

	/////////////////������������ ������ /////////////////////


	for (int i = 0; i < n; i++)
	{
		free(*(mat + i));
	}

	free(mat);


	return 0;
}