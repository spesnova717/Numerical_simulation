#include<stdio.h>
#include<math.h>

int main(void){
    int n = 2;
    double aaa0;
    double aaa1;
    double aaa2;
    double aaa3;
    double aaa4;
    double aaa5;
    double aaa6;
    double aaa7;
    double aaa8;
    double A = 0.25;
    double B = -1.16666666667;
    double C = 4*n*(n-1);

    double matrixA[n+1][n+1];
    double matrixF[n];
    double matrixa[n];

    double c;
    int i,j,k;  //カウンタ

    matrixA[0][0] = 1.0;
    matrixA[0][1] = 1.0;
    matrixA[1][0] = A;
    matrixA[1][1] = B;
   
    matrixA[0][2] = 0.50;
    matrixA[1][2] = 0.0;
    
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
    printf("\n a[%d]=%.10f\n",1,0.50);
    aaa0 = matrixa[0];
    aaa1 = 0.50;
    aaa2 = matrixa[1];

    double matrixA1[n+1][n+1];
    double matrixF1[n];
    double matrixa1[n];

    matrixA1[0][0] = -1.0;
    matrixA1[0][1] = -1.0;
    matrixA1[1][0] = 0.02083333333;//0.50/24.0 a1/24.0
    matrixA1[1][1] = -1.0625;//-17/16

    matrixA1[0][2] = -0.50;
    matrixA1[1][2] = 0.0;
    n = 2;
    for(j=0; j<=n-1; j++)
    {
        for(i=0; i<=n-1; i++)
        {
            if(i!=j)
            {
                c=matrixA1[i][j]/matrixA1[j][j];
                for(k=0; k<=n; k++)
                {
                    matrixA1[i][k]=matrixA1[i][k]-c*matrixA1[j][k];
                }
            }
        }
    }

    printf("\nThe solution is:\n");
    for(i=0; i<=n-1; i++)
    {
        matrixa1[i]=matrixA1[i][n]/matrixA1[i][i];
        printf("\n a[%d]=%.10f\n",i*2+1,matrixa1[i]);
    }
    aaa3 = matrixa1[1];

    double bbb,aaa;
    ///5
    n=2;
    aaa4 = (-2*aaa0*(n+1)+4*n*n*n*aaa2-2*n*aaa2)/(n-1);
    printf("\n a[%d]=%.10f\n",4,aaa4);


    aaa4 = -6*aaa0 + 28*aaa2;
    printf("\n a[%d]=%.10f\n",4,aaa4);
    
    n=3;
    aaa5 = (-aaa1*(n+1)+4*n*n*n*aaa3-2*n*aaa3)/(n-1);
    printf("\n a[%d]=%.10f\n",5,aaa5);

    n=4;
    aaa6 = (-aaa2*(n+1)+4*n*n*n*aaa4-2*n*aaa4)/(n-1);
    printf("\n a[%d]=%.10f\n",6,aaa6);

    n=5;
    aaa7 = (-aaa3*(n+1)+4*n*n*n*aaa5-2*n*aaa5)/(n-1);
    printf("\n a[%d]=%.10f\n",7,aaa7);

    n=6;
    aaa8 = (-aaa4*(n+1)+4*n*n*n*aaa6-2*n*aaa6)/(n-1);
    printf("\n a[%d]=%.10f\n",8,aaa8);

    double q[22];
    double basic;
    double t0 = 1;
    double t1 = basic;
    double t2 = 2*basic*basic-1;
    double t3 = 4*basic*basic*basic-3*basic;
    double t4 = 8*basic*basic*basic*basic-8*basic*basic+1;
    double t5 = 16*basic*basic*basic*basic*basic-20*basic*basic*basic+5*basic;
    double t6 = 21*pow(basic,6)-48*pow(basic,4)+18*pow(basic,2)-1;
    double t7 = 64*pow(basic,7)-112*pow(basic,5)+56*pow(basic,3)-7*pow(basic,6);
    double t8 = 128*pow(basic,8)-256*pow(basic,6)+160*pow(basic,4)-32*pow(basic,2)+1;

    double che2_pre[30];
    double che4_pre[30];
    double che8_pre[30];

    for(i=0; i<21; i++){
        basic = 1.0-i*0.1;
        che2_pre[i] = aaa0*1 + aaa1*basic + aaa2*(2*basic*basic-1);
        printf("che2_pre %lf   %lf \n",basic,che2_pre[i]);
    }  

    printf("\n");

    for(i=0; i<21; i++){
        basic = 1.0-i*0.1;
        che2_pre[i] = aaa0*1 + aaa1*basic + aaa2*(2*basic*basic-1) + aaa3*(4*basic*basic*basic-3*basic) +
        aaa4*(8*basic*basic*basic*basic-8*basic*basic+1);
        printf("che2_pre %lf   %lf \n",basic,che2_pre[i]);
    }

    printf("\n");

    for(i=0; i<21; i++){
        basic = 1.0-i*0.1;
        che2_pre[i] = aaa0*1 + aaa1*basic + aaa2*(2*basic*basic-1) + aaa3*(4*basic*basic*basic-3*basic) +
        aaa4*(8*basic*basic*basic*basic-8*basic*basic+1) + aaa5*(16*basic*basic*basic*basic*basic-20*basic*basic*basic+5*basic) +
        aaa6*(21*pow(basic,6)-48*pow(basic,4)+18*pow(basic,2)-1) + 
        aaa7*(64*pow(basic,7)-112*pow(basic,5)+56*pow(basic,3)-7*pow(basic,6)) +
        aaa8*(128*pow(basic,8)-256*pow(basic,6)+160*pow(basic,4)-32*pow(basic,2)+1);
        printf("che2_pre %lf   %lf \n",basic,che2_pre[i]);
    }
    




/*
    for(i=0;i<21;i++){
        q[i]= 1.0 - 0.1*i;
        printf("%lf\n",q[i]);
    }

    double ii;
    for(basic=1.0;basic<-1.0;basic=basic-0.1){
        che2 = aaa0*t0 + aaa1*t1 + aaa2*t1;
        printf("x=%lf, %lf\n",basic,che2);
    }


*/









    }
