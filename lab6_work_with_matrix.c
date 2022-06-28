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
				if (n <1)
				{
					printf("������ ������ ����������� �������");
					return 0;
				}

	///////////////// ��������� ������ ��� ������� /////////////////


	if(!(mat = (int*)calloc(n*n,sizeof(int))))
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

//////////////////////////////////////����� ����� �������/////////////////////

	printf("����� ����� �������\n");

	for (int i = 0; i < n; i++)
	{
		if (i == i_max )
		{
			continue;
		}


		for (int j = 0; j < n; j++)
		{
			if (j == j_max)
			{
				continue;
			}

			
			printf("%d\t", *(mat + i * n + j));
		}
		printf("\n");

	}


	free(mat);

	return 0;
}