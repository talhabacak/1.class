#include <stdio.h>

int main(){
	int i,j,l,d;
	
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	
	float k[d+2],a,p,b,e,c,f[100];
	
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&k[i]);
	}
	
	printf("baslangic degerini giriniz\n");
	scanf("%f",&a);
	printf("artis miktarini giriniz\n");
	scanf("%f",&p);
	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%f",&e);
	
	a=a-p;
	p=2*p;
	
	while(e<=p && f[l]!=0){
		l++;
		if(f[l-2]<0 && f[l-1]>0){
			a=a-p;
			p=p/2;
		}
		if(f[l-2]>0 && f[l-1]<0){
			a=a-p;
			p=p/2;
		}
		if(f[l-1]==0){
			p=0;
		}

		a=a+p;
		b=0;
		for(i=d+1; i>=1; i--){
			c=1;
			for(j=1; j<=i; j++){
				c=c*a;
			}
			b=b+c*k[i];
		}
		f[l]=b+k[0];
		printf("\nXkok = %f",a);
	}
	
	printf("\n\nXkoknet = %f",a);
	
	return 0;
}
