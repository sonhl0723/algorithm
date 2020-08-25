#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> v;
  pair<int, int> p;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;

    v.push_back(a);
  }

  int start = 0;
  int end = v.size()-1;
  int ans = 200000001;
  int sum;

  while(start < end){
    if(ans == 0){
      break;
    }

    sum = v[start] + v[end];

    ans = min(abs(ans), abs(sum));

    if(ans == abs(sum)){
      p = make_pair(start, end);
    }

    if(sum > 0){
      end--;
    }
    else if(sum == 0){
      ans = sum;
      break;
    }
    else{
      start++;
    }
  }

  cout << v[p.first] + v[p.second] << '\n';

  return 0;
}
