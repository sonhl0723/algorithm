#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;
vector<int> v[26];
bool visit[26][26];
vector<int> ans_v;
int ans;
int count_a = 1;

void bfs(int check_x, int check_y){
  for(int i = 0; i < 4; i++){
    int next_x = check_x + dx[i];
    int next_y = check_y + dy[i];

    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N){
      continue;
    }

    if(v[next_x][next_y] && !visit[next_x][next_y]){
      visit[next_x][next_y] = 1;
      count_a++;
      bfs(next_x, next_y);
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for(int i = 0; i < N; i++){
    string s;
    cin >> s;

    for(int j = 0; j < N; j++){
      int a = int(s[j])-48;
      v[i].push_back(a);
    }
    s.clear();
  }

  memset(visit, 0, sizeof(visit));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(v[i][j] && !visit[i][j]){
        ans++;
        visit[i][j] = 1;
        bfs(i, j);
        ans_v.push_back(count_a);
        count_a = 1;
      }
    }
  }

  sort(ans_v.begin(), ans_v.end());
  cout << ans << '\n';
  for(int i = 0; i < ans_v.size(); i++){
    cout << ans_v[i] << '\n';
  }

  return 0;
}
