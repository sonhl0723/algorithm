#include <iostream>
#include <cstdio>

using namespace std;

int Combination(int a, int b){
  if(a == b || b == 0){
    return 1;
  }
  else{
    return Combination(a - 1, b - 1) + Combination(a - 1, b);
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  int ans = Combination(N, K);

  cout << ans << '\n';

  return 0;
}
