#include <stdio.h>

int main(){
	
	int i,j,k,d;
	float F,xi[100],yi[100],f[100],x;
	
	printf("gireceginiz xi sayisinin adedini giriniz\n");
	scanf("%d",&d);
	
	for(i=0; i<d; i++){
		printf("xi'nin %d. degerini giriniz\n",i);
		scanf("%f",&xi[i]);
		printf("yi'nin %d. degerini giriniz\n",i);
		scanf("%f",&yi[i]);
	}
	
	printf("\nx'i giriniz\n");
	scanf("%f",&x);
	
	F=0;
	for(i=0; i<d; i++){
	
		k=i+1;
		f[i]=yi[i];
	
		for(j=1; j<d; j++){
			f[i]*=(x-xi[k])/(xi[i]-xi[k]);
			k++;
			k=k%d;
		}
		
		F+=f[i];
	}
	
	printf("\nF(%f) = %f",x,F);
	
	return 0;
}
