#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int L, R, A;

  cin >> L >> R >> A;

  int Max_input = max(L, R);
  int Min_input = min(L, R);
  int ans;

  if(Min_input + A < Max_input){
    ans = (Min_input + A) * 2;
  }
  else{
    int gap = Max_input - Min_input;

    if(gap < A){
      A = A - gap;
      int a = A / 2;
      ans = (Max_input + a) * 2;
    }
    else{
      ans = (Min_input + gap) * 2;
    }
  }

  cout << ans << '\n';

  return 0;
}
