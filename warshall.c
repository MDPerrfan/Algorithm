#include<stdio.h>
int n;
void warshall(int graph[][n]){
    int matrix[n][n],i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j]=graph[i][j];
        }
    }
    for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][n]) {
    printf("The final Matrix is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 999)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    int graph[n][n];
    printf("\nEnter the values in matrix:(Infinity=999)\n");
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d",&graph[i][j]);
    }
   }
  warshall(graph);
}



