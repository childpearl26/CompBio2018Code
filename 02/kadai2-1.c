#include<stdio.h>

int main(void){

  double X,XX,r,K=100.0;
  int t=0;
  FILE *fp;

  fp=fopen("output.dat","w");

  for(r=1.0;r<=3.0;r+=0.1){
    fprintf(fp,"r=%.1f\n",r);
    X=10.0;
    for(t=0;t<50;t++){
      XX=X+r*(1.0-X/K)*X;
      fprintf(fp,"%d,%.1f\n",t,XX);
      X=XX;
    }
  }

  fclose(fp);

  printf("COMPLETE\n");
  return 0;
}
