#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50

int main(void){
  int a[N],aa[N],i,j,t,r1,r2,r;
  srand(time(NULL));

  int k=20;//突然変異を持つ個体数
  int sum=0;//固定を判別
  int count=0;//突然変異が固定した回数を記録
  FILE *fp;

  fp=fopen("kadai5-4.dat","w");

  for(j=0;count<100;j++){

    for(i=0;i<N;i++){
      if(i<k){
        a[i]=0;
      }
      else{
        a[i]=1;
      }
    }

    for(t=0;;t++){
      for(i=0;i<N;i++){
        r1=rand()%N;
        r2=rand()%N;
        r=rand()%2;
        if(r==0){
          aa[i]=a[r1];
        }
        if(r==1){
          aa[i]=a[r2];
        }
      }
      for(i=0;i<N;i++){
        a[i]=aa[i];
      }
      sum=0;
      for(i=0;i<N;i++){
        sum+=a[i];
      }
      if(sum==0){
        fprintf(fp,"%d ",t);
        count++;
        break;
      }
      else if(sum==N){
        break;
      }
    }
  }
  fclose(fp);
  printf("complete\n");
  return 0;
}
