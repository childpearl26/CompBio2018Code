#include<stdio.h>
#define N 100

int lifegame(int cell1,int cell2,int cell3,
  int cell4,int cell5,int cell6,
  int cell7,int cell8,int cell9);

int main(void){

  int i,j;
  int cell[N][N];
  int tempcell[N][N];

  FILE *infile,*outfile;
  infile=fopen("test.csv","r");

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      fscanf(infile,"%d",&cell[i][j]);
      if(j<N){
        fscanf(infile,",");
      }
    }
  }

  fclose(infile);

  //境界条件処理(固定端)
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if((i==0)||(i==N-1)||(j==0)||(j==N-1)){
        tempcell[i][j]=0;
      }
    }
  }

  //実行
  for(i=1;i<N-1;i++){
    for(j=1;j<N-1;j++){
      tempcell[i][j]=lifegame(cell[i-1][j-1],cell[i-1][j],cell[i-1][j+1],
        cell[i][j-1],cell[i][j],cell[i][j+1],
        cell[i+1][j-1],cell[i+1][j],cell[i+1][j+1]);
    }
  }

  outfile=fopen("test.csv","w");

  //テスト

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      fprintf(outfile,"%d",cell[i][j]);
      if(j<N){
        fprintf(outfile,",");
      }
    }
    fprintf(outfile,"\n");
  }

  fprintf(outfile,"\n");

  //出力

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      fprintf(outfile,"%d",tempcell[i][j]);
      if(j<N){
        fprintf(outfile,",");
      }
    }
    fprintf(outfile,"\n");
  }

  fclose(outfile);

  return 0;
}

int lifegame(int cell1,int cell2,int cell3,
  int cell4,int cell5,int cell6,
  int cell7,int cell8,int cell9){

  int sum;
  sum=cell1+cell2+cell3+cell4+cell6+cell7+cell8+cell9;
  if(sum<=1){
    return 0;
  }
  else if(sum==2){
    return cell5;
  }
  else if(sum==3){
    return 1;
  }
  else{
    return 0;
  }
}
