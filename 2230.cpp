#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  int result = 0;

  cin >> N >> M;

  int A[N + 1];

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    A[i] = a;
    for(int j = 0; j <= i; j++){
      if(result == 0 && abs(A[j] - A[i]) >= M){
        result = abs(A[j] - A[i]);
      }
      else if(abs(A[j] - A[i]) >= M){
        result = min(result, abs(A[j] - A[i]));
      }
    }
  }

  cout << result << '\n';

  return 0;
}
