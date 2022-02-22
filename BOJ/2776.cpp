#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  vector<int> v_1;
  vector<int> v_2;

  while(Testcase--){
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++){
      int a;
      cin >> a;
      v_1.push_back(a);
    }

    cin >> M;
    for(int i = 0; i < M; i++){
      int b;
      cin >> b;
      v_2.push_back(b);
    }

    sort(v_1.begin(), v_1.end());
    // sort(v_2.begin(), v_2.end());

    for(int i = 0; i < M; i++){
      cout << binary_search(v_1.begin(), v_1.end(), v_2[i]) << '\n';
    }

    v_1.clear();
    v_2.clear();
  }

  return 0;
}
