//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//
//# define PI		3.14159265358979323846
//void main()
//{
//	float x, Eps;
//	int	n;
//	float Sum, Element;
//
//	printf("Enter x = ");
//	scanf_s("%f", &x);
//
//	rewind(stdin);
//
//	printf("And Eps = ");
//	scanf_s("%f", &Eps);
//
//
//	Element = 1;
//	Sum = 1;          // первый член Тейлора
//
//	n = 1;            // степень
//
//	do
//	{
//		(float)Element = (float)(-Element * x * x / ((2 * n)*(2 * n - 1)));
//		n++;
//		Sum = Sum + Element;
//	} while (fabs(Element) > Eps);
//
//
//	printf("cos(x) = %f,     n = %d", Sum, n);
//
//	printf("\ncos(x) = %f,     n = %d", cos(0.5235987));
//
//}



#include<stdio.h>
#include<stdlib.h>
#include<math.h>


# define PI		3.14159265358979323846
void main()
{
	float x, Eps;
	int	n;
	float Sum, Element;

	printf("Enter x = ");
	scanf_s("%f", &x);

	rewind(stdin);

	printf("And Eps = ");
	scanf_s("%f", &Eps);


	Element = 1;
	Sum = 1;          // первый член Тейлора

	n = 1;            // степень

	do
	{
		(float)Element = (float)(-Element * x * x / ((2 * n)*(2 * n - 1)));
		n++;
		Sum = Sum + Element;
	} while (fabs(Element) > Eps);


	printf("cos(x) = %f,     n = %d", Sum, n);

	printf("\ncos(x) = %f,     n = %d", cos(0.5235987));

}
