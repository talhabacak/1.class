#include <stdio.h>
#include <math.h>

int main(){
	int i,j,d,s,z;
	
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	
	float k[d+2],X0,X1,X2,y0,y1,y2,x0,x1,x2,e,X,Xd,Xs1,Xs2;
	
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&k[i]);
	}
	
	printf("X0 degerini giriniz\n");
	scanf("%f",&X0);
	printf("X1 degerini giriniz\n");
	scanf("%f",&X1);
	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%f",&e);
	
	X=100000; 
	
	do{
		s=0;
		z=0;
		y0=0;
		y1=0;
		for(i=d; i>=1; i--){
			x0=1;
			x1=1;
			for(j=1; j<=i; j++){
				x0=x0*X0;
				x1=x1*X1;
			}
			y0=y0+x0*k[i];
			y1=y1+x1*k[i];
		}
		y0=y0+k[0];	// result of the function with respect to X0
		y1=y1+k[0];	// result of the function with respect to X0
		X2=X0-((X1-X0)/(y1-y0))*y0;	//The formula for the secant method
		
		if(y0*y1==0){	// checking whether there are endpoints
			if(y0==0){
				y2=y0;
				X2=X0;
				z=1;
			}
			if(y1==0){
				y2=y1;
				if(z==1){
					printf("\nXkok2 = %f",X1);
				}
				else{
					X2=X1;
				}
			}
		}
		else if(y0*y1<0){	// Checking for root in range
			y2=0;
			for(i=d; i>=1; i--){
				x2=1;
				for(j=1; j<=i; j++){
					x2=x2*X2;
				}
				y2=y2+x2*k[i];
			}
			y2=y2+k[0];	// result of the function with respect to X0
			
			if(y0*y2<0){	// We determine which interval to look at
				X1=X2;
			}
			else if(y1*y2<0){	// We determine which interval to look at
				X0=X2;
			}
			else{
				if(y0*y2==0){
					if(y0==0){
						y2=y0;
						X2=X0;
					}
				}
				else if(y1*y2==0){
					if(y1==0){
						y2=y1;
						X2=X1;
					}
				}
			}
		}
		else if((y0*y1)>0){	// We check if there is root in this range
			Xd=100000;
			printf("\nBu aralikta kok yok, a ve b degerlerini tekrar giriniz");
			printf("\nX0 degerini giriniz\n");
			scanf("%f",&X0);
			printf("X1 degerini giriniz\n");
			scanf("%f",&X1);
		}
				
		if(X0==Xd){	// Since we keep X0 constant as long as it changes, we throw the changed X1 to X0 when it does not change.
			Xs1=X0;
			Xs2=X1;
			X1=Xs1;
			X0=Xs2;
		}
		
		X=X0-Xd;	// we get the difference of your roots
		Xd=X0;	//We save X0 in Xd to compare it to X0 in the previous round
		
		printf("\nXkok = %f",X2);
		
		X=fabs(X);	// save the absolute value
	}while(X>e);	// epsilon control 
	
	printf("\n\nXkoknet = %f",X2);
	
	return 0;
}
