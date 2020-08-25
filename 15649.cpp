#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> v;
  vector<int> visit[100001];

  for(int i = 1; i < N+1; i++){
    v.push_back(i);
  }

  memset(visit, 0, sizeof(visit));
  int count = 0;

  do{
    for(int i = 0; i < M; i++){
      visit[count].push_back(v[i]);
    }
    if(count == 0){
      for(int i = 0; i < M; i++){
        cout << visit[count][i] << " ";
      }
      cout << '\n';
    }
    else{
      for(int i = 0; i < M; i++){
        if(visit[count][i] != visit[count-1][i]){
          for(int j = 0; j < M; j++){
            cout << visit[count][j] << " ";
          }
          cout << '\n';
          break;
        }
      }
    }
    count++;
  }while(next_permutation(v.begin(), v.end()));

  return 0;
}
