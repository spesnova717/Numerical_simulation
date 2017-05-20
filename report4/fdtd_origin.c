#include <stdio.h>
#include <math.h>
#define NX 101
#define NY 101
#define step 48
int main(){
    int i,j,k;
    double micro[NX+5][NY+5];
    double EZ[NX+5][NY+5];
    double HX[NX+5][NY+5];
    double HY[NX+5][NY+5];
    double CEZ[NX+5][NY+5];
    double CEZLX[NX+5][NY+5];
    double CEZLY[NX+5][NY+5];
    double CHXLY[NX+5][NY+5];
    double CHYLX[NX+5][NY+5];
    double taux,tauy,tau;
    double sigma = 1.0;
    double epsilon = 1.0;
    double dt = 0.01;
    double dx = 0.02;
    double dy = 0.02;
    double tau0 = 1.0;
    double alpha = (4.0/tau0) * (4.0/tau0);
    
    for(i=1;i<=NX;i++){
        for(j=1;j<=NY;j++){
            EZ[i][j]=0.0;
            HX[i][j]=0.0;
            HY[i][j]=0.0;
        }
    }

    for(j=1;j<=NY;j++){
        for(i=1;i<=NX;i++){
            micro[i][j] = 1.0;
        }
    }

    for(j=70;j<=80;j++){
        for(i=70;i<=80;i++){
            micro[i][j] = 100.0;
        }
    }

    for(j=1;j<=NY;j++){
        for(i=1;i<=NX;i++){
        CEZ[i][j]=(1.0-((sigma*dt)/(2.0*epsilon)))/(1.0+((sigma*dt)/(2.0*epsilon)));
        CEZLX[i][j]=((dt/epsilon) / (1.0+((sigma*dt)/(2.0*epsilon))))*(1.0/dx);
        CEZLY[i][j]=((dt/epsilon) / (1.0+((sigma*dt)/(2.0*epsilon))))*(1.0/dy);
        CHXLY[i][j]=(dt/micro[i][j])*(1.0/dy);
        CHYLX[i][j]=(dt/micro[i][j])*(1.0/dx);
        taux=dx*(i-1);
        tauy=dy*(j-1);
        tau=sqrt((taux-1.0)*(taux-1.0)+(tauy-1.0)*(tauy-1.0))+1.0;
        EZ[i][j]=exp(-alpha*(tau-tau0)*(tau-tau0));
        }
    }

    for(j=1;j<=NY;j++){
        printf("\n");
        for(i=1;i<=NX;i++){
            printf("%10lf",EZ[i][j]);   //Initial waveform
        }
    }
    //--------------------------------------------------------------

    for(k=1;k<=step;k++){
        for(j=2;j<=NY;j++){
            for(i=2;i<=NX;i++){
                EZ[i][j]=CEZ[i][j]*EZ[i][j]+CEZLX[i][j]*(HY[i][j]-HY[i-1][j])
                -CEZLY[i][j]*(HX[i][j]-HX[i][j-1]);
            if(EZ[i][j] <= 0.0)
                EZ[i][j]=0.0;
            }
        }

    for(j=1;j<=NY-1;j++){
        for(i=2;i<=NX-1;i++){
            HX[i][j]=HX[i][j]-CHXLY[i][j]*(EZ[i][j+1]-EZ[i][j]);
        }
    }

    for(j=2;j<=NY-1;j++){
        for(i=1;i<=NX-1;i++){
            HY[i][j]=HY[i][j]+CHYLX[i][j]*(EZ[i+1][j]-EZ[i][j]);
        }
    }    
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");

    if((k % ((step/3)))==0){

    for(j=1;j<=NY;j++){
        printf("\n");
        for(i=1;i<=NX;i++){
            printf("%10lf",EZ[i][j]);   //Initial waveform
        }
    }

    }
    }

}

