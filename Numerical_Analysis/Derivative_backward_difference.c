#include <stdio.h>

int main(){	
	int i,j,d,n;

	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);	
	
	float a[100],X1,X2,t1,t2,f1,f2,dx,turev;
		
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&a[i]);
	}
	
	printf("X degerini giriniz\n");
	scanf("%f",&X1);
	printf("delta X degerini giriniz\n");
	scanf("%f",&dx);
	
	X2=X1-dx;
	f1=0;
	f2=0;
	for(i=d; i>0; i--){
		t1=1;
		t2=1;
		for(j=1; j<=i; j++){
			t1=t1*X1;
			t2=t2*X2;
		}
		f1=f1+a[i]*t1;
		f2=f2+a[i]*t2;
	}
	f1=f1+a[0];
	f2=f2+a[0];
	
	turev=(f1-f2)/dx;
	printf("\nturev: %f",turev);

	return 0;
}
