//modified_verlet
#include <stdio.h>
#include <math.h>
#define N 120
#define M 5
int i, j, step;
double m, n, L, dt;

double xa[N+M], xb[N+M], ya[N+M], yb[N+M];
double axa[N+M], axb[N+M], aya[N+M], ayb[N+M];
double r[N+M], vxa[N+M], vxb[N+M];
double vya[N+M], vyb[N+M];

int main(){
    m = 6.63*(pow(10,-26));
    n = 12.0;
    L = 6.0;
    dt = 0.01;
    step = 120;
    for(i=0; i<=N; i++){
        xa[N] = 0.0;
        xb[N] = 0.0;
        ya[N] = 0.0;
        yb[N] = 0.0;
        axa[N] = 0.0;
        axb[N] = 0.0;
        aya[N] = 0.0;
        ayb[N] = 0.0;
        r[N] = 0.0;
        vxa[N] = 0.0;
        vxb[N] = 0.0;
        vya[N] = 0.0;
        vyb[N] = 0.0;
    }

    xa[0]=0.0;
    ya[0]=3.0;
    xb[0]=0.0;
    yb[0]=-1.0;
    vxa[0]=sqrt(3.0);
    vya[0]=-3.0;
    vxb[0]=sqrt(3.0);
    vyb[0]=1.0;
    
    for(j=1; j<=step; j++){
        r[0]=sqrt((xa[0]-xb[0])*(xa[0]-xb[0]) + (ya[0]-yb[0])*(ya[0]-yb[0]));
        axa[j]=(pow((1.0/r[j-1]),(n+1.0))-
            (L/n)*pow((1.0/r[j-1]),(L+1.0)))*((xa[j-1]-xb[j-1])/r[j-1]);

        axb[j]=(pow((1.0/r[j-1]),(n+1.0))-
            (L/n)*pow((1.0/r[j-1]),(L+1.0)))*((xb[j-1]-xa[j-1])/r[j-1]);

        aya[j]=(pow((1.0/r[j-1]),(n+1.0))-
            (L/n)*pow((1.0/r[j-1]),(L+1.0)))*((ya[j-1]-yb[j-1])/r[j-1]);

        ayb[j]=(pow((1.0/r[j-1]),(n+1.0))-
            (L/n)*pow((1.0/r[j-1]),(L+1.0)))*((yb[j-1]-ya[j-1])/r[j-1]);

        xa[j]=xa[j-1]+dt*vxa[j-1]+((dt*dt)/(2.0*m))*m*axa[j-1];

        vxa[j]=vxa[j-1]+(dt/(2.0*m))*(m*axa[j]+m*axa[j-1]);

        ya[j]=ya[j-1]+dt*vya[j-1]+((dt*dt)/(2.0*m))*m*aya[j-1];

        vya[j]=vya[j-1]+(dt/(2.0*m))*(m*aya[j]+m*aya[j-1]);

        xb[j]=xb[j-1]+dt*vxb[j-1]+((dt*dt)/(2.0*m))*m*axb[j-1];

        vxb[j]=vxb[j-1]+(dt/(2.0*m))*(m*axb[j]+m*axb[j-1]);

        yb[j]=yb[j-1]+dt*vyb[j-1]+((dt*dt)/(2.0*m))*m*ayb[j-1];

        vyb[j]=vyb[j-1]+(dt/(2.0*m))*(m*ayb[j]+m*ayb[j-1]);

        r[j]=sqrt((xa[j]-xb[j])*(xa[j]-xb[j])+(ya[j]-yb[j])*(ya[j]-yb[j]));
    }

    for(i=0; i<=step; i++){
        printf("%10lf   %10lf   %10lf\n",dt*i,xa[i],ya[i]);
    }
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");

    for(i=0; i<=step; i++){
        printf("%10lf   %10lf   %10lf\n",dt*i,xb[i],yb[i]);
    }
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");

    for(i=0; i<=step; i++){
        printf("%10lf   %10lf   %10lf\n",dt*i,vxa[i],vxb[i]);
    }
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");

    for(i=0; i<=step; i++){
        printf("%10lf   %10lf   %10lf\n",dt*i,vya[i],vyb[i]);
    }
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");

    for(i=0; i<=step; i++){
        printf("%10lf   %10lf\n",dt*i,r[i]);
    }
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");        
}
