#include <stdio.h>

int carpantoplami(int sayi1){
	int bolum,kalan,carpan;
	
	carpan=0;
	for(int i=1; i<sayi1; i++){
		bolum = sayi1/i;
		kalan = sayi1-(i*bolum);
		if(kalan == 0){
			carpan=carpan+i;
			}
		}
	return carpan;
	}
int main(){
int deger1,a,b;
	printf("Arkadasi bulunucak sayi giriniz.\n");
	scanf("%d",&deger1);
	a=carpantoplami(deger1);
	b=carpantoplami(a);
	if(b == deger1){
		printf("Arkadas sayisi:%d\n",a);
		}
	else{
		printf("Arkadas sayisi yoktur.\n");
		}
	return 0;
}
