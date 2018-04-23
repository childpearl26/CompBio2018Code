#include<stdio.h>

int main(void){

  double X=10,XX,r,K=100.0;
  int t;
  FILE *fp;

  r=3.0;//←ここを変化させれば好きなrについての表を得られる

  fp=fopen("output.dat","w");
  for(t=0;t<50;t++){
    XX=X+r*(1.0-X/K)*X;
    fprintf(fp,"%.1f\n",XX);
    X=XX;
  }

  fclose(fp);

  printf("COMPLETE\n");
  return 0;

}
