#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum {N,P,S,M,B,T,F,ST}
block_t;
typedef struct
	{
	char text[15];
	int data;
	block_t type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
	} block;

int init_board(block board[][10],int max_row)
{
	int i,j;
	char digit1,digit2;
	char num[4];
	
	for(i=0; i<max_row; i++)
	{
		if(i%2==0)
		{
			for(j=0; j<10; j++)
			{
				board[i][j].data=(9-i)*10+(j+1);
				board[i][j].type=N;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=i;
				board[i][j].jump_y=j;
				digit1=(9-i)+'0';
				if(j<9)
				{
					digit2=(j+1)+'0';
				}
				else
				{
					digit1+=1;
					digit2='0';
				}
				num[0]=digit1;
				num[1]=digit2;
				num[2]=0;
				strcpy(board[i][j].text,num);
			}
		}
		else
		{
			for(j=0; j<10; j++)
			{
				board[i][j].data=(9-i)*10+(10-j);
				board[i][j].type=N;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].jump_x=i;
				board[i][j].jump_y=j;
				digit1=(9-i)+'0';
				if(j>0)
				{
					digit2=(10-j)+'0';
				}
				else
				{
					digit1+=1;
					digit2='0';
				}
				num[0]=digit1;
				num[1]=digit2;
				num[2]=0;
				strcpy(board[i][j].text,num);
			}
		}
	}
	/*Finish*/
	board[0][9].type=F;
	strcpy(board[0][9].text,"100 (Finish)");
	/*Snakes*/
	board[0][8].type=S;
	strcpy(board[0][8].text,"S {56}");
	board[0][8].jump_x=4;
	board[0][8].jump_y=5;
	board[0][7].type=S;
	strcpy(board[0][7].text,"S {72}");
	board[0][7].jump_x=2;
	board[0][7].jump_y=1;
	board[2][2].type=S;
	strcpy(board[2][2].text,"S {68}");
	board[2][2].jump_x=3;
	board[2][2].jump_y=2;
	board[3][7].type=S;
	strcpy(board[3][7].text,"S {52}");
	board[3][7].jump_x=4;
	board[3][7].jump_y=1;
	board[4][9].type=S;
	strcpy(board[4][9].text,"S {44}");
	board[4][9].jump_x=5;
	board[4][9].jump_y=6;
	board[5][5].type=S;
	strcpy(board[5][5].text,"S {22}");
	board[5][5].jump_x=7;
	board[5][5].jump_y=8;
	board[7][5].type=S;
	strcpy(board[7][5].text,"S {12}");
	board[7][5].jump_x=8;
	board[7][5].jump_y=1;
	board[9][4].type=S;
	strcpy(board[9][4].text,"S {1}");
	board[9][4].jump_x=9;
	board[9][4].jump_y=9;
	/*Traps*/
	board[0][2].type=T;
	strcpy(board[0][2].text,"T");
	board[0][2].jump_x=1;
	board[0][2].jump_y=2;
	board[2][8].type=T;
	strcpy(board[2][8].text,"T");
	board[2][8].jump_x=2;
	board[2][8].jump_y=3;
	board[4][3].type=T;
	strcpy(board[4][3].text,"T");
	board[4][3].jump_x=5;
	board[4][3].jump_y=1;
	board[6][9].type=T;
	strcpy(board[6][9].text,"T");
	board[6][9].jump_x=6;
	board[6][9].jump_y=4;
	/*Penalties*/
	board[1][5].type=P;
	strcpy(board[1][5].text,"P");
	board[5][2].type=P;
	strcpy(board[5][2].text,"P");
	board[8][2].type=P;
	strcpy(board[8][2].text,"P");
	/*Stairs*/
	board[1][1].type=M;
	strcpy(board[1][1].text,"M {94}");
	board[1][1].jump_x=0;
	board[1][1].jump_y=3;
	board[2][5].type=M;
	strcpy(board[2][5].text,"M {83}");
	board[2][5].jump_x=1;
	board[2][5].jump_y=7;
	board[3][1].type=M;
	strcpy(board[3][1].text,"M {77}");
	board[3][1].jump_x=2;
	board[3][1].jump_y=6;
	board[4][6].type=M;
	strcpy(board[4][6].text,"M {77}");
	board[4][6].jump_x=2;
	board[4][6].jump_y=6;
	board[6][1].type=M;
	strcpy(board[6][1].text,"M {52}");
	board[6][1].jump_x=4;
	board[6][1].jump_y=1;
	board[8][6].type=M;
	strcpy(board[8][6].text,"M {28}");
	board[8][6].jump_x=7;
	board[8][6].jump_y=2;
	board[9][3].type=M;
	strcpy(board[9][3].text,"M {11}");
	board[9][3].jump_x=8;
	board[9][3].jump_y=0;
	/*Boosts*/
	board[1][8].type=B;
	strcpy(board[1][8].text,"B");
	board[1][8].jump_x=1;
	board[1][8].jump_y=3;
	board[3][4].type=B;
	strcpy(board[3][4].text,"B");
	board[3][4].jump_x=2;
	board[3][4].jump_y=0;
	board[5][0].type=B;
	strcpy(board[5][0].text,"B");
	board[5][0].jump_x=4;
	board[5][0].jump_y=4;
	board[6][5].type=B;
	strcpy(board[6][5].text,"B");
	board[6][5].jump_x=5;
	board[6][5].jump_y=9;
	board[7][1].type=B;
	strcpy(board[7][1].text,"B");
	board[7][1].jump_x=6;
	board[7][1].jump_y=3;
	/*Start*/
	board[9][9].type=ST;
	strcpy(board[9][9].text,"1 (Start)");
	return 0;
}
void print_board(block board[][10],int max_row)
{
	int i,j;
	for(i=0; i<max_row; i++)
	{
		for(j=0; j<10; j++)
		{
			printf("%s  ",board[i][j].text);
		}
		printf("\n");
	}
}

int move(block board[][10],int pos_x, int pos_y,int *last_pos_x, int *last_pos_y)
{
	int dice,ret;
	dice=1+(rand()%6);
	ret=1;
	printf("Dice:%d ",dice);
	printf("Block: %s\n",board[pos_x][pos_y].text);
	if(pos_x%2==0)
	{
		if(pos_y+dice>9)
		{
			dice-=9-pos_y;
			*last_pos_x=pos_x-1;
			*last_pos_y=9-dice;
		}
		else
		{
			*last_pos_y=pos_y+dice;
			*last_pos_x=pos_x;
		}
	}
	else
	{
		if(pos_y-dice<0)
		{
			dice-=pos_y;
			*last_pos_x=pos_x-1;
			*last_pos_y=dice-1;
		}
		else
		{
			*last_pos_y=pos_y-dice;
			*last_pos_x=pos_x;
		}
	}
	if(*last_pos_x<0)
	{
		*last_pos_x=pos_x;
		*last_pos_y=pos_y;
		ret=-1;
	}
	return ret;
}
void jump_block(block board[][10],int pos_x,int pos_y, int *new_pos_x, int *new_pos_y)
{
	*new_pos_x=board[pos_x][pos_y].jump_x;
	*new_pos_y=board[pos_x][pos_y].jump_y;
}

int singleplayer(block board[][10],int pos_x,int pos_y)
{	
	if(move(board,pos_x,pos_y,&pos_x,&pos_y)==-1)
	{
		return 1+singleplayer(board,pos_x,pos_y);
	}
	if(pos_x == 0 && pos_y == 9) return 0;
	
	else
	{
		if(board[pos_x][pos_y].type==P)
		{
			return 1+singleplayer(board,pos_x,pos_y);
		}
		else
		{
			if(board[pos_x][pos_y].type==S || board[pos_x][pos_y].type==M || board[pos_x][pos_y].type==B || board[pos_x][pos_y].type==T)
			{
				jump_block(board,pos_x,pos_y,&pos_x,&pos_y);
			}
		}
	}
	return 1+singleplayer(board,pos_x,pos_y);
}

int multiplayer(block board[][10])
{
	int player1,player2;
	printf("Player 1:\n");
	player1=singleplayer(board,9,9);
	printf("Player 2:\n");
	player2=singleplayer(board,9,9);
	printf("Number of turns of player1:%d\n",player1);
	printf("Number of turns of player2:%d\n",player2);
	
	if(player1>player2)
	{
		printf("Player 2 wins.\n");
	}
	else
	{
		if(player2==player1)
		{
			printf("No one wins.\n");
		}
		else
		{
			printf("Player 1 wins.\n");
		}
	}
}
int main()
{
	block board[10][10];
	int turns;
	srand(time(NULL));
	init_board(board,10);
	print_board(board,10);
	turns=singleplayer(board,9,9);
	printf("Number of turns:%d\n",turns);
	multiplayer(board);
	return 0;
}
