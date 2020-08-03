#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool visit[1000];
vector< vector<int> > v;
int ans = 1;

void dfs(int index, int count){
  visit[index] = true;
  for(int i = 0; i < v[index].size(); i++){
    
  }
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

  memset(visit, false, sizeof(visit));

  for(int j = 1; j < N + 1; j++){
    dfs(j, ans);
  }

  cout << ans << '\n';

  return 0;
}
