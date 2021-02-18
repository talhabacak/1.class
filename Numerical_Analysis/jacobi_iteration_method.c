#include <stdio.h>
#include <math.h>

int main(){
	
	int i,j,d,y;
	
	printf("fonksiyonun derecesini giriniz\n");
	scanf("%d",&d);
	
	double k[d+2],m,S,s,l,b,x,p,a,D,e,c,t;
	
	printf("baslangic degerini giriniz\n");
	scanf("%lf",&a);
	
	printf("kabul edilebilir hatayi giriniz(epsilon)\n");
	scanf("%lf",&e);

	b=10000;
	y=0;	
	t=0;
	c=0;
	l=0;
	m=0;
	
	for(i=d; i>=0; i--){
		printf("%d dereceli terimin kat sayisini giriniz\n",i);
		scanf("%lf",&k[i]);	
	}
	
	for(i=d-1; i>0; i--){
		x=1;
		for(j=1; j<=i; j++){
			x=x*a;
		}
		c=x*k[i]+c;
		t=t+i*(-k[i])*x/a;
	}
	c=c+k[0];
	
	D=d;
	s=pow(-c,((1/D)-1));
	s=(s*t)*(1/D);
	
	while(e<b && s<1){
		c=0;
		for(i=d-1; i>0; i--){
			x=1;
			for(j=1; j<=i; j++){
			x=x*a;
			}
			c=x*k[i]+c;
		}	
		c=c+k[0];
		p=pow(-c,(1/D));
		b=a-p;
		b=fabs(b);
		a=p;
		y=1;
		printf("\nXkok: %f",a);
	}
	
	if(y==0){

		for(i=d; i>0; i--){
			x=1;
			for(j=1; j<=i; j++){
				x=x*a;
			}
			l=l+k[i]*x/a;
			m=m+(i-1)*k[i]*x/(a*a);
		}
		s=-k[0]/(l*l)*m;

		while(e<b && s<1){
			l=0;
			for(i=d; i>0; i--){
				x=1;
				for(j=1; j<=i; j++){
					x=x*a;
				}
				l=l+k[i]*x/a;
			}
			
			l=-k[0]/l;
			b=a-l;
			b=fabs(b);
			a=l;
			y=1;
			printf("\nXkok: %f",a);
		}	
	}
	
	if(y==0){
	
	
		for(i=d; i>0; i--){
			x=1;
			for(j=1; j<=i; j++){
				x=x*a;
			}
			l=l+k[i]*x;
			m=m+i*k[i]*x/a;
		}
		m=m-k[1];
		m=m/(-k[1]);
				
		while(e<b && m<1){
			l=0;
			for(i=d; i>0; i--){
				x=1;
				for(j=1; j<=i; j++){
					x=x*a;
				}
				l=l+k[i]*x;
			}
			l=l-k[1]*a+k[0];
			l=l/(-k[1]);
			
			b=a-l;
			b=fabs(b);
			a=l;
			y=1;
			printf("\nXkok: %f",a);
		}
	}
	
	printf("\n\nXkoknet: %f",a);
	
	return 0;
}
