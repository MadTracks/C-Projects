#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum gender{Male,Female}
gender_t;

typedef struct customer{
	char name[20];
	char surname[20];
	int age;
	gender_t gender;
	struct customer * next;
}customer_t;

typedef struct room{
	int no;
	int capacity;
	int floor;
	customer_t * cus;
	struct room * next;
} room_t;

room_t * add_room_to_end(room_t * room,int no,int cap,int floor)
{
	if(room==0)
	{
		room= (room_t *) malloc(sizeof(room_t));
		room->capacity=cap;
		room->floor=floor;
		room->no=no;
		room->next=0;
		room->cus=0;
		return room;
	}
	return add_room_to_end(room->next,no,cap,floor);
}
room_t * add_room_after_room_number(room_t * room,int number,int cap,int floor)
{
	if(room==0)
		{
			room=add_room_to_end(room,number,cap,floor);
			return room;
		}
	else
	{
		if(room->no==number)
		{
			room_t *next_room;
			next_room = (room_t *) malloc(sizeof(room_t));
			next_room->next=room->next;
			room->next=next_room;
			room->capacity=cap;
			room->floor=floor;
			room->no=number+1;
			room->cus=0;
			return room;
		}
	}
	return add_room_after_room_number(room->next,number,cap,floor);
}
customer_t * add_customer_to_end(customer_t * customer,char * name, char * surname,int age,gender_t gender)
{
	if(customer==0)
	{
		customer=(customer_t *)malloc(sizeof(customer_t));
		strcpy(customer->name,name);
		strcpy(customer->surname,surname);
		customer->age=age;
		customer->gender=gender;
		customer->next=0;
		return customer;
	}
	return add_customer_to_end(customer->next,name,surname,age,gender);
}
customer_t * end_customer(customer_t * customer)
{
	if(customer->next==0)
	{
		return customer;
	}
	return end_customer(customer->next);
}

room_t * link_customers_to_room(room_t * room,customer_t * customer,int number, char * name, char * surname,int age,gender_t gender)
{
	if(room==0)
	{
		return 0;
	}
	else
	{
		if(room->no==number)
		{
			if(room->cus==0)
			{
				customer=add_customer_to_end(customer,name,surname,age,gender);
				room->cus=customer;
			}
			else
			{
				customer_t * temp;
				customer=add_customer_to_end(room->cus,name,surname,age,gender);
				temp=end_customer(room->cus);
				temp->next=customer;
			}
			return room;
		}
	}
	return link_customers_to_room(room->next,customer,number,name,surname,age,gender);
}
room_t * remove_room(room_t * room,int number)
{
	if(room==0)
	{
		return 0;
	}
	else
	{
		if(room->no==number)
		{
			room_t * temp;
			temp=room->next;
			free(room);
			return temp;
		}
	room->next=remove_room(room->next,number);
	}
	return room;
}
int show_vacancy(room_t * room)
{
	if(room==0)
	{
		return 0;
	}
	else
	{
		if(room->cus==0)
		{
			printf("%d\n",room->no);
		}
	}
	return show_vacancy(room->next);
}
int get_by_floor(room_t * room,int floor)
{
	if(room==0)
	{
		return 0;
	}
	else
	{
		if(room->floor==floor)
		{
			printf("Room %d\n",room->no);
		}
	}
	return get_by_floor(room->next,floor);
}
int print_list_customer(customer_t * cus)
{
	if(cus==0)
	{
		return 0;
	}
	else
	{
		printf("%s %s (%d - ",cus->name,cus->surname,cus->age);
		if(cus->gender==Male)
		{
			printf("Male)\n");
		}
		else
		{
			printf("Female)\n");
		}
	}
	return print_list_customer(cus->next);
}
int print_list(room_t * room)
{
	if(room==0)
	{
		return 0;
	}
	else
	{
		printf("Room %d (Floor %d - capacity %dx):\n",room->no,room->floor,room->capacity);
		if(room->cus!=0)
		{
			print_list_customer(room->cus);
		}
		else
		{
			printf("Empty\n");
		}
	}
	return print_list(room->next);
}
int main()
{
	room_t * rooms;
	room_t * head;
	customer_t * customers;
	int i,j,k;
	int room_no;
	int room_cap;
	int room_floor;
	char cus_name[20];
	char cus_surname[20];
	int cus_age;
	char cus_gen[7];
	gender_t cus_gender;
	
	rooms=0;
	customers=0;
	i=0;
	j=0;
	FILE * fin;
	fin=fopen("rooms.txt","r");
	fscanf(fin,"%d,%d,%d\n",&room_no,&room_cap,&room_floor);
	rooms=add_room_after_room_number(rooms,room_no,room_cap,room_floor);
	head=rooms;
	do{
	fscanf(fin,"%d,%d,%d\n",&room_no,&room_cap,&room_floor);
	rooms->next=add_room_after_room_number(rooms,room_no,room_cap,room_floor);
	rooms=rooms->next;
	rooms->next=0;
	i++;
	}
	while(i<=26);
	rooms=head;
	fclose(fin);
	FILE * fin2;
	fin2=fopen("customers.txt","r");
	do{
	fscanf(fin2,"%d,",&room_no);
	fscanf(fin2,"%c",&cus_name[0]);
	for(k=0; cus_name[k]!=' '; k++)
	{
		fscanf(fin2,"%c",&cus_name[k+1]);
	}
	cus_name[k+1]=0;
	fscanf(fin2,"%c",&cus_surname[0]);
	for(k=0; cus_surname[k]!=','; k++)
	{
		fscanf(fin2,"%c",&cus_surname[k+1]);
	}
	cus_surname[k+1]=0;
	fscanf(fin2,"%d,",&cus_age);
	fscanf(fin2,"%c",&cus_gen[0]);
	for(k=0; cus_gen[k]!='\n'; k++)
	{
		fscanf(fin2,"%c",&cus_gen[k+1]);
	}
	if(cus_gen[0]=='M')
	{
		cus_gender=Male;
	}
	else
	{
		cus_gender=Female;
	}
	rooms = link_customers_to_room(rooms,customers,room_no,cus_name,cus_surname,cus_age,cus_gender);
	j++;
	rooms=head;
	}
	while(j<=33);
	fclose(fin2);
	print_list(rooms);
	/*rooms = remove_room(rooms,102);*/	/*Removes a room*/
	/*show_vacancy(rooms);*/		/*Shows free rooms*/
	/*get_by_floor(rooms,4);*/		/*Shows rooms by floor*/
	free(head);
	return 0;
}
