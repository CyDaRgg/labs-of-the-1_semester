/*���� ����������� ����� n � ������� s1, ..., sn ����� ������� ����
���������.�������� ��� �������, ������������� ����� ������ � ������

����������.���� ������� ��������� ���, �� �������� ��� �������,
������������� ����� ������������� ���������� ���������.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <string.h>  // ��������� �������


char* get_str(char* st, int n)
{
	int i=0;  // ������ �� ������

	while (i < n)
	{

		*(st + i) = (char)getchar();
		

		if (*(st+i) == '\n')
			break;
		i++;

		
	}

	*(st+i) = '\0';



	return st;
}

//-----------
//char* get_str(char *st, int n)           // ��������� �������           char* gets  (char* buffer);  ��� \n ��������� ���� � �������� ��� �� '\0'      ��� char mas[5];  
//{                                       // ��������� �������           int puts(const char* string);   ������� ������
//	setlocale(LC_ALL, "RUS");
//	int i = 0;
//	char symbol;
//
//	while (i < n)
//
//	{
//		symbol = (char)getchar();
//		if (symbol == '\n')
//		{
//			break;
//		}
//
//
//		*(st + i) = symbol;
//
//		i++;
//
//
//	}
//
//	st[i] = '\0';
//
//	return st;
//}


//----


int main()
{

	setlocale(LC_ALL, "RUS");

	int n;                  // �������� � ���������� ����� ����������� �������(������)
	int length_new_str=0;   // ������ ���� �������

	char *st;
	
	int i=0;  // ��� ������� �� ������

	printf("������� ����� ������: ");

	scanf_s("%d", &n);

	if (n < 1)
	{
		printf("������ ������ ����� ������");
		return 0;
	}

	st = (char*)calloc(n, sizeof(char));



	//��������� ������ � ���������� � ������� ��������������//
	printf("\n������� �������� ������ \t");
	rewind(stdin);
	printf("\n�������� ������ \t %s", get_str(st, n) );

	// �������� �� ������������� ������, � ������� ����� ������� ����� ����������� ��� ������� ����� ������� ���������//

	while (st[i] != ':')
	{
		if (st[i] == '\0')
		{
			printf("\n��������� �� �������");
			return 0;
		}
		i++;
	}

		i++; // ������ ���������

			for (int j = 0; st[i] != ':' && st[i] != '\0'; j++, i++)
			{


				//if (st[i] == '\0')  // ���� ������� ��������� �� �����
				//	break;

				st[j] = st[i];
				length_new_str++;

			}

		


	

	           // realloc � ���������� '\0' //

	st = realloc(st, length_new_str + 1);
	st[length_new_str] = '\0';

	           // ����� ����� ������//
	printf("\n����� ������ \t%s", st);



	free(st);

	return 0;
}
