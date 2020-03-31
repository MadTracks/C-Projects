#include <stdio.h>
int main(){
int komut,n,i,j,k,l,m;
	printf("---MENU---\n");
	printf("1.Yildizlardan elmas ciz\n");
	printf("2.Ekrana yazi yaz.\n");
	printf("0.Cikis\n");
	printf("Sececeginiz:");
	scanf("%d",&komut);
	if(komut == 1)
		{
		printf("Elmas icin yukseklik giriniz:");
		scanf("%d",&n);
		i=1;
		while(i<=n)
			{
			j=1;
			k=2*i-1;
			while(j<=k)
				{
				l=1;
				m=((n+1)/2)-i;
				while(l<=m)
					{
					printf(" ");
					l++;
					}
				if(k == n)
					{
					while(i<=n)
						{
						j=1;
						k=2*n-2*i+1;
						while(j<=k)
							{
							l=1;
							m=i-((n+1)/2);
							while(l<=m)
								{
								printf(" ");
								l++;
								}
							printf("*");
							j++;
							}
						printf("\n");
						i++;
						}
					return 0;
					}
				printf("*");
				j++;
				}
			printf("\n");
			i++;
			}
		}
	else if(komut == 2)
		{
		printf("Hello World!\n");
		}
	else if(komut == 0)
	return 0;
}
