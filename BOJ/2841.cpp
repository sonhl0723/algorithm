#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, P;
  vector< stack<int> > v(7);
  int sum = 0;

  cin >> N >> P;

  while(N--){
    int n, p;

    cin >> n >> p;

    if(v[n].empty() || sum == 0){
      v[n].push(p);
      sum = sum + 1;
    }
    else{
      while(v[n].top() > p){
        v[n].pop();
        sum = sum + 1;
        if(v[n].empty()){
          v[n].push(p);
          sum = sum + 1;
          break;
        }
      }
      if(v[n].top() < p){
        v[n].push(p);
        sum = sum + 1;
      }
    }
  }

  cout << sum << '\n';

  return 0;
}
