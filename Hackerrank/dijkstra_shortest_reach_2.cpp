#include <cstdio>    // In Hackerrank, c libraries are recommended
#include <vector>
using namespace std;

// Restrictions in the Hackerrank problem
const int MAX_SIZE = 3000;
int matrix[MAX_SIZE][MAX_SIZE];

// Dijkstra's algorithm for minimum path between one node and the others
void DijkstraShortestReach(int matrix[MAX_SIZE][MAX_SIZE], int S, int** solution, int test){
   // Some initializations...
   int N = solution[test][0];
   vector<int> distances(N, -1);
   vector<bool> used(N, false);
   distances[S-1] = 0;

   int min, selected;

   // Main loop which selects one node from the ones that haven't been used
   for (int i=0; i<N-1; ++i){
      min = -1;

      // Look for the node not used with the minimum path from first node
      for (int j=0; j<N; ++j){
         if ((min==-1 && !used[j]) || (distances[j]<min && !used[j] && distances[j]!=-1)){
            min = distances[j];
            selected = j;
         }
      }

      used[selected] = true;     // Mark the selected node as used

      // Update the distance of the adjacents nodes that haven't been used
      // and also have a length lower than the previous one.
      for (int j=0; j<N; ++j){
         if (!used[j] && matrix[selected][j]!=-1 && distances[selected]!=-1 &&
            (distances[selected]+matrix[selected][j]<distances[j] || distances[j]==-1)){
            distances[j] = distances[selected] + matrix[selected][j];
         }
      }
   }

   // Put the solutions for the Hackerrank problem output
   for (int i=1; i<=N; ++i){
      if (i<S){
         solution[test][i] = distances[i-1];
      }
      else if (i>S){
         solution[test][i-1] = distances[i-1];
      }
   }
}

// Read the matrix
void ReadCase(int M, int matrix[MAX_SIZE][MAX_SIZE]){
   int x, y, r;

   for (int i=0; i<M; ++i){
      scanf("%d", &x);
      scanf("%d", &y);
      scanf("%d", &r);
      matrix[x-1][y-1] = matrix[y-1][x-1] = (matrix[x-1][y-1]==-1 || matrix[x-1][y-1]>r) ? r : matrix[x-1][y-1];
   }
}

int main(){
   int T, N, M, x, y, r, S;
   scanf("%d", &T);
   int** solution = new int*[T];

   for (int i=0; i<MAX_SIZE; ++i){
      for (int j=0; j<MAX_SIZE; ++j){
         matrix[i][j] = -1;
      }
   }

   // Loop through every test
   for (int i=0; i<T; ++i){
      scanf("%d", &N);
      scanf("%d", &M);
      solution[i] = new int[N];
      solution[i][0] = N;

      for (int j=1; j<N; ++j){
         solution[i][j] = -1;
      }
      ReadCase(M, matrix);

      scanf("%d", &S);

      DijkstraShortestReach(matrix, S, solution, i);

      // Return the matrix to its original initialization
      for (int j=0; j<N; ++j){
         for (int k=0; k<N; ++k){
            matrix[j][k] = -1;
         }
      }
   }

   // Print final output
   for (int i=0; i<T; ++i){
      for (int j=1; j<solution[i][0]; ++j){
         printf("%d ", solution[i][j]);
      }
      printf("\n");
   }
}
