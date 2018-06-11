#include<stdio.h>
#define N 100

int main(void){

  int i,j;
  int cell[N][N];

  FILE *infile;
  infile=fopen("CGL.csv","r");

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      fscanf(infile,"%d",&cell[i][j]);
      printf("%d",cell[i][j]);
      if(j<N){
        fscanf(infile,",");
      }
    }
  }

  fclose(infile);
  return 0;

}
