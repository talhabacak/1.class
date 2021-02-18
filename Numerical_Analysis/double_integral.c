#include <stdio.h>

int main(){	
	int i,j,l,d,k,n,c1,c2,D,z;
	float a[100],b[100],C1[100],C2[100],X0,Xn,h,H,Ic,It,I1,s,S,t,y[100],y1[100],y2[100],g[100],sonuc[100];
	
	printf("X'li fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&a[i]);
	}
	
	printf("Y'li fonksiyonun derecesini giriniz\n");
	scanf("%d",&D);
	for(i=D; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&b[i]);
	}
	
	printf("ic integralin baslangic degerinin derecesini giriniz\n");
	scanf("%d",&c1);
	for(i=c1; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&C1[i]);
	}
	
	printf("ic integralin son degerinin derecesini giriniz\n");
	scanf("%d",&c2);
	for(i=c2; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&C2[i]);
	}
	
	printf("dis integralin baslangic degerini giriniz\n");
	scanf("%f",&X0);
	printf("dis integralin son degerini giriniz\n");
	scanf("%f",&Xn);
	printf("n degerini giriniz\n");
	scanf("%d",&n);
	
	h=(Xn-X0)/n;
	
	s=X0;
	for(k=0; k<=n; k++){
		y[k]=0;
		for(i=d; i>0; i--){
			t=1;
			for(j=1; j<=i; j++){
				t=t*s;
			}
			y[k]=y[k]+a[i]*t;
		}
		y[k]=y[k]+a[0];
		s=s+h;
	}
	s=X0;
	for(k=0; k<=n; k++){
		y1[k]=0;
		for(i=c1; i>0; i--){
			t=1;
			for(j=1; j<=i; j++){
				t=t*s;
			}
			y1[k]=y1[k]+C1[i]*t;
		}
		y1[k]=y1[k]+C1[0];
		s=s+h;
	}
	s=X0;
	for(k=0; k<=n; k++){
		y2[k]=0;
		for(i=c2; i>0; i--){
			t=1;
			for(j=1; j<=i; j++){
				t=t*s;
			}
			y2[k]=y2[k]+C2[i]*t;
		}
		y2[k]=y2[k]+C2[0];
		s=s+h;
	}
	
	for(z=0; z<=n; z++){
		sonuc[z]=0;
		H=(y2[z]-y1[z])/n;
		s=y1[z];
		for(k=0; k<=n; k++){
			g[k]=0;
			for(i=D; i>0; i--){
				t=1;
				for(j=1; j<=i; j++){
					t=t*s;
				}
				g[k]=g[k]+b[i]*t;
			}
			g[k]=g[k]+b[0]+y[z];
			s=s+H;
		}
		I1=g[0]+g[n];
		
		Ic=0;
		It=0;
		for(i=1; i<n; i++){
			if(i%2==0){
				Ic+=g[i];
			}
			else{
				It+=g[i];
			}
		}
		Ic=2*Ic;
		It=4*It;
		S=(H/3)*(I1+Ic+It);
		sonuc[z]=S;
	}
	
	Ic=0;
	It=0;
	for(i=1; i<n; i++){
		if(i%2==0){
			Ic+=sonuc[i];
		}
		else{
			It+=sonuc[i];
		}
	}
	I1=sonuc[0]+sonuc[n];
	Ic=2*Ic;
	It=4*It;
	S=(h/3)*(I1+Ic+It);
		
	printf("\n\nS: %f",S);
		
	return 0;
}
