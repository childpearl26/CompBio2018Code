#include<stdio.h>

int main(void){

  int N[20],NN[20],k[20];
  int t,i;
  int kp=0;//被りポイント
  FILE *fp;

  fp=fopen("kadai.csv","w");

  for(i=5;i<20;i++){
    N[i]=1000;
    k[i]=0;
  }//ゴネンゼミからジュウキュウネンゼミまでを設定

  for(t=1;t<1000;t++){

    for(i=5;i<20;i++){
      if(t%i==0){//その年に発生した場合
        kp++;//被りの個体数
        k[i]++;//被ってる判定
      }
    }

    for(i=5;i<20;i++){
      if(k[i]==1){
        NN[i]=(double)N[i]/kp+(double)(N[i]*(1-1/kp)*0.5);
        N[i]=NN[i];
      }
    }

    if(t%10==0){
      fprintf(fp,"%d ",t);
      for(i=5;i<20;i++){
        fprintf(fp,"%d ",N[i]);
      }
      fprintf(fp,"\n");
    }

    kp=0;
    for(i=5;i<20;i++){
      k[i]=0;
    }

  }

  fclose(fp);
  return 0;

}
