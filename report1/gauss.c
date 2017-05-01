#include <stdio.h>//test
#include <math.h>
#include "func.h"
#define IDX_WEI (0)
#define IDX_ABS (1)
#define NUM_ITEMS (8)
double a[3][3]; //入力用の配列
double f[3]; //f値
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
        yy = myFunc3(xx);
        d0 += (weight * yy);
    }
    a[0][2] = d0;
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
        yy = myFunc6(xx);
        d0 += (weight * yy);
    }
    a[1][2] = d0;
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
    a[2][0] = d0;
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
    a[2][1] = d0;
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
    a[2][2] = d0;
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
    f[0] = d0;
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
    f[1] = d0;
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
    f[2] = d0;
    printf("f3=%lf\n", d0);
//------------------------------------------

double inv_a[3][3]; //ここに逆行列が入る
double buf; //一時的なデータを蓄える
int i,j,k; //カウンタ
int n=3;  //配列の次数
 
//単位行列を作る
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        inv_a[i][j]=(i==j)?1.0:0.0;
        }
    }
//掃き出し法
for(i=0;i<n;i++){
    buf=1/a[i][i];
    for(j=0;j<n;j++){
    a[i][j]*=buf;
    inv_a[i][j]*=buf;
}
for(j=0;j<n;j++){
    if(i!=j){
        buf=a[j][i];
        for(k=0;k<n;k++){
            a[j][k]-=a[i][k]*buf;
            inv_a[j][k]-=inv_a[i][k]*buf;
            }
        }
    }
}
//逆行列を出力
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf(" %f",inv_a[i][j]);
}
    printf("\n");
}
printf("[0][0]%lf\n",inv_a[0][0]);
printf("[0][1]%lf\n",inv_a[0][1]);
printf("[0][2]%lf\n",inv_a[0][2]);
printf("[1][0]%lf\n",inv_a[1][0]);
printf("[1][1]%lf\n",inv_a[1][1]);
printf("[1][2]%lf\n",inv_a[1][2]);
printf("[2][0]%lf\n",inv_a[2][0]);
printf("[2][1]%lf\n",inv_a[2][1]);
printf("[2][2]%lf\n",inv_a[2][2]);
double kai1;
double kai2;
double kai3;

kai1 = inv_a[0][0] * f[0] + inv_a[0][1] * f[1] + inv_a[0][2] * f[2];
kai2 = inv_a[1][0] * f[0] + inv_a[1][1] * f[1] + inv_a[1][2] * f[2];
kai3 = inv_a[2][0] * f[0] + inv_a[2][1] * f[1] + inv_a[2][2] * f[2];

printf("a1 = %lf\n",kai1);
printf("a2 =  %lf\n",kai2);
printf("a3 = %lf\n",kai3);
}