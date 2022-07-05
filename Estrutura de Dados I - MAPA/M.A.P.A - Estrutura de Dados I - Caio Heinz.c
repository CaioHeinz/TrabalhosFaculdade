#include<stdio.h>
#define QTD 9999
#define MAX 6
#include <locale.h>

void dijkstra(float G[MAX][MAX],int n,int inicial);

int main(){
  int i,j,u,l,p;
  float G[MAX][MAX];
  setlocale (LC_ALL, "Portuguese");

  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      G[l][p] = -1;
    }
  }
  G[0][1]= 0; 
  G[1][2]= 13.192;
  G[1][3]= 6.596;
  G[2][4]= 0;
  G[2][5]= 46.172;
  G[3][2]= 6.596;
  G[3][5]= 26.384;
  G[4][5]= 46.172;

  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      printf( "%.3f,",G[l][p]);
    }
    printf("\n");
  }
  printf("\n*=*=**=*=**=*=**=*=**=*=**=*=**=*=**=*=*");
  printf("\nInforme qual ser� o caminho inicial: ");
  scanf("%d",&u-1);
  dijkstra(G,MAX,u);
/*Caio bonito*/ 
  return 0;
}

void dijkstra(float G[MAX][MAX],int n,int inicial)
{
  double pred[n], custo[n][n], distanciamin;
  float distancia[n];
  int visitado[n],cont,proxno,i,j;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==-1)
        custo[i][j]=QTD;
      else
        custo[i][j]=G[i][j];

  for(i=0;i<n;i++){
    distancia[i]=custo[inicial][i];
    pred[i]=inicial;
    visitado[i]=0;
  }

  distancia[inicial]=0;
  visitado[inicial]=1;
  cont=1;

  while(cont<n-1){
    distanciamin=QTD;
    for(i=0;i<n;i++)
      if(distancia[i]<distanciamin&&!visitado[i]){
        distanciamin=distancia[i];
        proxno=i;
      }
     visitado[proxno]=1;
     for(i=0;i<n;i++){
      if(!visitado[i])
        if(distanciamin+custo[proxno][i]<distancia[i]){
          distancia[i]=distanciamin+custo[proxno][i];
          pred[i]=proxno;
        }
      }
      cont++;
    }
    for(i=0;i<n;i++)
      if(i!=inicial){
    	 printf("\n");
         printf("\nDist�ncia do caminho %d = %.3f",i,distancia[i]);
		 printf("\nCaminho = %d" ,i);
         j=i; 
    		do{
        	j=pred[j];
        	printf("<-%d",j);
        	}
			while(j!=inicial);
        }
}
