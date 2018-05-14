#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int r,i,j;
  int x[5];
  srand(time(NULL));
  for(j=0;j<5;j++){
    x[j]=0;
  }
  FILE *fp;

  fp=fopen("kadai5-3.dat","w");

  for(i=0;i<100;i++){
    for(j=0;j<5;j++){
      r=rand()%2;
      if(r==0){
        x[j]=x[j]+1;
      }
      else{
        x[j]=x[j]-1;
      }
      fprintf(fp,"%d,",x[j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  printf("complete\n");
  return 0;
}
