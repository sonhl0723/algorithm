#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;

  int A[N];

  for(int k = 0; k < N; k++){
    int a;
    cin >> a;
    A[k] = a;
  }

  sort(A, A + N);

  int i = 0;
  int j = 1;
  int ans = 2147483647;

  while(i < N){
    if(A[j] - A[i] < M){
      j++;
      continue;
    }

    if(A[j] - A[i] == M){
      ans = M;
      break;
    }

    if(M == 0){
      ans = A[j] - A[i];
      break;
    }

    ans = min(ans, A[j] - A[i]);
    i++;
  }

  cout << ans << '\n';

  return 0;
}
