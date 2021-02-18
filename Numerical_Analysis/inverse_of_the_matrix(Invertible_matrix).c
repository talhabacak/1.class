#include <stdio.h>

int main(){
	float a[10][10],c[10][10],b,bb;
	int i,j,k,N,s,t;
	
	printf("A kare matrisinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("A matrisinin %d. satir, %d. sutun elemanini giriniz\n",i,j);
			scanf("%f",&a[i][j]);
			
			if(i==j){
				c[i][j]=1;
			}
			else{
				c[i][j]=0;
			}
		}
	}
	
	for(i=1; i<=N; i++){
		
		b=a[i][i];
		for(j=1; j<=N; j++){
			a[i][j]=a[i][j]/b;
			c[i][j]/=b;	
		}
		
		t=i;
		for(k=1; k<N; k++){
			s=t%N+1;
			bb=a[s][i];
			for(j=1; j<=N; j++){
				a[s][j]-=(bb*a[i][j]);
				c[s][j]-=(bb*c[i][j]);
			
			}
			t++;
		}
	}
	
	printf("\nMatrisin Ýnversi :\n");
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("%f	",c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
