#include <stdio.h>

int main(void)
{
	int number;
	int digit1;
	int digit2;
	int digit3;
	int digit4;
	int digit5;
	int mod2;
	int mod3;
	int mod4;
	
	printf("Enter the number:");			/*Takes number from user*/
	scanf("%d",&number);
	
	if(number<23 || number >98760)
	{
		printf("You entered wrong number.Number limit is:23-98760\n");
	}
	else
	{
		digit1 = number%10;				/*Finds the first digit of number*/
		
		printf("The first digit is %d\n",digit1);	/*Print the first digit of number*/
		
		mod2 = number%100;
		digit2 = mod2 - digit1;				/*Finds the second digit of number*/
		digit2 = digit2 / 10;
		
		printf("The second digit is %d\n",digit2);	/*Prints the second digit of number*/
		
		mod3 = number%1000;
		digit3 = mod3 - mod2;
		digit3 = digit3 / 100;				/*Finds the third digit of number*/
		
		printf("The third digit is %d\n",digit3);	/*Prints the third digit of number*/
		
		mod4 = number%10000;
		digit4 = mod4 - mod3;				/*Finds the fourth digit of number*/
		digit4 = digit4 / 1000;
		
		printf("The fourth digit is %d\n",digit4);	/*Prints the fourth digit of number*/
		
		digit5 = number - mod4;
		digit5 = digit5 / 10000;			/*Finds the fifth digit of number*/
		
		printf("The fifth digit is %d\n",digit5);	/*Prints the fifth digit of number*/
	}	
	return 0;
}
