#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

int n;
int arr[101][101];
int visit[101];
queue<int> q;

void bfs(int check){
  q.push(check);

  while(!q.empty()){
    int top = q.front();
    q.pop();

    for(int i = 1; i <= n; i++){
      if(arr[top][i] && !visit[i]){
        q.push(i);
        visit[i] = visit[top] + 1;
      }
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int start, end, Testcase;
  cin >> start >> end >> Testcase;

  memset(arr, 0, sizeof(arr));

  for(int i = 0; i < Testcase; i++){
    int a, b;
    cin >> a >> b;

    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  memset(visit, 0, sizeof(visit));

  bfs(start);

  if(visit[end] == 0){
    cout << "-1" << '\n';
  }
  else{
    cout << visit[end] << '\n';
  }

  return 0;
}
