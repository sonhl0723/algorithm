#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B;
  vector<int> v;

  cin >> A >> B;

  string str_A = to_string(A);

  for(int i = 0; i < str_A.length(); i++){
    v.push_back(A % 10);
    A = A / 10;
  }

  sort(v.begin(), v.end());

  int ans = -1;
  str_A = to_string(A);

  do{
    if(v[0] == 0){
      continue;
    }

    str_A.clear();

    for(int i = 0; i < v.size(); i++){
      str_A += to_string(v[i]);
    }

    if(stoi(str_A) <= B){
      ans = max(ans, stoi(str_A));
    }
    else{
      break;
    }

  }while(next_permutation(v.begin(), v.end()));

  cout << ans << '\n';

  return 0;
}
