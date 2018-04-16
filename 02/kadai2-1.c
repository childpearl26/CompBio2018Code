#include<stdio.h>

void main(){

  int X1,X2,r,K,t;
  FILE *fp;

  X1=5;
  r=2;
  K=200;
  t=0;

  fp=fopen("output.dat","a");
  if(fp==NULL){
    printf("error\n");
  }

  fprintf(fp,"%d,%d\n",t,X2);

  for(t=0;t<300;t++){
    X2=X1+r*(1-x/k)*X1;
    fprintf(fp,"%d,%d\n",t,X2);
  }

  fclose(fp);

}
