#include <iostream>
#include <cstdio>

using namespace std;

long long Combination_Permu(int distinction, int A, int B){
  long long result;


}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;

  while(T--){
    int N, M;

    cin >> N >> M;

    cout << Combination_Permu(M - N, M, N) << '\n';
  }

  return 0;
}
