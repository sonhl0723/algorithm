#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
bool check[101][101];
queue<int> q;
int step[101];

void bfs(int start){
  q.push(start);
  step[start] = step[start] + 1;
  while(!q.empty()){
    int q_size = q.size();
    while(q_size--){
      int current = q.front();
      q.pop();
      for(int i = 1; i < N+1; i++){
        if(check[current][i] != 1 || step[i] >= 0){
          continue;
        }
        q.push(i);
        step[i] = step[current] + 1;
      }
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  memset(check, 0, sizeof(check));

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;

    if(!check[a][b] || !check[b][a]){
      check[a][b] = 1;
      check[b][a] = 1;
    }
  }

  int min = 1000000000;
  int real_ans = 0;

  for(int i = 1; i < N+1; i++){
    memset(step, -1, sizeof(step));
    bfs(i);
    int sum = 0;
    for(int j = 1; j < N+1; j++){
      sum = sum + step[j];
    }
    if(sum < min){
      min = sum;
      real_ans = i;
    }
  }

  cout << real_ans << '\n';

  return 0;
}
