#include <stdio.h>

int fact(int n){
	
	if(n==1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}

float ust(float x, int n){
	
	if(n==0){
		return 1;
	}
	else if(n>0){
		return x*ust(x,n-1);
	}
	else{
		return 1.0/x*ust(x,n-1);
	}
}

int main(){
	int i,j,indis=0,derece,esitlik,m;
	float k[100],fdelta[100][100],fbaslangic,fbitis,baslangic,h,b,c,x,xi[100],f,F;
	
	printf("fonksiyonun baslangic araligini giriniz\n");
	scanf("%f",&fbaslangic);
	printf("fonksiyonun bitis araligini giriniz\n");
	scanf("%f",&fbitis);
	printf("fonksiyonun h degerini giriniz\n");
	scanf("%f",&h);
	
	baslangic=fbaslangic;
	while(baslangic<=fbitis){
		indis++;
		xi[indis]=baslangic;
		printf("f(%f) fonksiyonunu giriniz\n",fbaslangic);
		scanf("%f",&fdelta[0][indis]);
		
		baslangic+=h;
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
	
	printf("\nx degeri giriniz\n");
	scanf("%f",&x);
	
	i=1;
	F=fdelta[0][1];
	while(i<=j){
		f=0;
		f+=fdelta[i][1];
		f/=fact(i)*ust(h,i);
		m=0;
		while(m<i){
			f*=x-xi[m+1];
			m++;
		}
		F+=f;
		i++;
		
		printf("\nF(x) = %f",F);
	}
	
	printf("\nF(x)sonuc = %f",F);
	
	return 0;
}
