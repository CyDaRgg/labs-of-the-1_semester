 //�������� �� ������� ��������� � ���������(�������� � ����������) ���������
#include<stdio.h>
#include<conio.h>
#include <locale.h>
#include <windows.h>
#include<stdlib.h>


int Vvod(int n, int *MS,int k)
{
	if (!MS) return 1;                 // �������� �� ������� �� ��������� �� ������ 
	printf("������� �������� � ����� MS ");
	if (n == 1) printf("�� �����������\n");
	else  printf("�� ��������\n");
	int i = 0, j;
	while (i < k)                      // ���� �� ���-�� ��������� �������
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
	if (!MS) return 1;                 // �������� �� ������� �� ��������� �� ������ 
	while (i < k)                      // ���� �� ���-�� ��������� �������
	{
		printf("MS[ %d ] = ", i);
		fflush(stdin); //rewind(stdin);// ������ �������� ������
		if (scanf_s("%d", MS + i)) i++;  // �������� ������� �� �����
	}
	return 0;
}

void Print(int MS[], int k)      //  ����� MS[] � *MS  - ������������  
{
	if (!MS) return;                  // �������� �� ������� �� ��������� �� ������
	printf("�����  : ");
	for (int i = 0; i < k; i++)       // ���� ������������� ������ ������� �� ����� 
		printf("%4d\t", MS[i]);
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int *ms, n1, i, j, k1, k2;
	printf("������� ����������� ������� n1= ");
	scanf_s("%d", &n1);
	if (!n1) return 0;
	if (!(ms = (int *)malloc(n1 * sizeof(int)))) { return 0; }

	Vvod(ms, n1);
	system("CLS");
	Print(ms, n1);
	printf("������� ������� ��������� ");
	scanf_s("%d%d", &k1, &k2);

	for (i = k2 + 1; i < n1; i++)
	{
		*(ms + k1++) = *(ms + i);
	}

	ms = ((int*)realloc(ms, sizeof(int)*(k2 - k1 + 1)));


	Print(ms, n1-(k2-k1+2));                   // ����� ������� �� �����
	free(ms); 












	//if (k1 > k2)  // ��������� ������ - k1 <-> k2 (k1 ������ ���� ������ k2)
	//{
	//	i = k1; k1 = k2; k2 = i;
	//}

	//while (k2 < n1) 
	//	*(ms + k1++) = *(ms + k2++); // ���� ������ � ������� - �������� ��������� �� ���������� ���������
	//n1 -= k2 - k1;                   // ��������� �������� ������� �������
	//ms = (int *)realloc(ms, sizeof(int)*n1);  // ��������� (��������) ������ �������
	//	if (!ms) return 0;           // ����� ��� ������ � �������������� ������  
	//Print(ms, n1);                   // ����� ������� �� �����
	//free(ms);                        // ������������ ������
	return 0;
}