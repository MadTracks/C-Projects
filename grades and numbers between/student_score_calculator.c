#include <stdio.h>
#include <stdlib.h>

void most_successful(int successful_student,int successful_index)		
{
	printf("Most Successfully student:\n");
	printf("Index: %d\n",successful_index);
	printf("Score: %d\n",successful_student);			/*Prints most successful student*/
	printf("Letter grade:");
	if(successful_student<60) printf("F\n");
	else if(successful_student<70) printf("D\n");			/*Finds the grade of most successful student*/
	else if(successful_student<80) printf("C\n");
	else if(successful_student<90) printf("B\n");
	else if(successful_student<=100) printf("A\n");
	printf("\n");
}
void most_unsuccessful(int unsuccessful_student,int unsuccessful_index)
{
	printf("Most Unsuccessfully student:\n");
	printf("Index: %d\n",unsuccessful_index);
	printf("Score: %d\n",unsuccessful_student);			/*Prints most unsuccessful student*/
	printf("Letter grade:");
	if(unsuccessful_student<60) printf("F\n");			/*Finds the grade of most unsuccessful student*/
	else if(unsuccessful_student<70) printf("D\n");			
	else if(unsuccessful_student<80) printf("C\n");
	else if(unsuccessful_student<90) printf("B\n");
	else if(unsuccessful_student<=100) printf("A\n");
	printf("\n");
}
void grade_stats(int a,int b,int c, int d, int f)
{
	printf("%d student got letter grade 'A'\n",a);			/*Prints the total grades*/
	printf("%d student got letter grade 'B'\n",b);
	printf("%d student got letter grade 'C'\n",c);
	printf("%d student got letter grade 'D'\n",d);
	printf("%d student got letter grade 'F'\n",f);
	printf("\n");
}

void calculate_average(int student_number, int average_sum)
{
	double average;
	average=average_sum*1.0/student_number;
	printf("The average score of %d Student is %lf\n",student_number,average);	/*Calculates the average and prints it*/
	printf("\n");
}

void menu(int student_number, 
	  int successful_student,
	  int successful_index,
	  int unsuccessful_student,
	  int unsuccessful_index,
	  int a,
	  int b,
	  int c,
	  int d,
	  int f,
	  int average_sum)
{
	int select;
	
	select=0;
	while(select!=-1)									/*Calls menu while user enters the "-1"*/
	{
		printf("Student Score Calculator Menu for %d Student\n",student_number);	/*Print menu options*/
		printf("\n");
		printf("1-Most successful student\n");
		printf("2-Most unsuccessful student\n");
		printf("3-Letter Grade Statistics\n");
		printf("4-Calculate Average\n");
		printf("5-Show all Data\n");
		printf("			Make Selection:");
		scanf("%d",&select);

		switch(select)
		{
			case 1: most_successful(successful_student, successful_index);		/*Calls the correct function which is user's request*/
				break;
			case 2: most_unsuccessful(unsuccessful_student, unsuccessful_index);
				break;
			case 3: grade_stats(a,b,c,d,f);
				break;
			case 4: calculate_average(student_number,average_sum);
				break;
			case 5: most_successful(successful_student, successful_index);
				most_unsuccessful(unsuccessful_student, unsuccessful_index);
				grade_stats(a,b,c,d,f);
				calculate_average(student_number,average_sum);
				break;
			case -1:break;
			default: printf("False Selection!!!\n");
		}
	}
}
int main(void)
{
	int student_number;
	int student_score;
	int index;
	int successful_student, successful_index;
	int unsuccessful_student, unsuccessful_index;
	int A_grade=0;
	int B_grade=0;
	int C_grade=0;
	int D_grade=0;
	int F_grade=0;
	int average_sum;
	
	successful_student=0;
	unsuccessful_student=100;
	index=1;
	average_sum=0;
	
	printf("Enter student count:");
	scanf("%d",&student_number);
	
	while(student_number>50 || student_number<3)			/*Sets the range of student*/
	{
		printf("Not in Range!!!\n");
		printf("Enter student count:");
		scanf("%d",&student_number);	
	}
	
	srand(40);
	for(int counter=0; counter<student_number; counter++)		
	{
		student_score=rand()%101;
		printf("%d ",student_score);				/*Creates random values and finds the most successful student,the most unsuccessful student, all grades and total score*/
		
		if(student_score>successful_student)
		{
			successful_student = student_score;
			successful_index = index;
		}
		if(student_score<unsuccessful_student)
		{
			unsuccessful_student = student_score;
			unsuccessful_index = index;	
		}
		
		if(student_score<60) F_grade+=1;
		else if(student_score<70) D_grade+=1;
		else if(student_score<80) C_grade+=1;
		else if(student_score<90) B_grade+=1;
		else if(student_score<=100) A_grade+=1;
		
		average_sum+=student_score;
		index+=1;
	}
	printf("\n");
	
	menu(student_number,						/*Calls the menu function*/
	     successful_student,
	     successful_index,
	     unsuccessful_student,
	     unsuccessful_index,
	     A_grade,
	     B_grade,
	     C_grade,
	     D_grade,
	     F_grade,
	     average_sum);
	return 0;
}
