#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v1, v2;

bool comp(long long a, long long b){
  return a > b;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, test_case;
  cin >> T;

  for(test_case = 0; test_case < T; test_case++){
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < (N * 2); i++){
      long long menu;
      cin >> menu;
      if(i < N){
        v1.push_back(menu);
      }
      else{
        v2.push_back(menu);
      }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    reverse(v2.begin(), v2.begin() + K);

    long long Answer = 0;

    for(int i = 0; i < K; i++){
      Answer = max(v1[i] + v2[i], Answer);
    }

    cout << "Case #" << test_case+1 << endl;
    cout << Answer << endl;

    v1.clear();
    v2.clear();
  }

  return 0;
}
