#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<int> v[1001];
bool visit[1001];


void dfs(int start){
  visit[start] = 1;

  for(int i = 0; i < v[start].size(); i++){
    int next = v[start][i];

    if(visit[next]){
      continue;
    }

    cout << next << " ";
    dfs(next);
  }
}

void bfs(int start){
  queue<int> q;
  q.push(start);
  visit[start] = 1;

  while(!q.empty()){
    start = q.front();
    cout << start << " ";
    q.pop();

    for(int i = 0; i < v[start].size(); i++){
      int next = v[start][i];
      if(visit[next]){
        continue;
      }
      q.push(next);
      visit[next] = 1;
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  for(int i = 1; i < N+1; i++){
    sort(v[i].begin(), v[i].end());
  }

  memset(visit, 0, sizeof(visit));

  cout << V << " ";
  dfs(V);
  cout << '\n';

  memset(visit, 0, sizeof(visit));

  bfs(V);
  cout << '\n';

  return 0;
}
