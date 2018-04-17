#include<stdio.h>

int main(void){

  double X,XX,r,K;
  int t=0;
  FILE *fp;

  r=1.0;
  K=100.0;

  fp=fopen("output.dat","w");

  for(r=1.0;r<=3.0;r+=0.001){
    X=10.0;
    for(t=0;t<300;t++){
      XX=X+r*(1.0-X/K)*X;
      if(t>=250){
        fprintf(fp,"%.3f,%.1f\n",r,XX);
      }
      X=XX;
    }
  }

  fclose(fp);

  printf("COMPLETE\n");
  return 0;
}
