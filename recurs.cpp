// ���� ��������� ������� ��������� �������� � �������������� 
// ����������� �������
// (� ����������� �������� ����� �� ������������ !!!!)

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string.h>

//********************************************************** ����������� ������� ����� ���������� � ������ 

int Vvod(int *mas, int n) // int ��� ��������
{
	static int i;
///////////////////////��������///////////////////////////////
	if (!mas)
	{
		printf("������ ��� ������� �� ��������");
		return 1;
	}

	if (i >= n) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ����������� �� ���������� � ����
	{
		printf("������ ������  ���������");
		return 1;
	}
////////////////////////����//////////////////////////////////////////

	
		printf("mas[%d]=", i);

		rewind(stdin);
		if (scanf_s("%d", mas + i))
		{
			i++;
		}

		Vvod(mas, n);
		i--;
	
		return 0;


}

//// *************************************����������� ������� ������ �� ����� ���������� �� �������

void print(int *mas, int n)
{
	static int i;

///////////////////��������/////////////////
	if (!mas)
	{
		printf("������ ��� ������� �� ��������");
	}

	if (i >= n)
	{
		printf("������ ������ ���������");
		return 1;
	}
////////////////////////////////////////////
	printf("%4d", *(mas + i));
	i++;

	print(mas, n);

	i--;

	if (!i)
	{
		printf("\n");
	}
	return 0;


	// *******************************����������� ���������� ����� ������������� ����-��� ���������



	int fibon(int n)
{
		return (n == 0 || n == 1) ? 1 : fibon(n - 2) + fibon(n - 1);
}

	int main()
	{


		for (int n = 0; n < 15; n++)
		{
			printf("%d", fibon(n));
		}
		printf("\n");
		return 0;
	

}

	// ����������� ������� ���������� ����-��  (������� 1 )

	int fact1(int n)
	{
		if (n == 0 || n == 1)
		{
			return 1;
		}

		return fact1(n - 1)*n;

	}

	// ����������� ������� ���������� ����-��  (������� 2 )

	int fact2(int n)
	{
		static int i;
		int fact;

		if (n == 0 || n == 1)
		{
			return 1;
		}

		if (++i < n)
		{
			fact= i * fact2(n);
			i--;
			return fact;
		}
		i--;

		return n;


	}

	// ����������� ������� ���������� ����-��  (������� 3 )

	int fact3(int n)
	{

		return n ? fact3(n - 1)*n : 1;

	}

	// ����������� ��������� ������ �� ����� 1

	void revers1(char *st,int dl)
	{
		static int i,j;

		char c;

		c = *(st + i);
		if(c)
		{
			//c = *(st + i);
			
			revers1(st, dl);

			*(st + j++) = c;
			return;
		
		}

		return;

	}
	//void revers1(char *st, int dl)
//{
//static int i;
//	char c;
//	c = *(st + i++);        // ��������� � ����� ��������� ��������� ������
//	if (c)
//		revers1(st, dl); // ����������� ����� ��� ���������� ������ ����.
//	else return;    // ���� �� ������ ����� ������, ����� ����� �� ��������
//	*(st + dl - (--i)) = c; // �������� ������ �� �������� ����� ���������
//}    

	// ����������� ��������� ������ �� ����� 2

	void recurs2(char *st,int dl)
	{

		static int i;

		char c;
		c = *(st + i);
		*(st + i) = *(st + dl - 1 - i);
		*(st + dl - 1 - i++) = c;

		if (i < dl / 2)
		{
			recurs2(st, dl);
		}

		return;

	}












	//����������� ������� ���������� ������� �����
	void hoor(int *, int, int);
	void swap(int *, int, int);
	void FOR(int *, int, int, int, int &);

	// ����������� ������� ����� ���������� � ������ 
	int Vvod(int *MS, int k)
	{
		static int i = 0;
		int j;
		if (!MS) return 1;                 // �������� �� ������� �� ��������� �� ������ 
		if (i >= k) return 0;              // ������ ������ ���������
										   // �������� ��������
		printf("MS[ %d ] = ", i);
		fflush(stdin); //rewind(stdin);    // ������ �������� ������
		if (scanf("%d", MS + i)) i++;      // �������� ������� �� �����
		Vvod(MS, k);                        // �������� ��� ����� ���������� ��������
		i--;
		return 0;
	}

	// ����������� ������� ������ �� ����� ���������� �� �������
	void Print(int MS[], int k)       //  ����� MS[] � *MS  - ������������  
	{
		static int i;
		if (!MS) return;              // �������� �� ������� �� ��������� �� ������
		if (i >= k) return;
		printf("%4d", *(MS + i++));   // ����������� ������������ ����� ������� �� ����� 
		Print(MS, k);
		i--;
		if (!i) printf("\n");
		//i = 0;
		return;
	}


	int main()
	{
		setlocale(LC_ALL, "Russian");
		int *ms, i, n;
		do
		{
			rewind(stdin);
			puts("\n������� ���-�� �����");
			i = scanf_s("%d", &n);
		} while (i < 1 || n <= 0);
		ms = (int*)malloc(n * sizeof(int));
		puts("\n������� �������� ������� ");
		Vvod(ms, n);
		system("CLS");
		printf("\n�������� ������        :");
		Print(ms, n);
		hoor(ms, 0, n - 1);
		printf("\n\n��������������� ������ :");
		Print(ms, n);
	}

	// ����������� ������� ���������� ������� �����
	void hoor(int *a, int l, int r)
	{
		int i, las;
		if (l >= r) 
			return;
		swap(a, l, (l + r) / 2);  // ������� ��-� ����������� � a[l] (a[l]<->a[(l+r)/2])
		las = l;                  // ������� ����-�� ��-�� �������� ��� �������
		//for (i = l + 1; i <= r; i++) //������� [l,r] �� [l,las-1] � [las+1,r]
		//if (a[i]<a[l])         // ���� ������ !!!!!!!!!!!!!!!!!!!!
		//	swap(a, ++las, i);
		FOR(a, l, r, l + 1, las);   // ������ ����� for ����������� �������� FOR
		swap(a, l, las);
		hoor(a, l, las - 1);      // ���������� ��� [l,las-1]
		hoor(a, las + 1, r);      // ���������� ��� [las+1,r]
	}

	// ������� ( �� �����������) ������ i � j ��-��� � ������� a
	void swap(int *a, int i, int j)
	{
		int tmp;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	// ����������� ������� ���������� ������������ ���� for
	void FOR(int *a, int l, int r, int i, int &las)
	{
		if (i > r)
		{
			return;
		}
		if (a[i] < a[l])
		{
			swap(a, ++las, i);
		}
		FOR(a, l, r, ++i, las);
	}

	//----------------------------------------------------------------------


	//  ���������������������������������//////////////

	int nod(int a, int b)
	{
		int c;
/////////////////////////////////////
		if (b >a)
		{
			c=nod(b, a);
		}
////////////////////////////////////
		else
			if (b== 0)
			{
				c =a;
			}
			else
			{
				nod(b, a%b);
			}
		return c;
	}


	//*************************** ����������� ������� �������� ����� �� ���������� �/� � ����� (2 ... 16)


	void fc(int num1, int ss, char znak);         // �������� ����������� �-��� �������� ����� ����� �����
	void fd(double num, int ss, int t);   // �������� ����������� �-��� �������� ������� ����� �����

	//int ss;                             // ��������� ����� �/�
	//char znak = '+';
	int main()
	{
		int ss;                             // ��������� ����� �/�
		char znak = '+';


		setlocale(LC_ALL, "Russian");
		int t;                       // �������� ������� �����
		double num;                  // �������� ����� (���������� �����)
		printf("\n������� �������� ����� : ");
		scanf_s("%lf", &num);

		num < 0 ? znak = '-', num *= -1 : num;  // ��������� ����� �����
		printf("\n������� ��������� ����� �/�");
		scanf_s("%d", &ss);
		printf("\n������� �������� ��� ������� ����� ����� �/�");
		scanf("%d", &t);
		printf("\n����� � �/� (%d) = ", ss);
		fc((int)num, ss, znak);                 // �������� � ������� ����� ����� �����
		//putchar('.');
		printf(".");
		fd(num - (int)num, ss, t);           // �������� � ������� ������� ����� �����          
		//puts("\n");
		return 0;
	}

	void fc(int num1, int ss, char znak)    // ����������� ������� �������� (������ �� �����) � ����� �/�
	{                    // ����� ����� ��������� ����������� ����� 
		int i;
		if (num1 >= ss)
		{
			i = num1 % ss;      // �������� ������� �� ������� �� ���������
			num1 /= ss;       // �������� ����� ����� �� �������
			fc(num1, ss, znak);       // ����������� ����� ������� fc
			printf("%c", i > 9 ? i - 10 + 'a' : i + '0');
		}
		else printf("%c %c", znak, num1 > 9 ? num1 - 10 + 'A' : num1 + '0');
	}

	void fd(double num, int ss, int t)   // ����������� ������� �������� (������ �� �����) � 
	{                            // ����� �/� ������� ����� ��������� ����������� ����� 
		static short int n;
		int i;
		if (num != 0 && n++ < t)
		{
			i = num *= ss;             // �������� ������������ � �������� ����� �����k
			printf("%c", i > 9 ? i - 10 + 'a' : i + '0');
			fd(num - (int)num, ss, t);    // ����������� ����� fd
		}
		// else printf("%c",num>9?(int)num-10+'A':(int)num+'0');
	}

	//********************����������� ���� ������ � ������� �� �����

	int get_str(char* st, int n)
	{
		static int i;
		static int dl = 0;
		if (i < n)
		{
			*(st + i) = getchar();

			if (*(st + i) == '\n' || *(st + i) == EOF)
			{
				*(st + i) = '\0';
			}
			else
			{
				i++;
				get_str(st, n);
				i--;

				return ++dl;
			}

		}
		else
		{
			*(st + i) = '\0';

			return 0;
		}

	}
	int main()
	{
		char *st;

		st = (char*)calloc(5, sizeof(char));

		printf("%d\n", get_str(st, 4));
		printf("%s\n", st);
	}

	//*********************************** ������� �������� ������ ��������� ��������

	void del(char* st)
{
	static int i;
	static int j = 1;
	static int flag;

	
	///////////////////////////////
	if (*(st + i) == *(st + j) || flag    )
	{
		flag = 1;
		if (*(st + i + 1) != '\0')
		{

			*(st + i) = *(st +i+1);
			i++;
			printf("\n%s", st);
			del(st);
			return;
			
		}
		else
		{
			*(st + i) = *(st + i + 1);
			i = 0;
			j = i+1;
			flag = 0;
			printf("\n%s", st);
			del(st);
			return;
		}
	}

	/////////////////////////////////////////////
	if (*(st + j) != '\0')
	{
		j++;
		del(st);
		return;
	}

	else
	{
		//======================
		i++;
		j = i + 1;

		if (*(st+i) == '\0')
		{
			return;
		}
		
		del(st);
		
	}

}


	////////////////////////////////////////////// �������� ���� ��������� ��������

	int IF(char* st, int &i, int &flag2)
	{
		if (*(st + i + 1) != '\0' && flag2)
		{
			*(st + i) = *(st + i + 1);
			printf("\n%s", st);
			i++;
			IF(st, i, flag2);
			i--;
			return i;
		}
		else
		{
			if (*(st + i + 1) == '\0' && flag2)
			{
				*(st + i) = *(st + i + 1);
				printf("\n%s", st);
				//i = -1;
				flag2 = 0;
				i--;
				return i;
			}
		}
		return i;
	}
	///////////////////////////////////////////////////////////


	int get_str(char* st, int n)
	{
		static int i;
		static int dl = 0;


		if (i < n)
		{
			rewind(stdin);
			*(st + i) = getchar();

			if (*(st + i) == '\n' || *(st + i) == EOF)
			{
				*(st + i) = '\0';
			}
			else
			{
				i++;
				get_str(st, n);
				i--;

				return ++dl;
			}

		}
		else
		{
			*(st + i) = '\0';

			return 0;
		}

	}



	int del(char* st)
	{
		static int i;
		static int j = 1;
		static int flag, flag2;


		///////////////////////////////
		if (*(st + i) == *(st + j) || flag)
		{
			flag = 1;
			flag2 = 1;
			if (*(st + j + 1) != '\0')
			{

				*(st + j) = *(st + j + 1);
				j++;
				printf("\n%s", st);
				del(st);
				return i;

			}
			else
			{
				*(st + j) = *(st + j + 1);

				j = i + 1;
				flag = 0;
				printf("\n%s", st);
				del(st);
				return i;
			}
		}
		/////////////////////////////////////////////////////////
		if (*(st + j) != '\0')
		{
			j++;
			del(st);
			return i;
		}

		else
		{
			////////////////////////////////////////////////////
			i=IF(st, i, flag2); ///////////////////////////////////////////
			

			//////////////////////////////////////////////////


			i++;
			j = i + 1;

			if (*(st + i) == '\0')
			{
				return i;
			}

			del(st);

		}
	}


	int main()
	{
		setlocale(LC_ALL, "Russian");
		int dl;
		char *st;

		rewind(stdin);
		printf("\n������� ������ ���������� ������ :");
		scanf_s("%d", &dl);
		printf("\n������� ���������� ������ :");
		st = (char *)calloc(dl + 1, sizeof(char));
		 get_str(st, dl);    // nn - ����� ������� ��������� �������� � ������ (nn < kk)

//		strcpy(st, "qazsa");

		printf("\n������ �� ��������    :  %s", st);

		dl=del(st);

		st = (char*)realloc(st, dl + 1);

		printf("\n������ ����� �������� :  %s\n", st);


		free(st);

	}