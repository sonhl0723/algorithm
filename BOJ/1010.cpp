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

    int bridge[31][31] = {0};

    for(int i = 0; i <= M; i++){
      for(int j = 0; j <= N; j++){
        if(j == 0){
          bridge[i][j] = 0;
        }
        else if(j == 1){
          bridge[i][j] = i;
        }
        else if(i == j){
          bridge[i][j] = 1;
        }
        else{
          bridge[i][j] = bridge[i - 1][j - 1] + bridge[i - 1][j];
        }
      }
    }

    cout << bridge[M][N] << '\n';
  }

  return 0;
}
