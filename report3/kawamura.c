//coredump version.
#include <stdio.h>
#include <math.h>
#define N 50
#define M 5
int main(void){
    int i,j,k;
    double u[N+3][N+3];
    double theta = 30.0;
    double alpha=theta*M_PI/180.0;
    double dx=1.0/N;
    double dy=1.0/N;

    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            u[i][j] = 0.0;
        }
    }

    for(i=0; i<=M; i++){
        u[i][0] = 1.0;
        u[i][1] = 1.0;
    }

    for(j=0; j<=M; j++){
        u[0][j] = 1.0;
        u[1][j] = 1.0;
    }

    for(k=0; k<=1000; k++){
        for(i=2; i<=N+1; i++){
            for(j=2; j<=N+1; j++){
                if(N==0){
                    u[i+1][j]=0;
	                u[i+2][j]=0;
	                u[i][j+1]=0;
	                u[i][j+2]=0;
                }
                if(i==N){
                    u[i+2][j]=u[i-2][j];
                }
                if(i==N+1){
                    u[i+1][j]=u[i-1][j];
	                u[i+2][j]=u[i-2][j];
                }
                if(j==N){
                    u[i][j+2]=u[i][j-2];
                }
                if(j==N+1){
                    u[i][j+1]=u[i][j-1];
	                u[i][j+1]=u[i][j-2];
                }
                    u[i][j]=(dy*cos(alpha)*(-u[i+2][j]+2*u[i+1][j]
                    + 10*u[i-1][j]-2*u[i-2][j])
                    + dx*sin(alpha)*(-u[i][j+2]+2*u[i][j+1]
                    + 10*u[i][j-1]-2*u[i][j-2]))
                    / (9.0*(dy*cos(alpha)+dx*sin(alpha)));
            }
        }
    }


    for(j=0; j<=N; j++){
        printf("%10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf \
                %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf \
                %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf \
                %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf \
                %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf\n",
                u[0][j],u[1][j],u[2][j],u[3][j],u[4][j],u[5][j],u[6][j],u[7][j],u[8][j],u[9][j],
                u[10][j],u[11][j],u[12][j],u[13][j],u[14][j],u[15][j],u[16][j],u[17][j],u[18][j],u[19][j],
                u[20][j],u[21][j],u[22][j],u[23][j],u[24][j],u[25][j],u[26][j],u[27][j],u[28][j],u[29][j],
                u[30][j],u[31][j],u[32][j],u[33][j],u[34][j],u[35][j],u[36][j],u[37][j],u[38][j],u[39][j],
                u[40][j],u[41][j],u[42][j],u[43][j],u[44][j],u[45][j],u[46][j],u[47][j],u[48][j],u[49][j],u[50][j]);

    }
}

