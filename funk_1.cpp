// � ������ ������� ��������������� 3 �������� ������� �������� ����������
// (����������) � ������� : �� ��������, �� ���������, �� ������
#include <stdio.h>                          // �� ������ �������� ���� � �++ !!!!!!!!!!!!!!!!!!!!!!!!!!
#include <locale.h>
#include <windows.h>

// ����� ������������� �������,��� �� ����� �������� ������ ����� ��������� , � �� ����� ���������� ������� ������  

void fun1(int aa, int bb);          // �������� ������� � "����������� �� ��������"
void fun2(int a, int b);          // ���������� ������� fun1
void fun3(int *a, int *b);      // �������� ������� � "����������� �� ���������"
void fun4(int &aa, int &bb);      // �������� ������� � "����������� �� ������"
void fun5(int *(*p));
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b,c=7;

	int *pa, *pb;
	pa = (int *)malloc(10 * sizeof(int)); /* pa ��� ������������ ������
										     ��������( 10*sizeof(int) )  ���������� ���� ������, ������� ���������� ��������,
											 ���������� (int *) ��������� �� ���������� ���� � ������.
										  */
	pb = &c;


	//double d;
	scanf_s("%d%d", &a, &b);
	system("CLS");
	printf("\n ���. �������� ����������        a = %d   b=%d", a, b);
	fun1(a, b);                                // ����������� ��������� (a,b)         // �� main() ��� ������ fun1 �������� ���������� � ��������� ����, ��� ������� fun1()  a � b �� ���������� ����� ���������� ������ � ���������� aa � bb       
	                                           // ��� �� ��������� ��� ������� main()
	printf("\n�-��� � ����������� �� ��������  a = %d   b=%d", a, b);
	fun2(a, b);       //
	printf("\n�-��� � ����������� �� ��������  a = %d   b=%d", a, b);
	fun3(&a, &b);
	printf("\n�-��� � ����������� �� ��������� a = %d   b=%d", a, b);
	fun4(a, b);
	printf("\n�-��� � ����������� �� ������    a = %d   b=%d", a, b);

	             fun5(&pb);

	return 0;
}

void fun1(int aa, int bb)                     // ���������� ��������� aa, bb
{                                             // ��� �� ��������� ��� ������� fun1()
	aa--;   // � ���� ������� ���������� �������� ���������  
	bb++;   // ���������� aa � bb �� ���������� � main 
	printf("\n��������� � �-���    fun1       aa = %d   bb=%d", aa, bb);
}

void fun2(int a, int b)                                               
{
	a--;   // � ���� ������� ���������� �������� ���������  
	b++;   // ���������� aa � bb �� ���������� � main 
	printf("\n��������� � �-���    fun2        a = %d   b=%d", a, b);
}

void fun3(int *a, int *b)
{
	(*a)++;      // � ���� ������� ����������� ��������� �������� ���������� �������������  
	(*b) += *a;  // �� ������� ������� �������� � �������. ��-�� ���������� �������� "�����" � main
	printf("\n��������� � �-���    fun3  *(a) = %d  *(b)=%d", *a, *b);
}
void fun4(int &aa, int &bb)
{                // � ���� ������ �������������� aa � bb �������� ���������� ���� ���������� 
	aa++;        // a � b ������������ � main (�.�. ������ ������� ���� ����������)
	bb--;        // ��� ��������� aa � bb ���������� �� �������� ���������� a � b � main
	printf("\n��������� � �-���    fun4     aa = %d   bb=%d", aa, bb);
}




void fun5(int *(*p))
{
	  
	(*(*p)) += 2;  // �� ������� ������� �������� � �������. ��-�� ���������� �������� "�����" � main
	printf("\n��������� � �-���    fun5  **p = %d  *p=%d", **p,*p);
}