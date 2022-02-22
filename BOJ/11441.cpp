#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> v;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;

    if(i == 0){
      v.push_back(a);
    }
    else{
      int sum = a + v[i-1];
      v.push_back(sum);
    }
  }
  // cout << '\n';
  // for(int i = 0; i < v.size(); i++){
  //   cout << v[i] << " ";
  // }
  // cout << '\n';

  int M;
  cin >> M;

  while(M--){
    int start, end;
    cin >> start >> end;

    int ans = 0;

    if(start == end && start == 1){
      ans = v[end-1];
    }
    else if(start == end){
      ans = v[end-1] - v[end-2];
    }
    else if(start == 1){
      ans = v[end-1];
    }
    else{
      ans = v[end-1] - v[start-2];
    }

    cout << ans << '\n';
  }

  return 0;
}
