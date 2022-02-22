#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
bool check[101][101];
int step[101];
queue<int> q;

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

  cin >> N >> K;

  memset(check, 0, sizeof(check));

  for(int i = 0; i < K; i++){
    int a, b;
    cin >> a >> b;

    check[a][b] = 1;
    check[b][a] = 1;
  }

  int ans = 0;

  for(int i = 1; i < N+1; i++){
    memset(step, -1, sizeof(step));
    bfs(i);
    for(int j = 1; j < N+1; j++){
      if(step[j] < 0 || step[j] > 6){
        ans = 1;
        break;
      }
    }
  }

  if(ans == 1){
    cout << "Big World!" << '\n';
  }
  else{
    cout << "Small World!" << '\n';
  }

  return 0;
}
