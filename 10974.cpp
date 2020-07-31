#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  vector<int> v;

  cin >> N;

  for(int i = 1; i <= N; i++){
    v.push_back(i);
    if(i == N){
      cout << i << '\n';
    }
    else{
      cout << i << ' ';
    }
  }

  while(next_permutation(v.begin(), v.end())){
    for(int j = 0; j < v.size(); j++){
      if(j == v.size()-1){
        cout << v[j] << '\n';
      }
      else{
        cout << v[j] << ' ';
      }
    }
  }

  return 0;
}
