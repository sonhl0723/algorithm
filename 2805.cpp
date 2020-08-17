#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

long long Cal(long long input){
  long long calculation = 0;
  for(int i = 0; i < N; i++){
    if(v[i] < input){
      continue;
    }
    calculation = calculation + (v[i] - input);
  }

  return calculation;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  long long left = 0;
  long long right = v[N-1];
  long long mid = 0;
  long long count = 0;
  long long ans = 0;

  while(left <= right){
    mid = (left + right) / 2;
    count = Cal(mid);

    if(count >= M){
      ans = max(ans, mid);
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }

  cout << ans << '\n';


  return 0;
}
