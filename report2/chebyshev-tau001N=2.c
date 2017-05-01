#include<stdio.h>
#include<math.h>

int main(void){
    int n = 2;
    //double A = 2/(4*n*(n-1));
    double A = 0.25;
    //double B = -(1 + 1/(2*(n^2-1)));
    double B = -1.16;
    double C = 4*n*(n-1);

    double matrixA[n+1][n+1];
    double matrixF[n];
    double matrixa[n];

    double matrixB[n+1][n+1];
    double matrixF1[n];
    double matrixa1[n];

    double c;
    int i,j,k;  //カウンタ

    matrixA[0][0] = 1.0;
    matrixA[0][1] = 1.0;
    matrixA[1][0] = A;
    matrixA[1][1] = B;

    matrixF[0] = 0.50;
    matrixF[1] = 0.0;
    
    matrixA[0][2] = matrixF[0];
    matrixA[1][2] = matrixF[1];
    
    /* Gauss-Jordan method */
    for(j=0; j<=n-1; j++)
    {
        for(i=0; i<=n-1; i++)
        {
            if(i!=j)
            {
                c=matrixA[i][j]/matrixA[j][j];
                for(k=0; k<=n; k++)
                {
                    matrixA[i][k]=matrixA[i][k]-c*matrixA[j][k];
                }
            }
        }
    }

    printf("\nThe solution is:\n");
    for(i=0; i<=n-1; i++)
    {
        matrixa[i]=matrixA[i][n]/matrixA[i][i];
        printf("\n a[%d]=%.10f\n",i*2,matrixa[i]);
    }
    printf("\n a[%d]=%.10f\n",1,-0.50);
}
