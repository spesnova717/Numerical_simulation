#include <stdio.h>
#include <math.h>
#include "func.h"
#define IDX_WEI (0)
#define IDX_ABS (1)
#define NUM_ITEMS (8)
double a[3][3]; //入力用の配列
double c,x[10];

double cf[NUM_ITEMS][2] = {
//重み，積分点
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
    double inv_a[2][2]; //ここに逆行列が入る
    double buf; //一時的なデータ蓄積
    int i,j,k;  //カウンタ
    int n = 2;    //配列の次数
    double kai1;
    double kai2;

//------------------------------------------
    d0 = 0.0;
    for(idx=0; idx<NUM_ITEMS; idx++) {
        xx = cf[idx][IDX_ABS];
        weight = cf[idx][IDX_WEI];
        yy = myFunc1(xx);
        d0 += (weight * yy);
    }
    a[0][0] = d0;
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
    a[0][1] = d0;
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
    a[1][0] = d0;
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
    a[1][1] = d0;
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
    a[0][2] = d0;
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
    a[1][2] = d0;
    printf("f2=%lf\n", d0);
//------------------------------------------

    /* Gauss-Jordan method */
    for(j=0; j<=n-1; j++)
    {
        for(i=0; i<=n-1; i++)
        {
            if(i!=j)
            {
                c=a[i][j]/a[j][j];
                for(k=0; k<=n; k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
        }
    }

    printf("\nThe solution is:\n");
    for(i=0; i<=n-1; i++)
    {
        x[i]=a[i][n]/a[i][i];
        printf("\n x%d=%.10f\n",i,x[i]);
    }
}