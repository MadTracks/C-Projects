#include <stdio.h>

int character_to_integer_date(char str[], int *day, int *month, int *year)
{
	int counter,ret;
	int digitarray[10];
	
	ret=0;
	
	for(counter=0; str[counter]!=0; counter++)
	{
		digitarray[counter]=str[counter]-'0';
	}
	*day=(digitarray[0]*10)+digitarray[1];
	*month=(digitarray[3]*10)+digitarray[4];
	*year=(digitarray[6]*1000)+(digitarray[7]*100)+(digitarray[8]*10)+digitarray[9];
	
	if(*day>29 && *month==2 || *day>30 && (*month==4 || *month==6 || *month==9 || *month==11) || *day>31)
	{
		ret=-1;
	}
	return ret;
}

int date_with_number()
{
	char file_name[]="input_date.txt";
	char datestart[10];
	char dateend[10];
	int r1,r2;
	int sd, sm, sy;
	int ed, em, ey;
	int i,j,k;
	
	FILE * date;
	date = fopen(file_name,"w");
	printf("Enter a start date(dd/MM/yyyy):");
	scanf("%s",datestart);
	r1 = character_to_integer_date(datestart,&sd,&sm,&sy);
	while (r1==-1)
	{
		printf("Wrong date.\n");
		printf("Enter a start date(dd/MM/yyyy):");
		scanf("%s",datestart);
		r1 = character_to_integer_date(datestart,&sd,&sm,&sy);
	}
	printf("Enter a end date(dd/MM/yyyy):");
	scanf("%s",dateend);
	r2 = character_to_integer_date(dateend,&ed,&em,&ey);
	while (r2==-1)
	{
		printf("Wrong date.\n");
		printf("Enter a end date(dd/MM/yyyy):");
		scanf("%s",dateend);
		r2 = character_to_integer_date(dateend,&ed,&em,&ey);
	}
	
	for(k=sy; k!=ey; k++)
	{
		for(i=sm; i<=12; i++)
		{
			if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			{
				for(j=sd; j<=31; j++)
				{
					printf("%d/%d/%d\n",j,i,k);
					fprintf(date,"%d/%d/%d\n",j,i,k);
				}
			}
			else
			{
				if(i==2)
				{
					if(sy%4!=0)
					{
						for(j=sd; j<=28; j++)
						{
							printf("%d/%d/%d\n",j,i,k);
							fprintf(date,"%d/%d/%d\n",j,i,k);
						}
					}
					else
					{
						for(j=sd; j<=29; j++)
						{
							printf("%d/%d/%d\n",j,i,k);
							fprintf(date,"%d/%d/%d\n",j,i,k);
						}
					}
				}
				else
				{
					for(j=sd; j<=30; j++)
					{
						printf("%d/%d/%d\n",j,i,k);
						fprintf(date,"%d/%d/%d\n",j,i,k);
					}
				}
			}
		sd=1;
		}
	sm=1;
	}
	if(k==ey)
	{
		for(i=sm; i<=em; i++)
		{
			if(i!=em)
			{
				if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
				{
					for(j=sd; j<=31; j++)
					{
						printf("%d/%d/%d\n",j,i,k);
						fprintf(date,"%d/%d/%d\n",j,i,k);
					}
				}
				else
				{
					if(i==2)
					{
						if(sy%4!=0)
						{
							for(j=sd; j<=28; j++)
							{
								printf("%d/%d/%d\n",j,i,k);
								fprintf(date,"%d/%d/%d\n",j,i,k);
							}
						}
						else
						{
							for(j=sd; j<=29; j++)
							{
								printf("%d/%d/%d\n",j,i,k);
								fprintf(date,"%d/%d/%d\n",j,i,k);
							}
						}
					}
					else
					{
						for(j=sd; j<=30; j++)
						{
							printf("%d/%d/%d\n",j,i,k);
							fprintf(date,"%d/%d/%d\n",j,i,k);
						}
					}
				}
			}
			else
			{
				for(j=sd; j<=ed; j++)
				{
					printf("%d/%d/%d\n",j,i,k);
					fprintf(date,"%d/%d/%d\n",j,i,k);
				}
			}
		sd=1;
		}
	}
	fclose(date);
	
	return 0;
}
int main()
{
	date_with_number();
	return 0;
}
