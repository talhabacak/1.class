#include <stdio.h>
#include <math.h>

int main(){
	int i,j,d,s,z;
	
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	
	float k[d+2],a,b,c,fa,fb,fc,xa,xb,xc,e;
	
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&k[i]);
	}
	
	printf("a degerini giriniz\n");
	scanf("%f",&a);
	printf("b degerini giriniz\n");
	scanf("%f",&b);
	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%f",&e);
	
	do{
		s=0;
		z=0;
		fa=0;
		fb=0;
		for(i=d; i>=1; i--){
			xa=1;
			xb=1;
			for(j=1; j<=i; j++){
				xa=xa*a;
				xb=xb*b;
			}
			fa=fa+xa*k[i];
			fb=fb+xb*k[i];
		}
		fa=fa+k[0];
		fb=fb+k[0];
		c=(a+b)/2;
		
		if(fa*fb==0){
			if(fa==0){
				fc=fa;
				c=a;
				z=1;
			}
			if(fb==0){
				fc=fb;
				if(z==1){
					printf("\nXkok2 = %f",b);
				}
				else{
					c=b;
				}
			}
		}
		else if(fa*fb<0){
			fc=0;
			for(i=d; i>=1; i--){
				xc=1;
				for(j=1; j<=i; j++){
					xc=xc*c;
				}
				fc=fc+xc*k[i];
			}
			fc=fc+k[0];
			if(fa*fc<0){
				b=c;
			}
			else if(fb*fc<0){
				a=c;
			}
			else{
				if(fa*fc==0){
					if(fa==0){
						fc=fa;
						c=a;
					}
				}
				else if(fb*fc==0){
					if(fb==0){
						fc=fb;
						c=b;
					}
				}
			}
		}
		else if(fa*fb>0){
			s=1;
			printf("\nBu aralikta kok yok, a ve b degerlerini tekrar giriniz");
			printf("a degerini giriniz\n");
			scanf("%f",&a);
			printf("b degerini giriniz\n");
			scanf("%f",&b);
		}
		
		printf("\nXkok = %f",c);
		
		fc=fabs(fc);
	}while(fc>e || s==1);
	
	printf("\n\nXkok = %f",c);
	
	return 0;
}
