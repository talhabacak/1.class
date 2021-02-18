#include <stdio.h>

int main(){
	int i,j,indis=0,derece,esitlik;
	float k[100],fdelta[100][100],fbaslangic,fbitis,h,b,c;
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&derece);
	
	for(i=derece; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%f",&k[i]);
	}
	
	printf("fonksiyonun baslangic araligini giriniz\n");
	scanf("%f",&fbaslangic);
	printf("fonksiyonun bitis araligini giriniz\n");
	scanf("%f",&fbitis);
	printf("fonksiyonun h degerini giriniz\n");
	scanf("%f",&h);
	
	while(fbaslangic<=fbitis){
		indis++;
		b=0;
		for(i=derece+1; i>=1; i--){
			c=1;
			for(j=1; j<=i; j++){
				c=c*fbaslangic;
			}
			b=b+c*k[i];
		}
		fdelta[0][indis]=b+k[0];
		fbaslangic+=h;
		printf("%f\n",fdelta[0][indis]);
	}
	
	j=0;
	while(indis!=0 && (indis-1)!=esitlik){
		j++;
		esitlik=0;
		for(i=indis; i>1; i--){
			fdelta[j][i-1]=fdelta[j-1][i]-fdelta[j-1][i-1];
			if(fdelta[j][i]==fdelta[j][i-1]){
				esitlik++;
			}
			printf("%d. turev %d. sira ve degeri %f \n",j,i-1,fdelta[j][i-1]);
		}
		indis--;
		
		printf("\n%d. turev degeri %f \n\n",j,fdelta[j][1]);
	}
		
	return 0;
}
