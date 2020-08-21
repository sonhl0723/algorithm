#include <iostrea>
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
    cin >> x1 >> y1 >> x2 >> y2;

    int ans;

    for(int i = x1-1; i < x2 - x1 + 1; i++){
      int ans += v[y1-1][i]
    }
  }

  return 0;
}
