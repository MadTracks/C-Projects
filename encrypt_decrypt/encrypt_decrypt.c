#include <stdio.h>

int find_size_of_line(char line[])
{
	int counter,lines;
	lines=0;
	for(counter=0; line[counter]!=0; counter++)
	{
		lines++;
	}
	return lines;
}
void reverse_line(char line[], int line_length)
{
	char tempstr[line_length];
	int counter,counter2;
	for(counter=0; line[counter]!=0; counter++)
	{
		tempstr[line_length-counter-1]=line[counter];
	}
	tempstr[line_length]=0;
	for(counter2=0; line[counter2]!=0; counter2++)
	{
		line[counter2]=tempstr[counter2];
	}
}

void encrypt_open_msg()
{
	char file_name[]="open_msg.txt";
	char file_name2[]="secret_msg.txt";
	char str[1024];
	int key, i,j;
	
	FILE * fin;
	FILE * fin2;
	fin=fopen(file_name,"r");
	fin2=fopen(file_name2,"w");
	fscanf(fin,"%c",&str[0]);
	for(i=0; str[i]!=0; i++)
	{
		fscanf(fin,"%c",&str[i+1]);
	}
	printf("Key(between 1-26):");
	scanf("%d",&key);
	reverse_line(str,find_size_of_line(str));
	
	for(j=0; str[j]!=0; j++)
	{
		if(str[j]=='.')
		{
			str[j]='*';
		}
		else
		{
			if(str[j]==' ')
			{
				str[j]='_';
			}
			else
			{
				if(str[j]>='a' && str[j]<='z')
				{
					str[j]-=key;
					if(str[j]<'a')
					{
						str[j]+=26;
					}
				}
			}
		}
		
	}
	
	fprintf(fin2,"%s",str);
	printf("%s\n",str);
	
	fclose(fin);
	fclose(fin2);
}
void decrypt_secret_msg()
{
	char file_name[]="secret_msg.txt";
	char file_name2[]="open_msg.txt";
	char str[1024];
	int key, i,j;
	
	FILE * fin;
	FILE * fin2;
	fin=fopen(file_name,"r");
	fin2=fopen(file_name2,"w");
	fscanf(fin,"%c",&str[0]);
	for(i=0; str[i]!=0; i++)
	{
		fscanf(fin,"%c",&str[i+1]);
	}
	printf("Key(between 1-26):");
	scanf("%d",&key);
	reverse_line(str,find_size_of_line(str));
	
	for(j=0; str[j]!=0; j++)
	{
		if(str[j]=='*')
		{
			str[j]='.';
		}
		else
		{
			if(str[j]=='_')
			{
				str[j]=' ';
			}
			else
			{
				if(str[j]>='a' && str[j]<='z')
				{
					str[j]+=key;
					if(str[j]>'z')
					{
						str[j]-=26;
					}
				}
			}
		}
	}
	
	fprintf(fin2,"%s",str);
	printf("%s\n",str);
	
	fclose(fin);
	fclose(fin2);
}
void menu()
{
	int select=1;
	while(select!=0)
	{
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:");
		scanf("%d",&select);
		switch(select)
		{
			case 1: encrypt_open_msg(); break;
			case 2: decrypt_secret_msg(); break;
			case 0: break;
			default: printf("Wrong selection!\n"); break;
		}
	}
}
int main()
{
	menu();
	return 0;
}
