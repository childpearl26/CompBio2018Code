#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int i,j;
  int t;
  double dt=0.01;
  double u[100][100],v[100][100];
  double utemp[100][100],vtemp[100][100];

  double Du=0.4;
  double Dv=1.4;

  FILE *fpu,*fpv;

  fpu=fopen("11-2u.csv","w");
  fpv=fopen("11-2v.csv","w");

  srand(time(NULL));

  //初期化
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      u[i][j]=1.0;
      v[i][j]=1.0;
    }
  }

  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      if(rand()%2==0){
        u[i][j]=1.01;
        v[i][j]=1.01;
      }
    }
  }

/*
  u[49][49]=1.1;
  u[49][50]=1.1;
  u[50][49]=1.1;
  u[50][50]=1.1;

  v[49][49]=1;
  v[49][50]=1;
  v[50][49]=1;
  v[50][50]=1;
  */

  //初期値出力
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      fprintf(fpu,"%f",u[i][j]);
      fprintf(fpv,"%f",v[i][j]);
      if(j!=99){
        fprintf(fpu,",");
        fprintf(fpv,",");
      }
    }
    fprintf(fpu,"\n");
    fprintf(fpv,"\n");
  }

  for(t=1;t<5000;t++){

    //境界条件
    //i=0,j=0
    i=0;
    j=0;
    utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);

    //i=0,j=99
    i=0;
    j=99;
    utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);

    //i=99,j=0
    i=99;
    j=0;
    utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[0][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);

    //i=99,j=99
    i=99;
    j=99;
    utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);

    //i=0
    i=0;
    for(j=1;j<99;j++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

    //i=99
    i=99;
    for(j=1;j<99;j++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

    //j=0
    j=0;
    for(i=1;i<99;i++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

    //j=99
    j=99;
    for(i=1;i<99;i++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

    //その他
    for(i=1;i<99;i++){
      for(j=1;j<99;j++){
        utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]/v[i][j]-u[i][j]);
        vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+u[i][j]*u[i][j]-v[i][j]);
      }
    }

    //更新
    for(i=0;i<100;i++){
      for(j=0;j<100;j++){
        u[i][j]=utemp[i][j];
        v[i][j]=vtemp[i][j];
      }
    }

    //出力
    if(t%500==0){
      for(i=0;i<100;i++){
        for(j=0;j<100;j++){
          fprintf(fpu,"%f",u[i][j]);
          fprintf(fpv,"%f",v[i][j]);
          if(j!=99){
            fprintf(fpu,",");
            fprintf(fpv,",");
          }
        }
        fprintf(fpu,"\n");
        fprintf(fpv,"\n");
      }
    }
  }

  fclose(fpu);
  fclose(fpv);
  return 0;
}
