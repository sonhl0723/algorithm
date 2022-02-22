#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while(T--){
    cin >> k >> n;

    for(int i = 1; i < n+1; i++){
      v.push_back(i);
    }

    for(int i = 0; i < k; i++){
      for(int j = 0; j < n+1; j++){
        if(j == 0){
          continue;
        }
        int b = v[j];
        v[j] = v[j-1] + b;
      }
    }

    cout << v[n-1] << '\n';

    v.clear();
  }

  return 0;
}
