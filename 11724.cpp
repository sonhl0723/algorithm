#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
bool visit[1000];
vector< vector<int> > v;

void dfs(int index, int count, int ans){
  visit[index] = true;

  if(count == N){
    return;
  }

  for(int i = 0; i < v[index].size(); i++){
    cout << v[index][i];
    int next = v[index][i];
    if(visit[next]){
      continue;
    }
    dfs(next, count + 1, ans);
    if(count == N){
      return;
    }
  }

  ans = ans + 1;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int ans = 1;

  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  for(int j = 1; j < N + 1; j++){
    memset(visit, false, sizeof(visit));
    dfs(j, 1, ans);
  }

  cout << ans << '\n';

  return 0;
}
