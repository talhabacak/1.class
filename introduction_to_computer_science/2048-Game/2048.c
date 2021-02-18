#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <dos.h>

int a[5][5]={
	    {0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	g[20000][5][5];
	
void baslangic(){
	int i1,i2,j1,j2;
	srand(time(NULL));
	
	//random determines the location of the initial 2
	i1=rand()%4;
	j1=rand()%4;
	a[i1][j1]=2;
	//2. finds 2 in a way that does not contradict the first
	do{
		i2=rand()%4;
		j2=rand()%4;
		if(a[i2][j2]==0){
			a[i2][j2]=2;
		}
	}while(i1==i2 && j1==j2);
}

void display0(){
	int i,j;
	
	printf("\n\n              - 2 0 4 8 - \n");
	printf(" _______________________________________\n");
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					if(a[i][j]!=0){
						printf("|  %-5d  ",a[i][j]);
					}
					else{
						printf("|         ");
					}	
				}
				printf("|\n|_________|_________|_________|_________|\n");
			}
	printf("Oyundan cikmak icin E'ye, bastan baslamak icin X'e, bir onceki adima gitmek icin R'ye basiniz\n");
	printf("Yon ok tuslarini kullaniniz\nYapmak istediginiz islemi seciniz\n");	
}

void display(int r, int r1,int r2 ,int SCORE, int HIGHSCORE){
	int i,j,c;

	printf("\n\nSCORE: %d  -   HIGHEST SCORE: %d  \n _______________________________________\n",SCORE,HIGHSCORE);
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(i==r1 && j==r2 && r==2){
				printf("|  %-5d* ",a[i][j]);
			}
			else{
				if(a[i][j]!=0){
					printf("|");
					c=((a[i][j]%11)*a[i][j]+32)%250;
					printf("\033[38;5;%d;48;5;m",c);
					printf("  %-5d  ",a[i][j]);
					printf("\033[0m");
				}
				else{
					printf("|         ");
				}					
			}
		}
		printf("|\n|_________|_________|_________|_________|\n");
	}	
	printf("Oyundan cikmak icin E'ye, bastan baslamak icin X'e, bir onceki adima gitmek icin R'ye basiniz\n");
    printf("Yon ok tuslarini kullaniniz\nYapmak istediginiz islemi seciniz\n");
}

void restart(){
	int i,j;
	//resetting elements
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			a[i][j]=0;
		}
	}
	baslangic();
}

void random(int r,int r1, int r2, int h, int n){

	while(r==1 && h<16){
		r1=rand()%4;
		r2=rand()%4;
		n=rand()%8;
		if(a[r1][r2]==0){
	        r++;
			if(n==1){
	        	a[r1][r2]=4;
			}
			else{
	    	    a[r1][r2]=2;
	    	}
		}
	}
}

int same(int h, int z){
	int i,j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(a[i][j]==g[z-1][i][j]){
				h++;
			}
		}
	}
	return h;
}

void kaydirma(int i, int j, int yon1, int yon2, int yon3, int yon4, int k){
	int yer,temp1,temp2;
	int o=1;
	
	if(yon3==0 || yon4==0){
		o=-1;
	}
	
	while(k<4 && a[i][j]==0){
		yer=a[i][j];
		if(a[i+1*yon1][j+1*yon2]!=0){
			temp1=i+1*yon1;
			temp2=j+1*yon2;
			if((temp1*o)<=yon3 && (temp2*o)<=yon4){	
				a[i][j]=a[i+1*yon1][j+1*yon2];
				a[i+1*yon1][j+1*yon2]=yer;
			}
		}
		else if(a[i+2*yon1][j+2*yon2]!=0){
			temp1=i+2*yon1;
			temp2=j+2*yon2;
			if((temp1*o)<=yon3 && (temp2*o)<=yon4){	
				a[i][j]=a[i+2*yon1][j+2*yon2];
				a[i+2*yon1][j+2*yon2]=yer;
			}
		}
		else if(a[i+3*yon1][j+3*yon2]!=0){
			temp1=i+3*yon1;
			temp2=j+3*yon2;
			if((temp1*o)<=yon3 && (temp2*o)<=yon4){	
				a[i][j]=a[i+3*yon1][j+3*yon2];
				a[i+3*yon1][j+3*yon2]=yer;
			}
		}
		k=k+1;
	}
	k=0;	
}

int puan(int i, int j, int yon1, int yon2, int SCORE){
	if(a[i][j]==a[i+yon1][j+yon2]){
		a[i][j]+=a[i+yon1][j+yon2];
		a[i+yon1][j+yon2]=0;
		SCORE=SCORE+a[i][j];
	}
	return SCORE;
}

int main(){
		
	int S[10000],m,h,n,r1,r2,i1,i2,j1,j2,i,j,k,yer,bilgi,c;
	
	int z=1,
		win=0,
		SCORE=0,
		HIGHSCORE=0,
		r=1,
		l=1;
	
	char tus;
	
	FILE *fp;
	
	fp=fopen("dosya.txt","r");
	fscanf(fp, "%d",&bilgi);
	HIGHSCORE=bilgi;	
	
	baslangic();
	display0();
		
	do{		
		//We will store each step in a 3rd dimension and get the information from here when we go to the previous step
		z++;	//variable with which we specify each step
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				g[z][i][j]=a[i][j];		
			}
		}
		
		tus=getch();
		system("cls");	//screen cleaning
		
    	/* restart  */
		if(tus=='X' || tus=='x' ){
			SCORE=0;
			win=0;
			restart();
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		k=0;
		
		//move up
		if(tus==72){
			//scrolling
			for(j=0; j<4; j++){
				for(i=0; i<4; i++){
					kaydirma(i,j,1,0,3,10,k);
				}
			}
			//adding and calculating score
			for(j=0; j<4; j++){
				for(i=0; i<3; i++){
					SCORE=puan(i, j, 1, 0, SCORE);
				}
			}
			//applying the swipe again
			for(j=0; j<4; j++){
				for(i=0; i<4; i++){
					kaydirma(i,j,1,0,3,10,k);
				}
			}
			//finds similarities with the previous step
			h=same(h,z);
			//determines the random number and location to assign
			random(r, r1, r2, h, n);
		
			if(HIGHSCORE<=SCORE){
				HIGHSCORE=SCORE;
			}
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		k=0;
		
		//move down
		if(tus==80){
			//scrolling
			for(j=3; j>=0; j--){
				for(i=3; i>=0; i--){
					kaydirma(i,j,-1,0,0,10,k);
				}
			}
			//adding and calculating score
			for(j=3; j>=0; j--){
				for(i=3; i>0; i--){
					SCORE=puan(i, j, -1, 0, SCORE);
				}
			}
			//applying the swipe again
			for(j=3; j>=0; j--){
				for(i=3; i>=0; i--){
					kaydirma(i,j,-1,0,0,10,k);
				}
			}
			//finds similarities with the previous step
			h=same(h,z);
			//determines the random number and location to assign
			random(r, r1, r2, h, n);
		
			if(HIGHSCORE<=SCORE){
				HIGHSCORE=SCORE;
			}
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		k=0;
		
		//move right
		if(tus==77){
			//scrolling
			for(i=3; i>=0; i--){
				for(j=3; j>=0; j--){
					kaydirma(i,j,0,-1,10,0,k);
				}
			}
			//adding and calculating score
			for(i=3; i>=0; i--){
				for(j=3; j>0; j--){
					SCORE=puan(i, j, 0, -1, SCORE);
				}
			}
			//applying the swipe again
			for(i=3; i>=0; i--){
				for(j=3; j>=0; j--){
					kaydirma(i,j,0,-1,10,0,k);
				}
			}
			//finds similarities with the previous step
			h=same(h,z);
			//determines the random number and location to assign
			random(r, r1, r2, h, n);
		
			if(HIGHSCORE<=SCORE){
				HIGHSCORE=SCORE;
			}
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		k=0;
		
		//move left
		if(tus==75){
			//scrolling
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					kaydirma(i,j,0,1,10,3,k);
				}
			}
			//adding and calculating score
			for(i=0; i<4; i++){
				for(j=0; j<3; j++){
					SCORE=puan(i, j, 0, 1, SCORE);
				}
			}
			//applying the swipe again
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					kaydirma(i,j,0,1,10,3,k);
				}
			}
			//finds similarities with the previous step
			h=same(h,z);
			//determines the random number and location to assign
			random(r, r1, r2, h, n);
			
			if(HIGHSCORE<=SCORE){
				HIGHSCORE=SCORE;
			}
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		
		//turn back
		if(tus=='r' || tus=='R'){
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					a[i][j]=g[z-1][i][j];			
				}
			}
			SCORE=S[z-2];	//previous score is determined as new score
			if(HIGHSCORE<=SCORE){
				HIGHSCORE=SCORE;
			}
			display(r,r1,r2,SCORE,HIGHSCORE);
		}
		
		S[z]=SCORE;	//Allows us to find the previous step by keeping the points in order
		r=1;
		h=0;
		m=0;
		
		l=1;
		//It reaches 2048 and scans all elements and checks empty elements
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				if(a[i][j]==2048 &&	win==0){
					win++;
					printf("\n\n WIN \n\n");
					printf("Cikmak icin 'E'ye, tekrar oynamak icin 'X'e basiniz");
					printf("yön ok tuslaini kullanarak oynamaya devam edebilirsiniz");
				}
				if(a[i][j]==0){
					m++;
				}
			}
		}
		
		//controls the movement areas of the elements
		if(m==0){
			l=0;
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					if(a[i][j]==a[i+1][j]){
						l++;
					}
					if(a[i][j]==a[i][j+1]){
						l++;
					}
				}
			}
		}
		if(l==0){
			printf("\n\n G A M E  O V E R \n\n");
			printf("Cikmak icin 'E'ye, tekrar oynamak icin 'X'e basiniz");
		}

		fp=fopen("dosya.txt","r");
		fscanf(fp, "%d",&bilgi);	
		if(HIGHSCORE>bilgi){
			bilgi=HIGHSCORE;
			FILE *fp=fopen("dosya.txt","w");
			fprintf(fp,"%d\n",bilgi);	
		}
		fclose(fp);

	}while(tus!='E' && tus!='e');
	
	return 0;
}

