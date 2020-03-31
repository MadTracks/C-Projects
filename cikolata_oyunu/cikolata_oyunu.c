#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cikolataboyu(int cikolata[],int cikosayi);
void cikolataBas(int cikolata[],int cikosayi);
int CikolataKontrolAyse(int cikolata[],int posAyse);
int CikolataKontrolMehmet(int cikolata[],int posMehmet);
int cikolataYemeIslemi(int cikolata[],int cikosayi);
void CikolataKazanan(int Mehmetsayi,int Aysesayi);


int cikolataboyu(int cikolata[],int cikosayi){
	srand(time(NULL));
	for(int i=0; i<cikosayi; i++){
		cikolata[i]=rand()%11+1;
	}
	return cikosayi;
}
void cikolataBas(int cikolata[],int cikosayi){
	printf("Cikolata boylari:");
	for(int i=0; i<cikosayi; i++){
		printf("%d ",cikolata[i]);
	}
	printf("\n");
}

int CikolataKontrolAyse(int cikolata[],int posAyse){
	if(cikolata[posAyse]==0){
		return posAyse-1;
	}
	else if(cikolata[posAyse]>0){
		return posAyse;
	}
}
int CikolataKontrolMehmet(int cikolata[],int posMehmet){
	if(cikolata[posMehmet]==0){
		return posMehmet+1;
	}
	else if(cikolata[posMehmet]>0){
		return posMehmet;
	}
}
int cikolataYemeIslemi(int cikolata[],int cikosayi){
	int posMehmet=0;
	int posAyse=cikosayi-1;
	int Mehmetsayi;
	int Aysesayi;
	while(posAyse > posMehmet+1){
		cikolata[posMehmet]=cikolata[posMehmet]-2;
		cikolata[posAyse]=cikolata[posAyse]-1;
		if(cikolata[posMehmet]==-1){
			posMehmet=posMehmet+1;
			cikolata[posMehmet]=cikolata[posMehmet]-1;
		}
		posAyse=CikolataKontrolAyse(cikolata,posAyse);
		posMehmet=CikolataKontrolMehmet(cikolata,posMehmet);
	}
	if(cikolata[posMehmet]==cikolata[posAyse]){
		posAyse++;
		posMehmet++;
	}
	Mehmetsayi=posMehmet+1;
	Aysesayi=cikosayi-posAyse;
	CikolataKazanan(Mehmetsayi,Aysesayi);
	return 0;
}
void CikolataKazanan(int Mehmetsayi,int Aysesayi){
	printf("Mehmetin yedigi cikolata sayisi:%d\n",Mehmetsayi);
	printf("Aysenin yedigi cikolata sayisi:%d\n",Aysesayi);
	printf("Kazanan:");
	if(Mehmetsayi>Aysesayi){
		printf("Mehmet\n");
	}
	else if(Aysesayi>Mehmetsayi){
		printf("Ayse\n");
	}
	else if(Mehmetsayi == Aysesayi){
		printf("Berabere\n");
	}
}
int main(){

	int cikolata[6];
	cikolataboyu(cikolata,6);
	cikolataBas(cikolata,6);
	cikolataYemeIslemi(cikolata,6);
}
