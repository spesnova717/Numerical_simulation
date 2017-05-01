#include <stdio.h>//test
#include <math.h>
#include "func.h"
#define IDX_WEI (0)
#define IDX_ABS (1)
#define NUM_ITEMS (8)
double A[20][20],c,x[10]; //入力用の配列
double cf[NUM_ITEMS][2] =
{
// weight, abscissa
{0.10122853629037625915,    -0.96028985649753623168},
{0.22238103445337447054,    -0.79666647741362673959},
{0.31370664587788728734,    -0.52553240991632898582},
{0.36268378337836198297,    -0.18343464249564980494},
{0.36268378337836198297,     0.18343464249564980494},
{0.31370664587788728734,     0.52553240991632898582},
{0.22238103445337447054,     0.79666647741362673959},
{0.10122853629037625915,     0.96028985649753623168},

};

int main(void)
{
    double d0, xx, yy, weight;
    int idx;
    int i,j,k,n;
    n=3;

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc1(xx);
        d0 += (weight * yy);
    }
    A[0][0] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc2(xx);
        d0 += (weight * yy);
    }
    A[0][1] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc3(xx);
        d0 += (weight * yy);
    }
    A[0][2] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc4(xx);
        d0 += (weight * yy);
    }
    A[1][0] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc5(xx);
        d0 += (weight * yy);
    }
    A[1][1] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc6(xx);
        d0 += (weight * yy);
    }
    A[1][2] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc7(xx);
        d0 += (weight * yy);
    }
    A[2][0] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc8(xx);
        d0 += (weight * yy);
    }
    A[2][1] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc9(xx);
        d0 += (weight * yy);
    }
    A[2][2] = d0;
    printf("%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFuncf1(xx);
        d0 += (weight * yy);
    }
    A[0][3] = d0;
    printf("f1=%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFuncf2(xx);
        d0 += (weight * yy);
    }
    A[1][3] = d0;
    printf("f2=%lf\n", d0);
//------------------------------------------

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFuncf3(xx);
        d0 += (weight * yy);
    }
    A[2][3] = d0;
    printf("f3=%lf\n", d0);
//------------------------------------------

    /* Gauss-Jordan method */
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
}