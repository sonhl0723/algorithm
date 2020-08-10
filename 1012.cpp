#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool check[51][51];
int arr[51][51];
int ans = 0;
int N, M;

void dfs(int check_x, int check_y){
  for(int i = 0; i < 4; i++){
    int next_x = check_x + dx[i];
    int next_y = check_y + dy[i];

    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M){
      continue;
    }

    if(arr[next_x][next_y] && !check[next_x][next_y]){
      check[next_x][next_y] = 1;
      dfs(next_x, next_y);
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while(T--){
    int cabbage;
    cin >> N >> M >> cabbage;

    memset(check, 0, sizeof(check));
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < cabbage; i++){
      int x, y;
      cin >> x >> y;

      arr[x][y] = 1;
    }

    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        if(arr[j][k] && !check[j][k]){
          ans++;
          check[j][k] = 1;
          dfs(j, k);
        }
      }
    }
    cout << ans << '\n';
    ans = 0;
  }

  return 0;
}
