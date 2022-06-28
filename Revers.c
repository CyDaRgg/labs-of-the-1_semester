// Реверс (переворот) информации в массиве во введенном интервале [i1 , i2]
// i1, i2 - границы интервала (вводятся с клавиатуры)
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>

#define VALUE 5
int main()
{
	setlocale(LC_ALL, "RUS");
	int mas[VALUE];
	int i1;
	int	i2;
	int change;
	int proof;
	int proof_i1;
	int proof_i2;
	

	printf("Введите массив типа int по элементно");

	for (int i = 0; i < VALUE; i++)
	{
		printf("\nВведите ms[%d]= ", i);
		proof=scanf_s("%d", &mas[i]);
		if (!proof)
		{
			printf("input error");
			fflush(stdin);
			break;
		}
	}
	
	printf("\nИсходный масссив : ");

	for (int i = 0; i < VALUE; i++)
	{           
		
		
		
		if (!proof)
		{
			printf("absent");
			return 0;
		}



		printf("%4d", mas[i]);

	}
	printf("\n");

	//system("CLS");
	printf("Введите интервал из двух чисел (1-ое меньше чем 2-ое)\n ");
	fflush(stdin);
	proof_i1 = scanf_s("Первое= %d\n", &i1);
	proof_i2 = scanf_s("Второе= %d\n", &i2);

	scanf_s("%d", & i1);
	scanf_s("%d", & i2);

	proof_i1 = i1;
	proof_i2 = i2;

	if (proof_i1 <= 0 || proof_i2 <= 0 || proof_i1 == proof_i2|| proof_i1 + proof_i2 < 2 || !proof_i1||!proof_i2 )
	{
		printf("input error");
	}
	else
	{
		for (; i1 < i2; i1++, i2--)
		{
			change = mas[i1];
			mas[i1] = mas[i2];
			mas[i2] = change;

		}

		printf("Преобразованный массив\n");

		for (int i = 0; i < VALUE; i++)
		{
			printf("%4d", mas[i]);
		}
	}

	

	return 0;
}
	