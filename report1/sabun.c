#include<stdio.h>
#include<math.h>
#include"nrutil.c"

void tridag(float a[], float b[], float c[], float r[], float u[], unsigned long n){
	unsigned long j;
	float bet,*gam;
	
	gam=vector(1,n);
	if (b[1] == 0.0) nrerror("Error 1 in tridag");//nrerror("Error 1 in tridag");
	u[1]=r[1]/(bet=b[1]);
	for (j=2;j<=n;j++) {
		gam[j]=c[j-1]/bet;
		bet=b[j]-a[j]*gam[j];
		if (bet == 0.0) nrerror("Error 2 in tridag");
		u[j]=(r[j]-a[j]*u[j-1])/bet;
	}
	for (j=(n-1);j>=1;j--)
		u[j] -= gam[j+1]*u[j+1];
	free_vector(gam,1,n);
}

int main(void){
int stepsize;
stepsize=21;
const unsigned long n = 21;
int i, j;
double x, dx;
x = 0.0;
dx= 1.0/20;

float subdag[n+1],dag[n+1],supdag[n+1],f[n+1],u[n+1];

	for(i=0; i<=n; i++){
		supdag[i]	= 1.0;						//superdiagonal elements
		//dag[i]	= -(2+pow(dx,2.0));				//diagonal elements
        dag[i]	= -(2+dx*dx);				//diagonal elements
		subdag[i]	= 1.0;						//subdiagonal elements
		//f[i]		= -pow(dx,2.0);				//rightside of equation
        f[i]		= -dx*dx;				//rightside of equation
		u[i]		= 0.0;						//answer values of u(x) zero-init.
	}
//-----------main initializers end-----------

	printf("\nMtrPrev  ");						//Matrix export to stdout...preview
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
							
							if(j==i){printf("%6.2lf  ",dag[i]);}
							else if(j==i+1){printf("%6.2lf  ",supdag[i]);}
							else if(j==i-1){printf("%6.2lf  ",subdag[i]);}
							else {printf("%6.2lf  ",0.0);}
							if(j==n){printf("|%6.2lf|%6.2lf",u[i],f[i]);}
						}
		printf("\n         ");
	}printf("\n");



	tridag(subdag+1,dag+1,supdag+1,f+1,u+1,n-2);			//call tridag function to solve matrix
//Don't calculate "x=0" & "x=1". to skip "x=0", +1 pointer increment was needed
//order "-2" to skip last term "x=1"

	printf("\nMtrAftr  ");						//Matrix export to stdout...after tridag
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
							
							if(j==i){printf("%6.2lf  ",dag[i]);}
							else if(j==i+1){printf("%6.2lf  ",supdag[i]);}
							else if(j==i-1){printf("%6.2lf  ",subdag[i]);}
							else {printf("%6.2lf  ",0.0);}
							if(j==n){printf("|%6.2lf|%6.2lf",u[i],f[i]);}
						}
		printf("\n         ");
	}printf("\n");
}