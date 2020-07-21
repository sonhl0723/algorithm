#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v[1000001];
  int N;

  cin >> N;

  v[1] = 0;

  for(int i=2; i <= N; i++){
    v[i] = v[i-1] + 1;

    if(i % 3 == 0 && v[i] > v[i / 3] + 1){
      v[i] = v[i / 3] + 1;
    }

    if(i % 2 == 0 && v[i] > v[i / 2] + 1){
      v[i] = v[i / 2] + 1;
    }

  }

  cout << v[N] << '\n';

  return 0;
}
