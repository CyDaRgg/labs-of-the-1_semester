#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>



char* getstr(char *st, int n)           // ��������� �������           char* gets  (char* buffer);  ��� \n ��������� ���� � �������� ��� �� '\0'      ��� char mas[5];  
{                                       // ��������� �������           int puts(const char* string);   ������� ������
	setlocale(LC_ALL, "RUS");
	int i = 0;
	char symbol;

	while (i < n)

	{
		symbol = (char)getchar();
		if (symbol == '\n')
		{
			break;
		}


		*(st + i) = symbol;

		i++;


	}

	st[i] = '\0';

	return st;
}

//================================================================
      //����������� �������//

int check(char* str, int size)
{
	static sum, i; // ������� � ��� �������
	static flg1 = 1, flg2=1, flg3=1;  

	

	char c;
	
	c = *(str + i++);
	

	if (c)
	{
		//�������� �� ������� ������ ������ ���� �����//
		if (c == ']'&& flg1)
		{

			return sum+1;
		}



		if (c == ')'&& flg2)
		{

			return sum + 1;
		}
		


		if (c == '}'&& flg3)
		{

			return sum + 1;
		}
	//================� ���� ���� �������============================
		if (c == '[')
		{
			flg1 = 0;
			sum++;
		}
		
		else
			if (c == ']')
			{

				sum--;
			}




		if (c == '(')
		{
			flg2 = 0;
			sum++;
		}

		else
			if (c == ')')
			{

				sum--;
			}



		if (c == '{')
		{
			flg3 = 0;
			sum++;
		}

		else
			if (c == '}')
			{

				sum--;
			}



		check(str, size);
	}


	else
	{
		return;
	}


	return sum;

}


















int main()
{
	setlocale(LC_ALL, "RUS");
	char* str;
	int size;  //������ ������
	

	     //������ ������ ������//

	printf("������� ����������� ������");
	scanf_s("%d", &size);

	    //�������� ������ ��� ������//
	str = (char*)calloc(size, sizeof(char));

	//���� � ����� ������//
	printf("������� ������  ");
	rewind(stdin);
	printf("\n ������: %s", getstr(str, size));

	

	if (check(str, size))
	{
		printf("\n������ ����������� �������");
	}
	else
	{
			printf("\n������ ����������� �����");
		
	}

	free(str);



	return 0;
}