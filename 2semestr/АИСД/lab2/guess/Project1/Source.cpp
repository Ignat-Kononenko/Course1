#include <stdio.h>
#include<iostream>

#define HIGH 100
#define LOW 1
int main()
{
	setlocale(LC_ALL, "rus");
	int guess = (HIGH + LOW) / 2;
	int highest = HIGH;
	int lowest = LOW;
	char response;
	printf(" «адумайте число от %d до %d. я попробую", LOW, HIGH);
	printf(" угадать его.\n ќтвечайте q, если мо€ догадка правильна,");
	printf(" d, если \n больше, и a, если");
	printf(" меньше. \n");
	printf("»так ... ваше число %d?\n", guess);
	while ((response = getchar()) != 'q')
	{
		if (response != ' \n')
		{
			if (response == 'd')
			{/* уменьшение верхнего предела. ≈сли предло-
			женное значение слишком велико */
				highest = guess - 1;
				guess = (highest + lowest) / 2;
				printf(" √м ... слишком велико. ¬аше число %d?\n", guess);
			}
			else if (response == 'a')
				{/* увеличение нижнего предела, если предложенное значение слишком мало */
					lowest = guess + 1;
					guess = (highest + lowest) / 2;
					printf("√м ... слишком мало.¬аше число % d ? \n", guess);
				}
				else
				{/* подводите пользовател€ к правильному ответу */
					printf("я не понимаю; введите, пожалуйста, д, б");
					printf(" или м.\n");
				}
		}
		
	}
	printf("я знала, что смогу сделать это!\n");
}