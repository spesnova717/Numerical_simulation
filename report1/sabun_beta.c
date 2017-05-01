//sabun alpha
#include<stdio.h>
#include<math.h>
#include"nrutil.c"	//Numerical Recipes in C

//https://www.astro.umd.edu/~ricotti/NEWWEB/teaching/ASTR415/NRiC/tridag.c
void tridag(float a[], float b[], float c[], float r[], float u[], unsigned long n){
	unsigned long j;
	float bet,*gam;
	
	gam=vector(1,n);
	if (b[1] == 0.0) nrerror("Error 1 in tridag");
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

int n = 21;
int i, j;
double x = 0.0;
double dx = 1.0/20.0;	//Grid spacing

//https://www2.units.it/ipl/students_area/imm2/files/Numerical_Recipes.pdf p74
float C[n+1],B[n+1],A[n+1],r[n+1],u[n+1];

	for(i=0; i<=n; i++){
		A[i]	= 1.0;			//a
        B[i]	= -(2+dx*dx);	//b
		C[i]	= 1.0;			//c
        r[i]	= -dx*dx;		//r
		u[i]	= 0.0;			//u 初期化　解
	}

	tridag(C+1,B+1,A+1,r+1,u+1,n-2);

	for(i=1;i<=n;i++){
		printf("%lf	",(i-1)*0.05);
		printf("%lf\n",u[i]);
	}
}