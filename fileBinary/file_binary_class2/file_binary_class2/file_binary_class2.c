#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

/*
���� ������ ���� ������ short ����� ���� ����� ������
�� ��� ������� � scanf , ����� ������ � hi

*/

int main()
{
	FILE* f;

	short a;

	f = fopen("data.bin", "w");

	if (f == NULL)
	{
		// error

	}
	else
	{
		scanf("%hi", &a);
		fwrite(&a, sizeof(short), 1, f);
		fclose(f);
	}

	/* �� ����� ������ ����� �� ����� ������� �� ������ �����  */
	f = fopen("data.bin", "r");
	if (f == NULL)
	{
		// error

	}
	else
	{
		int read = fread(&a, sizeof(short), 1, f);
		int malt = (int) a * a;
		printf("%d\n", malt);
		fclose(f);
	}

	/* ���� ������� 10 ������ (������) ������ "����" ����� ���� ����� ����  */
	int b;

	f = fopen("data1.bin", "w");

	if (f == NULL)
	{
		// error

	}
	else
	{
		
		for (int i = 1; i <= 1; i++)
		{
			printf("please enter a number:\n");
			scanf("%d", &b);
			//getch();
			fwrite(&b, sizeof(int), 1, f);
			//printf("Please press enter twice and then select a number");
		}


		fclose(f);
	}

	/*
		�� ����� ������� ����� ���� ������ ������ ������� ���� ����� ���� ���.
		���� ��� ������ �� ��� ������ ������� ���� ����� ����
		���� �� ����� ������� �� �� ������� ��� ����� 
	*/

	f = fopen("exe3.bin", "r");
	if (f == NULL)
	{
		// error

	}
	else
	{
		int num = 0;
		int sum = 0;
		for (int i = 1; i <= 10; i++)
		{
			int read = fread(&num, sizeof(int), 1, f);
			sum += num;
			printf("%d", num);
		}
		printf("\n%d", sum);

		fclose(f);
	}

    return 0;
}