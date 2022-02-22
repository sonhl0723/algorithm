#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
bool check[51][51];
int arr[51][51];
int ans = 0;
int w, h;

void dfs(int check_x, int check_y){
  for(int i = 0; i < 8; i++){
    int next_x = check_x + dx[i];
    int next_y = check_y + dy[i];

    if(next_x < 0 || next_y < 0 || next_x >= w || next_y >= h){
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

  while(1){
    cin >> h >> w;

    if(w == 0 && h == 0){
      return 0;
    }

    memset(check, 0, sizeof(check));
    memset(arr, 0, sizeof(arr));

    int land;

    for(int i = 0; i < w; i++){
      for(int j = 0; j < h; j++){
        cin >> land;
        arr[i][j] = land;
      }
    }

    for(int i = 0; i < w; i++){
      for(int j = 0; j < h; j++){
        if(arr[i][j] && !check[i][j]){
          ans++;
          check[i][j] = 1;
          dfs(i, j);
        }
      }
    }

    cout << ans << '\n';
    ans = 0;
  }

  return 0;
}
