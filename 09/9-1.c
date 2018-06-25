#include<stdio.h>

int rule(int cell1,int cell2,int cell3);

int main(void){
  int t,i;
  int cell[100];
  int tempcell[100];

  FILE *fp;
  fp=fopen("CA.csv","w");

  for(i=0;i<100;i++){
    cell[i]=0;
    tempcell[i]=0;
  }

  for(i=0;i<100;i++){
    if(i%2==0){
      cell[i]=1;
    }
  }
  for(i=0;i<100;i++){
    fprintf(fp,"%d",cell[i]);
    if(i!=99){
      fprintf(fp,",");
    }
  }
  fprintf(fp,"\n");

  for(t=1;t<100;t++){

    tempcell[0]=rule(cell[99],cell[0],cell[1]);

    for(i=1;i<99;i++){
      tempcell[i]=rule(cell[i-1],cell[i],cell[i+1]);
    }

    tempcell[99]=rule(cell[98],cell[99],cell[0]);

    for(i=0;i<100;i++){
      cell[i]=tempcell[i];
      fprintf(fp,"%d",cell[i]);
      if(i!=99){
        fprintf(fp,",");
      }
    }
    fprintf(fp,"\n");

  }

  fclose(fp);
  return 0;
}

int rule(int cell1,int cell2,int cell3){
  if((cell1==cell2)&&(cell3==cell2)){
    return cell2;
  }
  else{
    return 1-cell2;
  }
}
