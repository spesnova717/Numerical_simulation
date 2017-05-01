#include <stdio.h>
#include <math.h>
#define Expansion_factor 2

int n = (Expansion_factor+2)/2;


//prototype of functions
	void gjsolver(double[][n+1], double[n+1], double[n+1]);
	//GJSolver(target matrix,target vector, GJ-solution matrix)
	void mtrexchange(double[][n+1],double[], int, int, int, int);

#define exptn 5

void mtrexport(char name[], int k, double a[][exptn+1], char mtr, char line, char col){
	
	int i,j;
	
		printf("\n%s%d\t%c[%c][%c] = ",name,k,mtr,line,col);	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){printf("%5.2lf ",a[i][j]);}
		printf("\n\t\t\t  ");
	}printf("\n");

}


int main(void){
//-----------main initializers-----------
	int i,j,k,ne,no;
	double u, x, dx;
	u = -1.0;
	x = -1.0;
	dx= (1.0-(-1.0))/20;

	double k_odd[(Expansion_factor+2)/2 + 1][(Expansion_factor+2)/2 + 1];
	double f_odd[(Expansion_factor+2)/2 + 1];
	double a_odd[(Expansion_factor+2)/2 + 1];

	double k_even[(Expansion_factor+2)/2 + 1][(Expansion_factor+2)/2 + 1];
	double f_even[(Expansion_factor+2)/2 + 1];
	double a_even[(Expansion_factor+2)/2 + 1];
	
	double CL[Expansion_factor+1];	//C-Legendre polynomials
		CL[0]=2.0;
		for(i=1;i<=Expansion_factor;i++){
			CL[i]=1.0;
			}
	
	double T[Expansion_factor+1];	//Chebyshev polynomials
		T[0]= 1.0;
		T[1]= x;
		for(i=2; i<=Expansion_factor; i++){
			T[i]=2.0*x*T[i-1]-T[i-2];
			}
			
	double a_merged[Expansion_factor];

//-----------main initializers end-----------


//Making the Matrix for chebyshev-tau-method
	//zero initialize k matrix and f vector
	for(i=0; i<(Expansion_factor+2)/2 + 1; i++){
		f_odd[i]=0;				//vector f_odd[i] init.
		f_even[i]=0;			//vector f_even[i] init.
		for(j=0; j<(Expansion_factor+2)/2 + 1 ; j++){
			k_odd[i][j]=0;			//matrix k_odd[i][j] init.
			k_even[i][j]=0;			//matrix k_even[i][j] init.
			}
		}

	//calculate components of k matrix and f vector
	for(i=1; i<=(Expansion_factor+2)/2; i++){
		for(j=1; j<=(Expansion_factor+2)/2; j++){			
			if(i==1){
				f_odd[i]	=(1.0/2.0);		//first row of rightside vectors = 0.5
				f_even[i]	=(1.0/2.0);
				k_odd[i][j]	= 1.0;			//first rows of odd     matrix = 1(all)
				k_even[i][j]= 1.0;			//				 and even
			}else{						//only first rows are filled by '1'
					ne=(i*2)-2;
					no=(i*2)-1;
					if(i==(j+1)){	//subdiagonal elements		"A()"
									k_odd[i][j]		= CL[no-2]/(4*no*(no-1));
									k_even[i][j]	= CL[ne-2]/(4*ne*(ne-1));
									}
					if(i==j){		//diagonal elements 		"B()"
									k_odd[i][j]		= -(1.0+(1.0/( 2.0*(pow(no,2.0)-1.0) ) ));
									k_even[i][j]	= -(1.0+(1.0/( 2.0*(pow(ne,2.0)-1.0) ) ));
									}
					if(i==(j-1)){	//superdiagonal elements	"C()"
									k_odd[i][j]		= 1/(4*n*(no-1));
									k_even[i][j]	= 1/(4*i*(ne-1));
									}
				
				}
			
			}


		}
	mtrexport("chebytauod",1,k_odd,'a','i','j');
	mtrexport("chebytauev",1,k_even,'a','i','j');

//-----------chebyshev-tau method matrix complete-----------
	gjsolver(k_odd,f_odd,a_odd);		//solve the matrix using GJsolver
	gjsolver(k_even,f_even,a_even);		//solve the matrix using GJsolver

	for(i=1;i<=Expansion_factor;i++){
		if(i%2){a_merged[i]=a_odd[j];}
		else{a_merged[i]=a_even[j];}
		}

	return 0;
}


//-below-------C-lang Gauss-Jordan Solver and Pivot exchanger-------
void gjsolver(double a[][n+1], double b[n+1], double gjsolution[n+1]){
	int i,j,k,l,m;
	double tmp;
	printf("Start Gauss-Jordan method Solver.\n");
	for(k=1; k<=n; k++)													/*Gauss-Jordan k�������đ���*/	
	{
		mtrexchange(a,b,k,k,k+1,n);														/*Matrix �s�����ւ��֐�*/
		for(i=1; i<=n; i++)													/*�s��*/
		{
			if(k!=i)																/*�Ίp�����ȊO�̐���������*/
			{
				tmp=(a[i][k] / a[k][k]);												/*�Ώۗ��̌v�Z�p�ɒl���ޔ�*/
				for(j=1; j<=n; j++)														/*i�s�ڂ̐������Cj++�ł��ׂď���*/
				{
					a[i][j] = a[i][j] - (tmp*a[k][j]);									/*a(i,j)������*/
				}
				b[i]= b[i] - ( b[k]*tmp);												/*b[i]�ɂ����l�̏���*/

				printf("\nMtrGJ    a[i][j] = ");										/*i�s�ڏ��������@���ԏo�͊J�n*/
				for(l=1;l<=n;l++){
					for(j=1;j<=n;j++){
										printf("%5.2lf ",a[l][j]);
										if(j==n){printf("  %5.2lf",b[l]);}
									}
					printf("\n                   ");
				}printf("\n");															/*i�s�ڏ��������@���ԏo�͊���*/

			}																		/*�Ίp�����ȊO*/
		}																	/*�s���@i�s���[�v*/
	}
	
	printf("Gauss-Jordan method finished.\n");
	for(i=1; i<=n; i++){
		printf("GJ-sol.%d = %lf\n",i,b[i]/a[i][i]);
		gjsolution[i] = b[i]/a[i][i];
	}/*���̏o��*/
	 return;
}

void mtrexchange(double a[][n+1],double b[], int k, int ia, int ib, int dimn){
				//�Ώۍs��a,	�Ώۍs��b,	 �Q�Ɨ�, �Ώۍs1, �Ώۍs2, �Ώۍs���̎���
	
	int i,j;														/*for*/
	double x,y,tmp,tmpmtr[n+1];

	printf("matrix exchanger was called. checking pivot...");
	printf("\nMtrPrev  a[i][k] = ");	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
							printf("%5.2lf ",a[i][j]);
							if(j==n){printf("  %5.2lf",b[i]);}
						}
		printf("\n                   ");
	}printf("\n");

	if((ia>dimn) || (ib>dimn)){
		printf("No more exchange needed. Finish pivot exchange.\n");
		return;
		}

	x=a[ia][k];
	y=a[ib][k];
	if(fabs(y)>fabs(x)){
		printf("do %d pivot...\n",k);
		tmp=x; x=y; y=tmp;
		}
	else{printf("do nothing %d.\n",k);}
	if(x!=a[ia][k]){
		//matrix a
		for(j=1;j<=n;j++){	tmpmtr[j]=a[ia][j]; }
		for(j=1;j<=n;j++){	a[ia][j]=a[ib][j];  }
		for(j=1;j<=n;j++){	a[ib][j]=tmpmtr[j]; }
		
		//vector b
		tmp=b[ia];
		b[ia]=b[ib];
		b[ib]=tmp;
	}

	
	printf("\nchanged%d a[i][k] = ",k);	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
							printf("%5.2lf ",a[i][j]);
							if(j==n){printf("  %5.2lf",b[i]);}
						}
		printf("\n                   ");
	}printf("\n");
	

}
