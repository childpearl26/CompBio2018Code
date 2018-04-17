#include<stdio.h>

int main(void){

  double X1,X2,r,K;
  int t;
  FILE *fp;

  r=3.0;
  K=100.0;
  t=0;

  fp=fopen("output.dat","w");
  if(fp==NULL){
    printf("error\n");
  }

  X1=10.0;

  for(t=0;t<50;t++){
    X2=X1+r*(1.0-X1/K)*X1;
    fprintf(fp,"%.1f\n",X2);
    X1=X2;
  }

  fclose(fp);

  printf("COMPLETE\n");

  return 0;

}
