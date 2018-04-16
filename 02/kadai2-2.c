#include<stdio.h>

int main(void){

  double X1,X2,r,K;
  int t;
  FILE *fp;

  X1=10.0;
  r=1.0;
  K=100.0;
  t=0;

  fp=fopen("output.dat","w");
  if(fp==NULL){
    printf("error\n");
  }

  for(r=1.0;r<=3.0;r+=0.001){

    //fprintf(fp,"r=%.1f\n",r);

    X1=10;

    for(t=0;t<300;t++){
      X2=X1+r*(1.0-X1/K)*X1;
      if(t>=250){
        fprintf(fp,"%.3f,%.1f\n",r,X2);
      }
      X1=X2;
    }

  }

  fclose(fp);

  printf("COMPLETE\n");

  return 0;

}
