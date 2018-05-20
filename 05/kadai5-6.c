#include<stdio.h>
#include<math.h>

int main(void){

  int i;
  double N=200.0;
  double t,p,dp=0.00001;
  FILE *fp;

  fp=fopen("kadai5-6.dat","w");

  for(p=dp;p<=1.0;p+=dp){
    t=-(2*N*(1-p)*log(1-p))/p;
    fprintf(fp,"%f,%f\n",p,t);
  }

  printf("complete\n");
  fclose(fp);

}
