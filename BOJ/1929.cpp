#include <iostream>
#include <cstring>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  int v[1000001];
  memset(v, 0, sizeof(v));

  for(int i = 2; i < M+1; i++){
    int a = i;
    while(a <= M){
      v[a] = v[a] + 1;
      a = a + i;
    }
  }

  // cout << v[1] << " ";

  for(int i = N; i < M+1; i++){
    if(v[i] == 1){
      cout << i << '\n';
    }
  }

  return 0;
}
