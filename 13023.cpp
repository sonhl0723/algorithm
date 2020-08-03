#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool visit[2000], ans;
vector<int> v[2000];

void dfs(int start, int friend_count){
  if(friend_count == 5){
    ans = true;
    return;
  }

  visit[start] = true;

  for(int i = 0; i < v[start].size(); i++){
    int next = v[start][i];
    if(visit[next]){
      continue;
    }
    dfs(next, friend_count + 1);
    if(friend_count == 5){
      ans = true;
      return;
    }
  }

  visit[start] = false;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;

  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  for(int j = 0; j < N; j++){
    memset(visit, false, sizeof(visit));

    dfs(j, 1);

    if(ans){
      break;
    }

  }

  if(ans){
    cout << "1" << '\n';
  }
  else{
    cout << "0" << '\n';
  }

  return 0;
}
