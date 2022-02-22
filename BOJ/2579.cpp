#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  long long A[301][2];
  A[0][0] = 0;
  A[0][1] = 0;

  for(int i = 1; i < T + 1; i++){
    int a;
    cin >> a;
    A[i][0] = a;
    A[i][1] = 0;
  }

  A[1][1] = A[1][0];
  long long ans = 0;

  for(int j = 2; j < T + 1; j++){
    long long shelter = A[j][0];
    A[j][0] = max(A[j-2][0], A[j-2][1]) + shelter;
    A[j][1] = A[j-1][0] + shelter;
  }

  cout << max(A[T][0], A[T][1]) << '\n';

  return 0;
}
