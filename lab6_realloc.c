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

int vvod(int * mat, int n)
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
			if (!scanf_s("%d", mat + i * n + j))
			{
				j--;
			}

		}

	}

	return 0;

}



void print(int * mat, int n)
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
			printf("%d\t", *(mat + i * n + j));
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


	int *mat;
	int n;
	int i_max = 0, j_max = 0;


	///////////////// ���� ����������� ������� /////////////////

	printf("������� ����������� (�������)������� = ");
	rewind(stdin);
	scanf_s("%d", &n);
	if (n < 1)
	{
		printf("������ ������ ����������� �������");
		return 0;
	}

	///////////////// ��������� ������ ��� ������� /////////////////


	if (!(mat = (int*)calloc(n*n, sizeof(int))))
	{
		printf("������ ��� ������� (�������) �� ��������\n");
		return 0;

	}





	///////////////// ��������� � ������� �������� ������� �� ����� /////////////////

	vvod(mat, n);

	print(mat, n);

	////////////////////// ����� ����������� �� ������� � ������ ������� ����������� ��������//////



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{




			if (module(*(mat + i * n + j)) > module(*(mat + i_max * n + j_max)))
			{

				i_max = i;
				j_max = j;

			}

		}


	}

	//////////////////////////////////////������ ����� � �����/////////////////////

	for (int i = 0; i < n ; i++)
	{
		for (int j = j_max; j < n - 1; j++)
		{
			*(mat + i * n + j) = *(mat + i * n + j + 1);
		}
	}


	for (int j = 0; j< n ; j++)
	{
		for (int i = i_max; i < n - 1; i++)
		{
			*(mat + i*n  +j  ) = *(mat + i * n+ n +j );
		}
	}

	////////////////////���������� � realloc//////////////////

	for (int j = 1, q = 2; j < (n - 1), q < n; j++, q++)
	{
		for (int i = (n - 1)*j; i < (n - 1)*q; i++)
		{
			*(mat + i) = *(mat + i + j);
		}

	}


	////////////////////������������ ������/////////

	mat = (int*)realloc(mat,  (n*n-(2*n-1)) * sizeof(int));


	////////////////////����� ������� �������////////////////

	print(mat, n-1 );

	free(mat);


	return 0;
}