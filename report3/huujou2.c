#include <stdio.h>
#include <math.h>
#define N 50
#define M 5

int main(void){
    int i,j;
    double u[N+1][N+1];
    double alpha=theta*pi/180.0;
    double dx=1.0/N;
    double dy=1.0/N;

    for(i=0; i=<N; i++){
        for(j=0; j=<N; j++){
            u[i][j] = 0.0;
        }
    }

    for(i=0; i=<M; i++){
        u[i][0] = 1.0;
    }

    for(j=0; j=<M; i++){
        u[0][j] = 1.0;
    }

    for(i=1; i=<N; i++){
        for(j=1; j=<N; j++){
            u[i][j] = (cos(alpha)*dy*uu[i-1][j] + sin(alpha)*dx*uu[i][j-1] / (cos(alpha)*dy+sin(alpha)*dx);
        }
    }

    for(j=0; j=<N; j++){
        printf("%lf\n",u[0][j]);
    }
}

