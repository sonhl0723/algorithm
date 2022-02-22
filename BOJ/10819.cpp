#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  vector<int> v;

  cin >> N;

  while(N--){
    int a;

    cin >> a;

    v.push_back(a);
  }

  sort(v.begin(), v.end());

  int sum = 0;
  int tmp = 0;

  for(int i = 1; i <= v.size(); i++){
    sum += abs(v[i-1] - v[i]);
  }

  while(next_permutation(v.begin(), v.end())){
    for(int i = 1; i <= v.size()-1; i++){
      tmp += abs(v[i-1] - v[i]);
    }
    sum = max(sum, tmp);
    tmp = 0;
  }

  tmp = 0;

  for(int i = 1; i <= v.size()-1; i++){
    tmp += abs(v[i-1] - v[i]);
  }
  sum = max(sum, tmp);

  cout << sum << '\n';

  return 0;
}
