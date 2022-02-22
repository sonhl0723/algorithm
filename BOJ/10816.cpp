#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N;

  vector<int> v1;
  vector<int> v2;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    v1.push_back(a);
  }

  cin >> M;
  for(int i = 0; i < M; i++){
    int b;
    cin >> b;
    v2.push_back(b);
  }

  sort(v1.begin(), v1.end());

  for(int i = 0; i < M; i++){
    cout << upper_bound(v1.begin(), v1.end(), v2[i]) - lower_bound(v1.begin(), v1.end(), v2[i]) << " ";
  }

  return 0;
}
