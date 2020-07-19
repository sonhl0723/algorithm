#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;

  while(T--){
    int N, M;

    cin >> N >> M;

    long long a = M;
    long long b = M - N;
    long long result;

    if(b != 0){
      for(int i = 1; i < (M - N); i++){
        a = a * (M - i);
        b = b * ((M - N) - i);
        result = a / b;
      }
    }
    else{
      result = M / N;
    }


    cout << result << '\n';
  }

  return 0;
}
