#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>


using namespace std;

vector<int> v[101];
bool check[101];
int count_E = 0;

void dfs(int index, int count){
  check[index] = true;

  for(int i = 0; i < v[index].size(); i++){
    int next = v[index][i];
    if(check[next]){
      continue;
    }

    dfs(next, count+1);
    count_E++;
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;

  cin >> N >> M;

  while(M--){
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  memset(check, false, sizeof(check));

  dfs(1, 1);

  cout << count_E << '\n';

  return 0;
}
