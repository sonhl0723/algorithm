#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;

  while(T--){
    int N;
    long long P[101];

    cin >> N;

    for(int i = 0; i <= N; i++){
      if(i == 0 || i == 1 || i == 2){
        P[i] = 1;
      }
      else{
        P[i] = P[i - 3] + P[i - 2];
      }
    }

    cout << P[N - 1] << '\n';
  }

  return 0;
}
