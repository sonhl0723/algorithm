#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int K;
  int sum = 0;
  stack<int> s;

  cin >> K;

  while(K--){
    int money;
    cin >> money;

    if(money == 0){
      s.pop();
    }
    else{
      s.push(money);
    }
  }



  while(!s.empty()){
    sum = sum + s.top();
    s.pop();
  }

  cout << sum << '\n';

  return 0;
}
