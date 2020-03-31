#include <stdio.h>
double factorial(int n){
	double j=1;
	for(int i=1; i<=n; i++){
	j=i*j;
	}
	return j;
}
double powa(double x,int n){
	double j=1;
	for(int i=1; i<=n; i++){
	j=x*j;
	
	}
	return j;
}
double sina(double x){
	double bolme;
	double sonuc=0;
	for(int n=0; n<=6; n++){
	bolme=powa(x,2*n+1)*powa((-1),n)/factorial(2*n+1);
	sonuc=bolme+sonuc;
	}
	return sonuc;
}
int main(){
	int derece;
	double radyan,sonuc;
	printf("Sinusu hesaplanacak aci giriniz.\n");
	scanf("%d",&derece);
	radyan=derece*3.1415926535/180.0;
	sonuc=sina(radyan);
	printf("Sonuc=%lf\n",sonuc);
}
