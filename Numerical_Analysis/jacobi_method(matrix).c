#include <stdio.h>
#include <math.h>

int main(){
	int i,j,k,N,c,h,m;
	
	printf("A kare matrisinin boyutunu giriniz\n");
	scanf("%d",&N);
	float a[N+1][N+2],x[N+1],y[N+1],b,min,s[N+1],t,e,m1,m2,c1,c2,max;
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("A matrisinin %d. satir, %d. sutun elemanini giriniz\n",i,j);
			scanf("%f",&a[i][j]);
		}
		printf("C matrisinin %d. satir elemanini giriniz\n",i);
		scanf("%f",&a[i][N+1]);
		y[i]=0;
	}

	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%f",&e);
	
	m=0;
	do{
		m++;
		for(j=m; j<=N; j++){
			for(i=j; i<=N; i++){
				m1=fabs(a[j][m]);
				m2=fabs(a[i][m]);
				if(m1<m2){
					for(k=1; k<=N+1; k++){
						b=a[j][k];
						a[j][k]=a[i][k];
						a[i][k]=b;
					}
				}
			}
		}
		c1=(a[m+1][m+1]);
		c2=fabs(a[m+2][m+1]);
	}while(c1==c2);
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N+1; j++){
			printf("%f  ",a[i][j]);	
		}
		printf("\n  ");
	}
	
	s[1]=100000;
	do{
		for(i=1; i<=N; i++){
			t=0;
			h=i;
			for(j=1; j<N; j++){
				c=h%N+1;
				t+=a[i][c]*y[c];
				h++;
			}
			x[i]=(a[i][N+1]-t)/a[i][i];
			printf("%f  ",x[i]);
		}
		printf("\n");
		min=x[1]-s[1];
		min=fabs(min);
		for(i=1; i<=N; i++){
			max=x[i]-s[i];
			max=fabs(max);
			if(min<max){
				min=max;
			}
			y[i]=x[i];
			s[i]=x[i];
		}
		min=fabs(min);
	}while(e<min);
	
	for(i=1; i<=N; i++){
		printf("\n%f  ",x[i]);	
	}

	return 0;
}
