// ���������� (�����, ������) �������� ����� ����������� �������
// �.�. �������� (������������� � ������ � ������������ � �������).
// ����������� �������(�������) �������� � ����������

#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include <windows.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int *ms, n, m, i, i1, i2, j, j1, kk, ind = 0;
	do
	{
		system("CLS");
		printf("������� ����������� (�������)������� = ");
		//fflush(stdin);
		i = scanf_s("%d%d", &n, &m);
	} while (i < 2 || n <= 0 || m <= 0);

	return 0;
}