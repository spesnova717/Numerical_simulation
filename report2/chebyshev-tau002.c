#include <stdio.h>
#include <math.h>
#define IDX_WEI (0)
#define IDX_ABS (1)
#define NUM_ITEMS (8)
double a[3][3]; //入力用の配列
double c,x[10];

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

    a[0][0] = 1.0;
    a[0][1] = 1.0;
    a[1][0] = 0.25;
    a[1][1] = -1.166;
    a[0][2] = 0.50;
    a[1][2] = 0.0;

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