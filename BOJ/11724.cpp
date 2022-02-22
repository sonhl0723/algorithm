#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[1001];
bool visit[1001];
int ans = 0;
bool check = false;
int count_E = 1;


void dfs(unsigned seq, int count, int size_N){
  if(count_E == size_N){
    check = true;
    return;
  }

  visit[seq] = true;

  for(int i = 0; i < v[seq].size(); i++){
    int next = v[seq][i];
    if(visit[next]){
      continue;
    }

    count_E++;

    dfs(next, count_E, size_N);

    if(count_E == size_N){
      check = true;
      return;
    }
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

  for(int j = 1; j < N+1; j++){
    if(visit[j] != true){
      ans++;
    }
    dfs(j, count_E, N);
    if(check){
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}
