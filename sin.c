#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <locale.h>
// ������� ����������  SIN(X) � ��������� E ��� ���������� �������� ���������� N
int main()
{
	setlocale(LC_ALL, "Russian");       // ����������� ������ ���������� �� ���
	float x, e, k = 0, st, znak = 1, y1 = 0, y2;
	int n, i = 1;
	double fakt;
	puts("\n�������  x  e  n : ");
	scanf_s("%f%f%d", &x, &e, &n);
	system("CLS");                     // ������� ������
	st = x;                             // ������� �
	do                  // ���� ���������� �������� ������� �� �������� 
	{                   // �������� (e) ��� �� ��������� ����� �������� (n)
		y2 = y1;                       // ���������� �������� ������� Y1
		fakt = 1;
		for (int j = 1; j <= 50; j++) // ���������� ���������� (�����������)
		{
			fakt *= j;
			printf("\n%35.0lf", fakt);
		}
		y1 += znak * (st / fakt);        // ����� �������� ������� Y1
		i++;                           // ����� ����������� �������� 
		st *= x * x;                     // ���������� ������� � (���������)
		znak *= -1;                    // ������ ���� ��� ��������� ��������
	} while (i<n && fabs(y1 - y2)>e);

	printf("\n f(%5.2f) = %10.7f   %d\n", x, y1, i);
	printf("\n  %ld\n", fakt);
	return 0;
}