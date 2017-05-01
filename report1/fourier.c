#include <stdio.h>
#include <math.h>
float A[30][30],c,x[30]; //入力用の配列
int main(void) {
    int i,j,k,n;
    n = 20;  //Matrix Number

    //Zero Matrix Create
    printf("----------------Zero Matrix Create----------------\n");
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
                A[i][j] = 0.0;
            printf("%lf  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<20; i++){
        A[i][i] = 0.5*(1+(i+1)*(i+1)*M_PI*M_PI);    //L=1
        printf("L:%lf  \n",A[i][i]);
    }
    printf("\n");

    printf("----------------Matrix 20x20----------------\n");
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            printf("%lf  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < 20; i++){
        A[i][20] = 1/((i+1)*M_PI) - cos((i+1)*M_PI)/((i+1)*M_PI);
        printf("f[%d] = %lf  \n", i, A[i][20]);
    }
    printf("\n");

    //Gauss-Jordan Method 
    for(j=0; j<=n-1; j++)
    {
        for(i=0; i<=n-1; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=0; k<=n; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    
    printf("\nThe solution is:\n");
    for(i=0; i<=n-1; i++)
    {
        x[i]=A[i][n]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    double xx[30];
    for(i=0;i<=20;i++){
        xx[i] = 0.05*i;
        printf("xx=%lf\n",xx[i]);
    }
    double kai0 = 0.0;
    int ii;
    double kai[30];

/*
    for (ii=0; ii<20; ii++){
        for (i=0; i<20; i++){
            kai[ii] += x[i]*sin((i+1)*M_PI*xx[ii+1]/20);
        }
    //kai0=0.0;
    printf("\n kai : %d=%f\n",ii,kai[ii]);
    }
    //printf("\n kai : %d=%f\n",ii,kai0);
*/
    for(j=0;j<21;j++){
    for (i=0; i<20; i++){
        //kai[0] += x[i]*sin((i+1)*M_PI*0.05);
        kai[0] += x[i]*sin((i+1)*M_PI*xx[j]);     
    }
    printf("\n kai : %d=%f\n",i,kai[0]);
    kai[0] = 0.0;
    }

}