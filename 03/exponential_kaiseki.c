#include<stdio.h>
#include<math.h>

int main(void){
  double a,x,x0,xx,xa,dt;
  int i;
  a=1.2;
  x0=10.0;
  dt=0.001;
  x=x0;
  xa=x0;

  FILE *fp;
  fp=fopen("exponential_kaiseki.dat","w");
  fprintf(fp,"%f, %f, %f\n",0.0,xa,x);

  for(i=1;i<10000;i++){
    xa=x0*exp(a*dt*i);//解析解
    xx=x+dt*a*x;//オイラーの近似解
    x=xx;
    fprintf(fp,"%f, %f, %f\n",dt*i,xa,x);
  }

  fclose(fp);
  return 0;
}
