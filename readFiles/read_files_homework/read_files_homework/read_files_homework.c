#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	FILE* f;
	int caunt = 0;
	int asterisks = 0;

	f = fopen("targil.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(f);
			caunt++;

			if (ch == '*')
			{
				asterisks++;
			}
		}
		fclose(f);
	}

	printf("\n");

	/* על אותו קובץ כתבו פונקציה שמדפיסה את הכמות של התווים שיש בקובץ  */
	printf("%d \n", caunt);

	/* על אותו קובץ כתבו פונקציה שמחזירה כמה * יש בקובץ  */
	printf("%d \n", asterisks);

	/* כמה שורות יש בקובץ? רמז :\n  */

	caunt = 0;
	f = fopen("targil2.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			if (ch == '\n')
			{
				caunt++;
			}
			ch = fgetc(f);
		}
		fclose(f);
	}
	caunt += 1;
	printf("%d \n", caunt);

	/*
	בהתייחס לקובץ הזה:
	כתבו תוכנית שקוראת  את הקובץ הזה

	שימו לב לפורמט של הקובץ הזה מכיל צמדים של תוים
	מספר וטיפוס. C הוא char

	I הוא integer

	זהו קובץ הוראות ליצירת זיכרון דינמי

	עליכם לקרוא את כל הקובץ ולייצר בהתאמה את מרחבי הזכרון לפי ההוראות ש ל הקובץ

	לדוגמא  בהתחלה מייצר 3 תאים של CHAR, לאחר מכן מייצר 4 משתנים של INT וכך הלאה
	*/

	f = fopen("targil3.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		// 3c 4i 5c 5i 8i 2c 4c 5i
		int* allotment_of_int;
		char* allotment_of_char;
		int num;
		char number;
		char zero = 48;
		char ch = fgetc(f);
		while (ch != EOF)
		{
			if (ch != 'c' || ch != 'i')
			{
				number = ch;
				ch = fgetc(f);
			}

			if (ch == 'c')
			{
				num = number - zero;
				allotment_of_char = malloc(num * sizeof(char));
				char x = 1;
				for (char i = 1; i <= num; i++)
				{
					getchar();
					scanf(" %c", allotment_of_char);
					fflush(stdin);
					allotment_of_char++;
				}
				allotment_of_char -= num;
				free(allotment_of_char);
				ch = fgetc(f);
			}
			else if (ch == 'i')
			{
				num = number - zero;
				allotment_of_int = malloc(num * sizeof(int));
				for (int i = 1; i <= num; i++)
				{
					getchar();
					scanf(" %s", allotment_of_int);
					fflush(stdin);
					allotment_of_int++;
				}
				allotment_of_int -= num;
				free(allotment_of_int);
				ch = fgetc(f);
			}
		}
		fclose(f);
	}
	return 0;
}