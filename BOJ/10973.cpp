#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  string str;
  vector<int> v;
  string clean_str;
  string tmp;

  cin >> N;

  while(N--){
    int a;

    cin >> a;

    v.push_back(a);
  }

  if(!prev_permutation(v.begin(), v.end())){
    cout << "-1" << '\n';
  }
  else{
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
