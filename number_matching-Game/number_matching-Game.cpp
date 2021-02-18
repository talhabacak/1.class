#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	char ch[15],ch1[6]=".txt";
	int a[15][15],b[100][15][15],c1[50],c2[100],d1[100],d2[100],A[100],I,J,M,N,i,j,k,k1,k2,K1,K2,l,s,tus,c,z,t,h,w,W,E,Z=0,HIGHSCORE=0,bilgi;

	FILE *fp;
	fp=fopen("HIGHSCORE.txt","r");
	fscanf(fp, "%d",&bilgi);
	HIGHSCORE=bilgi;
	
	z=0;
	tus='x';
	do{
		
		if(tus=='x' || tus=='X'){
			do{
				printf("\n\nLutfen oyunun boyutunu ([5,11] arasi) giriniz\n");
				scanf("%d",&N);
			}while(N<5 || N>11);
			for(i=1; i<=15; i++){
				for(j=1; j<=15; j++){
					a[i][j]=0;
				}
			}	
			
			h=rand()%5;
			M=N*2;
			sprintf(ch,"%d.%d%s",N,h,ch1);
			FILE *fp;
			fp=fopen(ch,"r");
			
			for(i=0; i<=M-1; i++){
				fscanf(fp, "%d %d",&I,&J);
				fscanf(fp, "%d",&a[I][J]);
				d1[i+1]=I;
				d2[i+1]=J;
				c1[i+1]=I;
				c2[i+1]=J;
			}	
			fclose(fp);
			w=0;
		}
		w=0;
		j=0;
		for(i=1; i<=M+2; i=i+2){
			A[0]=0;
			A[1]=0;
			c1[i]=d1[i];
			c2[i]=d2[i];
			E=5;
			do{
				j++;
				while(a[c1[i]][c2[i]]==a[c1[i]+1][c2[i]] && E!=3){
					c1[i]++;
					E=1;
					A[j]++;
				}
				while(a[c1[i]][c2[i]]==a[c1[i]][c2[i]+1] && E!=4){
					c2[i]++;
					E=2;
					A[j]++;
				}
				while(a[c1[i]][c2[i]]==a[c1[i]-1][c2[i]] && E!=1){
					c1[i]--;
					A[j]++;
					E=3;
				}
				while(a[c1[i]][c2[i]]==a[c1[i]][c2[i]-1] && E!=2){
					c2[i]--;
					A[j]++;
					E=4;
				}
			}while(A[j]>A[j-1]);
			if(c1[i]==d1[i+1] && c2[i]==d2[i+1]){
				w++;
			}
		}
			
		z++;
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				b[z][i][j]=a[i][j];
			}
		}
		
		system("cls");
		W=0;
		
		printf("\n\nSAYI ESLESTIRME\n\n");
		printf("Hic bir yer bos olmayacak sekilde sayilari eslestiriniz\n\n");
		for(i=1; i<=N; i++){
			printf("   %d   ",i);
		}
		printf("\n");
		for(i=1; i<=N; i++){
			printf(" ______");
		}
		printf("\n");
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				printf("|");
				if(a[i][j]!=0){
					W++;
					c=(a[i][j]*a[i][j]+57)%256;
					printf("\033[38;5;%d;48;5;m",c);
					printf(" %-4d ",a[i][j]);
					printf("\033[0m");
				}
				else{
					printf("      ");
				}
			}
			printf("| %d   \n",i);
			for(k=1; k<=N; k++){
				printf("|______");
			}
			printf("|\n");
		}
		if(w>=N && W>=N*N){
			Z=N*N*N*N/z;
			printf("\n\n        YOU WIN\n\n");
			if(HIGHSCORE<=Z){
				HIGHSCORE=Z;
			}
			printf("\n\nSCORE: %d	-	HIGHSCORE: %d\n\n",Z,HIGHSCORE);
		}
		if(w<N && W>=N*N){
			printf("\n\n        YOU LOSE\n\n");
		}
		else{
			printf("\nKoordinatlari girmek icin 'K'ya, ");
		}
		printf("Cikmak icin 'E'ye, geri gelmek icin 'R'ye, restart icin 'X'e basiniz");
		tus=getch();
		
		if(tus=='k' || tus=='K'){
			
			printf("\nLutfen baslangic koordinatinin satirini giriniz\n");
			scanf("%d",&k1);
			printf("\nLutfen baslangic koordinatinin sutununu giriniz\n");
			scanf("%d",&k2);
			printf("\nLutfen varis koordinatinin satirini giriniz\n");
			scanf("%d",&K1);
			printf("\nLutfen varis koordinatinin sutununu giriniz\n");
			scanf("%d",&K2);
			
			l=0;
			s=0;
			
			if(k1==K1){
				if(K2>k2){
					for(i=k2; i<=K2; i++){
						if(l>1){
							s++;
						}
						if(a[k1][i]!=0 && a[k1][i]!=a[k1][k2]){
							s++;
						}
						if(a[k1][i]==a[k1][k2]){
							l++;
						}
					}
				}
				if(k2>K2){
					for(i=K2; i<=k2; i++){
						if(l>1){
							s++;
						}
						if(a[k1][i]!=0 && a[k1][i]!=a[k1][k2]){
							s++;
						}
						if(a[k1][i]==a[k1][k2]){
							l++;
						}
					}
				}
			}
			
			else if(k2==K2){
				if(K1>k1){
					for(i=k1; i<=K1; i++){
						if(l>1){
							s++;
						}
						if(a[i][k2]!=0 && a[i][k2]!=a[k1][k2]){
							s++;
						}
						if(a[i][k2]==a[k1][k2]){
							l++;
						}
					}
				}
				if(k1>K1){
					for(i=K1; i<=k1; i++){
						if(l>1){
							s++;
						}
						if(a[i][k2]!=0 && a[i][k2]!=a[k1][k2]){
							s++;
						}
						if(a[i][k2]==a[k1][k2]){
							l++;
						}
					}
				}
			}
			
			if(s==0){
				if(k1==K1){
					if(K2>k2){
						for(i=k2; i<=K2; i++){
							a[k1][i]=a[k1][k2];
						}
					}
					if(k2>K2){
						for(i=K2; i<=k2; i++){
							a[k1][i]=a[k1][k2];
						}
					}
				}
				else if(k2==K2){
					if(K1>k1){
						for(i=k1; i<=K1; i++){
							a[i][k2]=a[k1][k2];		
						}
					}
					if(k1>K1){
						for(i=K1; i<=k1; i++){
							a[i][k2]=a[k1][k2];
						}
					}
				}
			}
		}
		
		if(tus=='r' || tus=='R'){
			for(i=1; i<=N; i++){
				for(j=1; j<=N; j++){
					a[i][j]=b[z-1][i][j];
				}
			}
		}
		
		fp=fopen("HIGHSCORE.txt","r");
		fscanf(fp, "%d",&bilgi);
		
		if(HIGHSCORE>bilgi){
			bilgi=HIGHSCORE;
			FILE *fp=fopen("HIGHSCORE.txt","w");
			fprintf(fp,"%d\n",bilgi);	
		}
		fclose(fp);
	
	}while(tus!='e' && tus!='E');	
	
	return 0;
}

