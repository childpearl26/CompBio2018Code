#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void){
  FILE *fp;
  fp=fopen("13-1.csv","w");

  int i;
  double t,tt;
  double x[3],xx[3];
  double beta,gamma;
  double e[3];
  double ran,ran2;

  beta=0.000001;
  gamma=0.001;
  x[0]=10000;
  x[1]=1;
  x[2]=0;
  t=0;

  fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);
  srand(time(NULL));

  //各イベントの確率を設定
  for(i=1;i<=20000;i++){
    e[1]=beta*x[0]*x[1];
    e[2]=gamma*x[1];
    e[0]=e[1]+e[2];

    //次のイベントまでのタイムステップを設定
    ran=(double)rand()/RAND_MAX;
    while((ran==0)||(ran==1)){
      ran=(double)rand()/RAND_MAX;
    }
    tt=t+log(1/ran)/e[0];
    t=tt;

    //確率に応じてイベントを設定
    ran2=(double)rand()/RAND_MAX;

    if(ran2<=e[1]/e[0]){
      xx[0]=x[0]-1;
      x[0]=xx[0];
      xx[1]=x[1]+1;
      x[1]=xx[1];
    }
    else{
      xx[1]=x[1]-1;
      x[1]=xx[1];
      xx[2]=x[2]+1;
      x[2]=xx[2];
    }
    if((x[0]==0)||(x[1]==0)){
      break;
    }

    fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);

  }

  fclose(fp);
  return 0;

}
