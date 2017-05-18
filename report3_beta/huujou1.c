#include <stdio.h>
#include <math.h>
#define N 50
#define M 5

int main(void){
    int i,j;
    double u[N+1][N+1];	//kai
    double theta = 30.0;
    double alpha=theta*M_PI/180.0;
    double dx=1.0/N;
    double dy=1.0/N;

    for(i=0; i<=N; i++){	//initialize.
        for(j=0; j<=N; j++){
            u[i][j] = 0.0;
        }
    }

    for(i=0; i<=M; i++){
        u[i][0] = 1.0;
	u[0][i] = 1.0;
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            u[i][j] = (cos(alpha)*dy*u[i-1][j] + sin(alpha)*dx*u[i][j-1]) / (cos(alpha)*dy+sin(alpha)*dx);
        }
    }

    for(j=0; j<=N; j++){
        printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \
                %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \
                %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \
                %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \
                %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                u[0][j],u[1][j],u[2][j],u[3][j],u[4][j],u[5][j],u[6][j],u[7][j],u[8][j],u[9][j],
                u[10][j],u[11][j],u[12][j],u[13][j],u[14][j],u[15][j],u[16][j],u[17][j],u[18][j],u[19][j],
                u[20][j],u[21][j],u[22][j],u[23][j],u[24][j],u[25][j],u[26][j],u[27][j],u[28][j],u[29][j],
                u[30][j],u[31][j],u[32][j],u[33][j],u[34][j],u[35][j],u[36][j],u[37][j],u[38][j],u[39][j],
                u[40][j],u[41][j],u[42][j],u[43][j],u[44][j],u[45][j],u[46][j],u[47][j],u[48][j],u[49][j],u[50][j]);

    }
}

