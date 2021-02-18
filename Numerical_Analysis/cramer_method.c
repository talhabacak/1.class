#include <stdio.h>

float det(float a[][10],int N){
	
	float d,dt,dt1=0,dt2=0;
	int i,j,k;
		
	if(N==3){
		for(i=0; i<N; i++){
		
			d=1;
			k=i;
			for(j=0; j<N; j++){
				d=d*a[k][j];
				k++;
			}
			dt1+=d;
		}
		
		for(i=N-1; i>=0; i--){
			
			d=1;
			k=i;
			for(j=N-1; j>=0; j--){
				d=d*a[k][j];
				k++;
			}
			dt2+=d;
		}
		
		dt=dt1-dt2;
	}
	
	else if(N==2){
		dt=a[0][0]*a[1][1]-a[0][1]*a[1][0];
	}
	
	return dt;
}


int main(){
	float a[10][10],b[10][10],c[10],x[10],A;
	int i,j,k,N;
	
	printf("A kare matrisinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("A matrisinin %d. satir, %d. sutun elemanini giriniz\n",i,j);
			scanf("%f",&a[i][j]);
			b[i][j]=a[i][j];
			a[i+N][j]=a[i][j];;
		}
		printf("C matrisinin %d. satir elemanini giriniz\n",i);
		scanf("%f",&c[i]);
	}
	
	A=det(a,N);
	
	for(k=1; k<=N; k++){
		
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				a[i][j]=b[i][j];
			}
		}
		
		for(j=1; j<=N; j++){
			a[j][k]=c[j];
		}
		
		for(i=1; i<=N; i++){	
			for(j=1; j<=N; j++){
				a[i+N][j]=a[i][j];
			}
		}
		
		x[k]=det(a,N)/A;
		
		printf("%f  \n",x[k]);
	}
	
	return 0;
}
