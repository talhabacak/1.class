#include <stdio.h>

int main(){	
	int i,j,l,d,k,n;

	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);	
	
	float a[100],X0,Xn,h,Ic,It,I1,b,S,t,y[100];
		
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&a[i]);
	}
	
	printf("baslangic degerini giriniz\n");
	scanf("%f",&X0);
	printf("son degerini giriniz\n");
	scanf("%f",&Xn);
	printf("n degerini giriniz\n");
	scanf("%d",&n);
	
	
	h=(Xn-X0)/n;
	b=X0;
	for(k=0; k<=n; k++){
		y[k]=0;
		for(i=d; i>0; i--){
			t=1;
			for(j=1; j<=i; j++){
				t=t*b;
			}
			y[k]=y[k]+a[i]*t;
		}
		y[k]=y[k]+a[0];
		b=b+h;
		printf("\ny%d: %f",k,y[k]);
	}
	
	I1=y[0]+y[n];

	Ic=0;
	It=0;
	for(i=1; i<n; i++){
		if(i%2==0){
			Ic+=y[i];
		}
		else{
			It+=y[i];
		}
	}
	Ic=2*Ic;
	It=4*It;
	
	S=(h/3)*(I1+Ic+It);
	
	printf("\n\nS: %f",S);
	
	return 0;
}
