#include <iostream>
using namespace std;

// Generic swap function
template <class T>
inline void Swap(T &a, T &b){
   T tmp = a;
   a = b;
   b = tmp;
}

// Function that returns the number elements in the biggest ring of the matrix of size M*N
inline int CicleCount(int M, int N){
   return 2*(M+N) - 4;     // Reduction of M*N - (M-2)*(N-2)
}

// Recursive implementation that rotates the matrix R times
void RotateMatrix(int** matrix, int M, int N, int R, int offset){
   int min_rotations = R%CicleCount(M, N);   // Reduces amount of rotations per level

   // Every rotation is done in spiral (in the corresponding ring)
   for (int r=0; r<min_rotations; ++r){
      // Computes upper row
      for (int j=offset; j<N+offset-1; ++j){
         Swap(matrix[offset][j], matrix[offset][j+1]);
      }

      // Computes right column
      for (int i=offset; i<M+offset-1; ++i){
         Swap(matrix[i][N+offset-1], matrix[i+1][N+offset-1]);
      }

      // Computes lower row
      for (int j=N+offset-1; j>=offset+1; --j){
         Swap(matrix[M+offset-1][j], matrix[M+offset-1][j-1]);
      }

      // Computes left column
      for (int i=M+offset-1; i>=offset+2; --i){
         Swap(matrix[i][offset], matrix[i-1][offset]);
      }
   }

   // We compute the inner rings recursively if both sizes are bigger than 2
   if (M>2 && N>2){
      RotateMatrix(matrix, M-2, N-2, R, offset+1);
   }
}

int main(){
   int M, N, R;

   cin >> M >> N >> R;

   // Initialize the matrix with given values
   int** matrix = new int*[M];
   for (int i=0; i<M; ++i){
      matrix[i] = new int[N];

      for (int j=0; j<N; ++j){
         cin >> matrix[i][j];
      }
   }

   RotateMatrix(matrix, M, N, R, 0);

   // Print rotated matrix
   for (int i=0; i<M; ++i){
      for (int j=0; j<N; ++j){
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
}
