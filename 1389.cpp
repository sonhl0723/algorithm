#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool check[101][101];
int ans;
queue<int> q;
int sum[101];

void bfs(int index){
  for(int i = 1; i < N+1; i++){
    q.push(i);
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;

    if(!check[a][b] || !check[b][a]){
      check[a][b] = 1;
      check[b][a] = 1;
    }
  }

  for(int i = 1; i < N+1; i++){
    memset(sum, -1, sizeof(sum));
    bfs(i);

  }
  return 0;
}
