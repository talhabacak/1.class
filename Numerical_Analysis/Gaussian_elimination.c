#include <stdio.h>

int main(){
	int i,j,k,N,s,t;
	
	printf("A kare matrisinin boyutunu giriniz\n");
	scanf("%d",&N);
	float a[N+1][N+2],c[N+1],x[N+1],b,bb,X;
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("A matrisinin %d. satir, %d. sutun elemanini giriniz\n",i,j);
			scanf("%f",&a[i][j]);
		}
		printf("C matrisinin %d. satir elemanini giriniz\n",i);
		scanf("%f",&c[i]);
		x[i]=1;
	}
	
	for(i=1; i<=N; i++){
		b=a[i][i];
		for(j=1; j<=N; j++){
			a[i][j]=a[i][j]/b;
		}
		c[i]/=b;	
		for(k=i+1; k<=N; k++){
			bb=a[k][i];
			for(j=1; j<=N; j++){
				a[k][j]-=(bb*a[i][j]);
			}
			c[k]-=(bb*c[i]);
		}
	}
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("%f  ",a[i][j]);	
		}
		printf("%f \n",c[i]);
	}
	
	for(i=N; i>=1; i--){
		for(j=N; j>i; j--){
			c[i]-=a[i][j]*x[j];
		}
		x[i]=c[i]/a[i][i];
		printf("\nX%d: %f  ",i,x[i]);
	}
	
	return 0;
}
