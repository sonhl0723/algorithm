#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long P[117];

  cin >> n;

  for(int i = 0; i <= n; i++){
    if(i == 0 || i == 1 || i == 2){
      P[i] = 1;
    }
    else{
      P[i] = P[i - 1] + P[i - 3];
    }
  }

  cout << P[n - 1] << '\n';

  return 0;
}
