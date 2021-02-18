#include <stdio.h>

void invers(int N,float a[][10],float d[]){
	
	float c[10][10],x[10],b,bb;
	int i,j,k,s,t;

	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
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
	
	for(i=1;  i<=N; i++){
		t=0;
		for(j=1; j<=N; j++){
			t+=c[i][j]*d[j];
			printf("%f  ",c[i][j]);
		}
		x[i]=t;
		printf("			X%d : %f\n",i,x[i]);
	}
}

void gausjordan(int N,float a[][10],float c[]){
	
	int i,j,k;
	float b,bb,bbb,x[10],t;
	
	for(i=1; i<=N; i++){
		x[i]=1;
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
	
	for(i=N; i>1; i--){
		for(j=i-1; j>=1; j--){
			bbb=a[j][i];
			a[j][i]-=a[j][i]*a[i][i];
			c[j]-=bbb*c[i];
		}
	}
	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			printf("%f  ",a[i][j]);	
		}
		printf("			%f \n",c[i]);
	}
	
	for(i=N; i>=1; i--){
		for(j=N; j>i; j--){
			c[i]-=a[i][j]*x[j];
		}
		x[i]=c[i]/a[i][i];
		printf("\nX%d: %f  ",i,x[i]);
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
	
	int i,j,k,d,m;
	float xi[10],yi[10],A[10][10],B[10],x;
	
	printf("gireceginiz xi sayisinin adedini giriniz\n");
	scanf("%d",&d);
	
	for(i=1; i<=d; i++){
		printf("xi'nin %d. degerini giriniz\n",i);
		scanf("%f",&xi[i]);
		printf("yi'nin %d. degerini giriniz\n",i);
		scanf("%f",&yi[i]);
	}
	
	printf("fonksiyonun kacinci dereceden oldugunu giriniz\n");
	scanf("%d",&m);
	
	for(i=1; i<=m+1; i++){
		for(j=1; j<=m+1; j++){
			A[i][j]=0;
			for(k=1; k<=d; k++){
				A[i][j]+=ust(xi[k],i+j-2);;
			}
			printf("%f	",A[i][j]);
		}
		
		B[i]=0;
		for(j=1; j<=d; j++){
			B[i]+=yi[j]*ust(xi[j],i-1);
		}
		printf("		%f\n",B[i]);
	}
	
	A[1][1]=d;
	
	if(m>1){
		gausjordan(m+1,A,B);
	}
	else if(m==1){
		invers(m+1,A,B);
	}
	
	return 0;
}
