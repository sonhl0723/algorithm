#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, money;
vector<int> v;

int Cal(int input){
  int check = 0;
  for(int i = 0; i < N; i++){
    if(input >= v[i]){
      check = check + v[i];
    }
    else{
      check = check + input;
    }
  }
  return check;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  cin >> money;

  sort(v.begin(), v.end());

  long long left = 0;
  long long right = v[v.size()-1];
  long long mid = 0;
  long long ans = 0;

  while(left <= right){
    mid = (left + right) / 2;

    if(Cal(mid) <= money){
      ans = max(mid, ans);
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
