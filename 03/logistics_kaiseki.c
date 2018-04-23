#include<stdio.h>
#include<math.h>

int main(void){
  double r,k,x,x0,xx,xa,dt;
  int i;
  r=1.2;
  k=100.0;
  x0=10.0;
  dt=0.001;
  x=x0;
  xa=x0;

  FILE *fp;
  fp=fopen("logistics_kaiseki.dat","w");
  fprintf(fp,"%f, %f, %f\n",0.0,xa,x);

  for(i=1;i<10000;i++){
    xa=k/(1+((k/x0)-1)*exp(-r*dt*i));//解析解
    xx=x+dt*r*(1-(x/k))*x;//オイラーの近似解
    x=xx;
    fprintf(fp,"%f, %f, %f\n",dt*i,xa,x);
  }

  fclose(fp);
  return 0;
}
