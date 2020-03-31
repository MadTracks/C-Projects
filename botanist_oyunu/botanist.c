#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int pos_x;
	int pos_y;
	int water;
} Botanist;

typedef struct {
	char ** map;
	int width;
	int height;
	int flower_x;
	int flower_y;
} Forest;

void init_game(Forest * forest,Botanist * botanist)
{
	FILE * fin;
	int i,j,k;
	char temp;
	
	fin=fopen("init.txt","r");
	fscanf(fin,"%d",&botanist->water);
	
	fscanf(fin,"%d,%d\n",&forest->width, &forest->height);
	
	forest->map=calloc(forest->width,sizeof(forest->map));
	
	for(i=0; i<forest->height; i++)
	{
		forest->map[i]=calloc(forest->width,sizeof(char *));
	}
	
	for(k=0; k<forest->height; k++)
	{
		for(j=0; j<(forest->width)*2; j++)
		{
			fscanf(fin,"%c",&temp);
			if(temp=='#' || temp==' ' || temp=='B' || temp=='F')
			{
				forest->map[k][j/2]=temp;
				if(temp=='B')
				{
					botanist->pos_x=k;
					botanist->pos_y=j/2;
				}
				if(temp=='F')
				{
					forest->flower_x=k;
					forest->flower_y=j/2;
				}
			}
			else if(temp=='\n')
			{
				j=(forest->width*2)+1;
				k--;
			}
		}
	}
	
	fclose(fin);
}
void print_map(Forest forest)
{
	int i,j;
	for(i=0; i<forest.height; i++)
	{
		for(j=0; j<forest.width; j++)
		{
			printf("%c ",forest.map[i][j]);
		}
		printf("\n");
	}	
}

void search(Forest * forest,Botanist * botanist,int direction)
{
	if(botanist->pos_x == forest->flower_x && botanist->pos_y == forest->flower_y)
	{
		printf("I have found it on (%d,%d)!\n",forest->flower_x,forest->flower_y);
	}
	else
	{
		if(botanist->water<0 && forest->map[botanist->pos_x][botanist->pos_y]==' ')
		{
			printf("Help! I am on (%d,%d)!\n",botanist->pos_x,botanist->pos_y);
		}
		else
		{
			if(botanist->pos_x>=forest->height)
			{
				botanist->pos_x-=1;
				search(forest,botanist,1+rand()%4);
			}
			else
			{
				if(botanist->pos_x<=0)
				{
				botanist->pos_x+=1;
				search(forest,botanist,1+rand()%4);
				}
				else
				{
					if(botanist->pos_y>=forest->width)
					{
						botanist->pos_y-=1;
						search(forest,botanist,1+rand()%4);
					}
					else
					{
						if(botanist->pos_y<0)
						{
							botanist->pos_y+=1;
							search(forest,botanist,1+rand()%4);
						}
						else
						{
							if(forest->map[botanist->pos_x][botanist->pos_y]=='#')
							{
								switch(direction)
								{
								case 1: botanist->pos_x+=1; search(forest,botanist,1+rand()%4); break;
								case 2: botanist->pos_x-=1; search(forest,botanist,1+rand()%4); break;
								case 3: botanist->pos_y+=1; search(forest,botanist,1+rand()%4); break;
								case 4: botanist->pos_y-=1; search(forest,botanist,1+rand()%4); break;
								}
			
							}
							else
							{
								if(forest->map[botanist->pos_x][botanist->pos_y]==' ')
								{
									botanist->water-=1;
								}
								switch(direction)
								{
									case 1: botanist->pos_x-=1; search(forest,botanist,1+rand()%4); break;
									case 2: botanist->pos_x+=1; search(forest,botanist,1+rand()%4); break;
									case 3: botanist->pos_y-=1; search(forest,botanist,1+rand()%4); break;
									case 4: botanist->pos_y+=1; search(forest,botanist,1+rand()%4); break;
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	Forest forest;
	Botanist botanist;
	
	srand(time(NULL));
	init_game(&forest,&botanist);
	
	printf("%d %d %d\n",botanist.water,forest.width,forest.height);
	
	print_map(forest);
	printf("Searching...\n");
	forest.map[botanist.pos_x][botanist.pos_y]=' ';
	search(&forest,&botanist,1+rand()%4);
	forest.map[botanist.pos_x][botanist.pos_y]='B';
	print_map(forest);
	return 0;
}
