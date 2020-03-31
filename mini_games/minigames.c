#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt(int mini, int maxi)
{
	int number;
	scanf("%d",&number);
	while(number>maxi || number<mini)
	{
		printf("Number not in range.\n");	/*Takes a number from user. If it's not in range, it gives an error and ask a number again*/
		printf("Enter number:");
		scanf("%d",&number);
	}
	return number;
}

int numberGeneratorBetweenRange(int min,int max)
{
	int number;
	number=rand()%(max+1);
	while(number>max || number<min)			/*Takes a random number. If it's not in range, it takes another number again.*/
	{
		number=rand()%(max+1);
	}
	return number;
}

void horseRacingGame()
{
	int horsenum;
	int userhorse;
	int horsetime;
	int winner;
	int counter2;
	int winnertime;
	
	winner=0;
	winnertime=25;
	horsenum=numberGeneratorBetweenRange(3,5);
	printf("Number of Horse:%d\n",horsenum);		/*Takes a horse number from user*/
	printf("Horse Number:");
	userhorse=getInt(1,horsenum);
	printf("Racing starts...\n");
	
	for(int counter=1; counter<=horsenum; counter++)
	{
		horsetime=numberGeneratorBetweenRange(10,20);
		printf("Horse %d:",counter);
		for(counter2=1; counter2<=horsetime; counter2++)	/*Prints horses' time*/
		{
			printf("-");
		}
		printf("\n");
		if(counter2<=winnertime)
		{
			winnertime=counter2;
			winner=counter;	
		}
	}
	if(userhorse==winner)
	{
		printf("You win!");					
	}
	else
	{
		printf("You lose!");
	}
	printf("Winner is Horse %d.",winner);
}

int power(int num1, int num2)
{
	int result;
	result=1;
	for(int counter=1; counter<=num2; counter++)			/*Calculates power(pow function returns double but this function returns integer)*/
	{
		result*=num1;
	}
	return result;
}
int calculateOccur(int bignum,int searchnum,int bigdigit)
{
	int temp,temp2;
	int digit;
	int occur;
	int counter;
	occur=0;
	counter=0;
	while(power(10,counter)<bignum)
	{
		temp=bignum%(power(10,counter));
		temp2=bignum%(power(10,counter+bigdigit));		/*Finds occurence between two digits*/
		digit=temp2-temp;
		digit=digit/power(10,counter);
			
		if(digit == searchnum)
		{
			occur++;
		}
		counter++;
	}
	return occur;
}

void countOccurence()
{
	int bignum;
	int searchnum;
	int occur;
	
	printf("Big Number:");
	bignum=getInt(1,999999999);
	printf("Search Number:");
	searchnum=getInt(1,999999999);
	
	if(searchnum<10 && searchnum>0)
	{
		occur=calculateOccur(bignum,searchnum,1);
	}
	if(searchnum<100 && searchnum>10)
	{
		occur=calculateOccur(bignum,searchnum,2);
	}
	if(searchnum<1000 && searchnum>100)
	{
		occur=calculateOccur(bignum,searchnum,3);		/*Calls the calculateOccur function to find occurence*/
	}
	if(searchnum<10000 && searchnum>1000)
	{
		occur=calculateOccur(bignum,searchnum,4);
	}
	if(searchnum<100000 && searchnum>10000)
	{
		occur=calculateOccur(bignum,searchnum,5);
	}
	if(searchnum<1000000 && searchnum>100000)
	{
		occur=calculateOccur(bignum,searchnum,6);
	}
	if(searchnum<10000000 && searchnum>1000000)
	{
		occur=calculateOccur(bignum,searchnum,7);
	}
	if(searchnum<100000000 && searchnum>10000000)
	{
		occur=calculateOccur(bignum,searchnum,8);
	}
	if(searchnum<1000000000 && searchnum>100000000)
	{
		occur=calculateOccur(bignum,searchnum,9);
	}
	printf("Occurrence:%d\n",occur);
}

void triangleOfSequences()
{
	int num;
	num=numberGeneratorBetweenRange(2,10);
	for(int counter=1; counter<=num; counter++)
	{
		for(int counter2=1; counter2<=counter; counter2++)		/*Prints random triangles between 2 and 10*/
		{
			printf("%d ", counter*counter2);
		}
	printf("\n");
	}
}

void menu()
{
	int select;
	
	select=100;
	while(select!=0)
	{
		printf("\n");
		printf("1. Horse Racing Game\n");
		printf("2. Occurrence Counter\n");		/*Takes an option from user and continues until user enters zero*/
		printf("3. Triangle of Sequences\n");
		printf("0. Exit\n");
		scanf("%d",&select);
		
		switch(select)
		{
			case 1: horseRacingGame(); break;
			case 2: countOccurence(); break;
			case 3: triangleOfSequences(); break;
			case 0: break;
			default: printf("You entered wrong option. Try again"); break;
		}
	}
}

int main()
{
	srand(time(NULL));		/*Calls menu*/
	menu();
	return 0;
}
