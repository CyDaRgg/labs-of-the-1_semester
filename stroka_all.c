////  ������� ��������� ����������� ������� ��� ������ �� ��������
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include <string.h>  // ��������� �������

//#include <iostream>










//////////// ������� ����� ������ ��������� ������/////////////

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

		
		  *(st + i) = symbol  ;
		
		  i++;
          
		
	}
	
	st[i] = '\0';

	return st;
}

//////////// ������� ����� ������ �� ����������� � ������� ������/////////////////////

int getleng(char *st)       
{
	int length = 0;

	//for (; st[length]!='\0' ; length++);
      for (; *(st+length) != '\0'; length++);

	return length;
}




// ������� �������� ���������� ������ �  int
int char_numb (char *st)
{
	int number=0;    // ���� �����
	int i = 0;     // ��� �������
	int znak=0;      

	for (i; st[i] != '\0'; i++)
	{
		while (st[i] == ' ')
		{
			i++;
		}
		if ((st[i] == '+') &znak == 0)    // ���������� ����
			znak = 1;
	
		if ((st[i] == '-') &znak == 0)    // ���������� ����
			znak = -1;
//--------------------------------------------------------------
		while (!(st[i] >= '0'&& st[i] <= '9'))   // ���� �� �����, �� �������
		{
			if (st[i] == '\0')
				return 0;
			i++;

		}

		if (st[i] == '\0')
			return 0;              // � ������ ���� ������� � ������ �� ������
		number = 10 * number + (st[i] - '0');
	}


	return znak * number;                     // ������� ����� �� ������
}

 
void numb_char(int number, char*st)
{
	int i = 0;
	char znak;
	char change;

	
	if (number < 0) 
	{
		znak = '-';       // we identified the sign of number
		number = number * -1; // ��� ��� % �������� ��������� ��� ������������� �����
	}
	else
		znak = '+';

	for (i; st[i]!='\0'|| number != 0; i++)
	{
	
		st[i] = ((number % 10 )+ '0');
		number = number / 10;
	}
	st[i] = '-';
	st[++i] = '\0';

	printf("\n%s", st);  // �� �������, ����� �������� �������� ������ � ������

	//for (int i2 = 0; i2 < i / 2; i2++)
	//{
	//	st[i2] = st[i2] + st[i - 1 - i2];
	//	st[i - 1 - i2] = st[i2] - st[i - 1 - i2];
	//	st[i2] = st[i2] - st[i - 1 - i2];

	//}

	// ��� ��������� �� ������ �������

	for (int i2 = 0,  i3=i-1; i2<i3; i2++,i3--)    
	{
		change = st[i2];
		st[i2] = st[i3];
		st[i3] = change;
	}


}



//float double_char_numb(char * st)
//{
//	float number=0;  //���� �����
//	float after_point=0.0; // ��� �������� �������� ����� �������
//	int i, znak=0;
//
//
//
//	for (i = 0; ((st[i] >= '0'& st[i] <= '9' )&st[i]!='\0')||st[i]=='+'||st[i]=='-'|| st[i]=='.'; i++)
//	{
//
//		//znak = (st[i] == '+' & znak==0) ? 1 : -1;   //� ���������� znak  ��������� ������ ���������� ����, ��������� �������
//
//		if (st[i] == '+' & znak == 0)
//		{
//			znak = 1;
//			
//		}
//
//		if (st[i] == '-' & znak == 0)
//		{
//			znak = -1;
//			
//		}
//		
//		if (st[i] != '0' || st[i] != '-'|| st[i]!='+')        // ������ �������� ����� � �����!!!
//		{
//
//		
//
//			if (st[i] != '.')
//				number = 10 * number + (st[i] - '0');
//
//			else
//				after_point = 1;   // ���������� �����, �� ����������� ������ � ������������ ���������� ������ ����� ������� 
//
//			if(after_point)
//			after_point *= 10;  
//		
//		}
//		//printf("%f", number);
//
//		
//
//
//
//	}
//
//
//	return znak * number / (after_point/10);
//}


double double_char_numb(char *ss)
{
	double n, ii = 0;
	int i = 0, znak;
	while (ss[i] == ' ') i++;
	if (!ss[i]) return 0.;             // � ������ ���� �������
	znak = (ss[i] == '-') ? -1 : 1;
	if (ss[i] == '+' || ss[i] == '-')  // ������� �����
		i++;
	for (n = 0; (ss[i] > '0' && ss[i] <= '9') || ss[i] == '.'; i++)
	{
		if (ss[i] != '.')
			n = 10 * n + (ss[i] - '0');     // ����� ��������� ����� ����� �� ������
		else 
			ii = 1;                      // ������� ���������� �����

		if (ii) ii *= 10;   // ����� ���� ����� ���������� �����
	}
	ii /= 10;               //
	return znak * n / ii;     // ������� ����� �� ������
}


// ������� ��������� ���� �����  �� ���������
int str_cmp(char *st1, char *st2)
{
	while (*st1)     // ������ ���� �� ��������� ����� ('\0') ������ s1
	{
		if (*st1 - *st2)
			return *st1 - *st2;  // >0 ���� ASCII-���  *s1 > *s2
											  // ����� <0
		else                                  // ��� ���������� �������� �������
		{
			st1++;                            // � ������� ��������� ���� ��������
			st2++;
		}

	}
	return *st1 - *st2;  // ������ ���� ��������� ������� ���� ���� ����������
}





// ������� ������� (����������) � ������ st1 ������ st2                  // ������ ������
// � ������� k
char * strcat(char *st1, char *st2, int k)
{
	//char *ss;
	int i, n;
	if (k > getleng(st1))
		k = getleng(st1); // �������� ���� ��������� ������ st2
										  // ������������� ������ ��� ����� ������ st1
	st1 = (char*)realloc(st1, getleng(st1) + getleng(st2) + 1);
	for (i = getleng(st1); i >= k; i--)   // ����� � ������ st1 ������ ����� (�� ������� k) 
		*(st1 + i + getleng(st2)) = *(st1 + i); // ������
	for (i = 0; i <getleng(st2); i++)      // ���������� ������ ������ st2 � ������ st1
		*(st1 + k + i) = *(st2 + i);      // � ������� k
	return st1;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

//using namespace std;

	int main()
	{

		setlocale(LC_ALL, "RUS");

		char *s1, *s2, *s3,*s4;
		int n1, n2, n3, n4;
		int numb;



		char *we = "hello Egor!";  // ������ ����� ��, � ���  �++ ��������  ( ��������� ��������� ����������� � ����������� ������, ������� � ���������� � ������)
		//char we[]="hello Egor!";  // ���������� ������ ,, ��������� ���������� ������ ��� ��� ���� �������, �������������� ������� \0 (������� �����������)
		char q;    // ������

		q = 'w';
		printf("%s%c\n", we, q);  // pay attention to %s and %c

		char gg[] = "hello";
		printf("%s\n", gg);

		//char mas[20] = "";    // ������ �++ ��������� ������ �� 20 ��������� � ��� ����������� \0 
		//cin >> mas;
		//cout << mas<<endl;





		//��������� gets � puts//
		char mas[5];
		gets(mas); // ��� ������ ���������� NULL 
		//printf("%s", mas);
		puts(mas);

		
		







		printf("������� ����������� ������ ������");
		scanf_s("%d", &n1);



		s1 = (char*)calloc(n1, sizeof(char));

		printf("������� ������ ������  ");
		rewind(stdin);
		printf("\n ������: %s", getstr(s1, n1));

		////-------------------------------------------------------------


		//printf("\n ����� ���� ������ %d\n", getleng(s1));
		////-----------------------------------------------------------



		//printf("������� ����������� ������ ��� char_numb\n");
		//scanf_s("%d", &n2);

		//s2 = (char*)calloc(n2, sizeof(char));

		//printf("������� ������ ��� char_numb\n  ");
		//rewind(stdin);
		//printf("\n ������: %s\n", getstr(s2, n2));

		//printf("��������������� �����:%d ", char_numb(s2));

		////------------------------------------------------------------------
		printf("\n������� ����������� ������ ��� numb_char ");

		scanf_s("%d", &n3);



		s3 = (char*)calloc(n3, sizeof(char));
		printf("������� ����� int  ��� char_numb\n  ");
		scanf_s("%d", &numb);
		numb_char(numb, s3);
		printf("\n������������ ����� int � ������ %s", s3);
		//-------------------------------------------------------


		printf("������� ����������� ������ ���  double_char_numb\n");
     	scanf_s("%d", &n4);

		s4 = (char*)calloc(n4, sizeof(char));

		printf("������� ������ ���  double_char_numb\n  ");
		rewind(stdin);
		printf("\n ������: %s\n", getstr(s4, n4));
		printf("��������������� �����  double_char_numb:%f ", double_char_numb(s4));

		//----------------------------




		str_cmp(s1,s3);

		free(s1);
//		free(s2);
		free(s3);
		free(s4);

	

	return 0;
}


