#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> v[N];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int a;
      cin >> a;
      if(j == 0){
        v[i].push_back(a);
      }
      else{
        v[i].push_back(a + v[i][j-1]);
      }
    }
  }

  while(M--){
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    int ans = 0;

    for(int i = 0; i < y2-y1+1; i++){
      if(x1 == x2){
        if(x1 == 1){
          ans = ans + v[y1 - 1 + i][x2-1];
        }
        else{
          ans = ans + (v[y1 - 1 + i][x2-1] - v[y1 - 1 + i][x2-2]);
        }
      }
      else{
        if(x1 == 1){
          ans = ans + v[y1 - 1 + i][x2-1];
        }
        else{
          ans = ans + (v[y1 - 1 + i][x2-1] - v[y1 - 1 + i][x1-2]);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
