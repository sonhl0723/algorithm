#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> v;

int Cal(int input){
  int calculation = 0;
  for(int i = 0; i < v.size(); i++){
    calculation = calculation + (v[i] / input);
  }
  return calculation;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int K, N;
  cin >> K >> N;

  for(int i= 0; i < K; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  long long bottom = 0;
  long long top = pow(2, 31) - 1;
  long long mid = 0;
  long long count = 0;
  long long ans = 0;


  while(bottom <= top){
    mid = (top + bottom) / 2;
    count = Cal(mid);

    if(count >= N){
      ans = max(ans, mid);
      bottom = mid + 1;
    }
    else{
      // ans = mid;
      top = mid - 1;
    }
  }

  cout << ans <<'\n';


  return 0;
}
