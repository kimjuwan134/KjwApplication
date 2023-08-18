#include <stdio.h>

int main()
{
	int year;
	while (1)
	{
		scanf_s("%d", &year);
		if (year >= 1 && year <= 4000)
		{
			if (year % 4 == 0)
				if (year % 100 != 0 || year % 400 == 0)
					printf("1");

		}
		else
		{
			printf("0");
		}
	}
	return 0;
}