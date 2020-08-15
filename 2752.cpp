#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v;

  for(int i = 0; i < 3; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < 3; i++){
    if(i == 2){
      cout << v[i] << '\n';
    }
    else{
      cout << v[i] << " ";
    }
  }

  return 0;
}
