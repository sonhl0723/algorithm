#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> v;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;

    if(i == 0){
      v.push_back(a);
    }
    else{
      v.push_back(a + v[i-1]);
    }
  }

  for(int i = 0; i < M; i++){
    int start, end;
    cin >> start >> end;
    int ans;

    if(start == 1){
      ans = v[end-1];
    }
    else{
      ans = v[end-1] - v[start-2];
    }

    cout << ans << '\n';
  }

  return 0;
}
