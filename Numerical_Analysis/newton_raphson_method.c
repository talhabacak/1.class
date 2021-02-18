#include <stdio.h>
#include <math.h>

int main(){
	int i,j,d;
	
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	
	float k[d+2],X0,X1,Xe,y0,ye,x0,e,X,t,z;
	
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&k[i]);
	}
	
	printf("baslangic degerini giriniz\n");
	scanf("%f",&X0);
	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%f",&e);
	
	z=0;
	do{
		y0=0;
		t=0;
		for(i=d; i>0; i--){
			x0=1;
			for(j=1; j<=i; j++){
				x0=x0*X0;
			}
			y0=y0+k[i]*x0;
			t=t+i*k[i]*x0/X0;
		}
		y0=y0+k[0];
		
		if(z==0){
			X1=X0-(y0/t);	
		}
		else{
			X1=X0-(y0/(ye-y0)*(Xe-X0));	
		}
		z++;		
		/*
		printf("\nX1 = X0 - y0/y'0");
		printf("\n%f = %f - %f/%f",X1,X0,y0,t);
		*/
		X=X1-X0;
		Xe=X0;
		ye=y0;
		X0=X1;
		
		X=fabs(X);
		printf("\nXkok = %f",X1);
		
	}while(X>e);
	
	printf("\n\nXkoknet = %f",X1);
	
	return 0;
	
}
