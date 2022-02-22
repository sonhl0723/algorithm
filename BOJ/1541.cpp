#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string Test;
  getline(cin, Test);
  int sum = 0;
  queue<int> q1, q2;
  int ans = 0;

  for(int i = 0; i < Test.length(); i++){
    if(Test[i] == '-'){
      while(!q2.empty()){
        sum = sum + q2.front();
        q2.pop();
      }
      q1.push(sum);
      sum = 0;
      continue;
    }
    else if(Test[i] == '+'){
      q2.push(sum);
      sum = 0;
      continue;
    }

    int a = Test[i] - '0';
    sum = (sum*10) + a;

    if(i == Test.length()-1){
      q2.push(sum);
      sum = 0;
      while(!q2.empty()){
        sum = sum + q2.front();
        q2.pop();
      }
      q1.push(sum);
    }

    // cout << sum << " ";
  }

  if(q1.empty()){
    sum = 0;
    while(!q2.empty()){
      sum = sum + q2.front();
      q2.pop();
    }
    ans = sum;
  }

  int check_f = 0;

  while(!q1.empty()){
    if(check_f == 0){
      ans = q1.front();
      q1.pop();
      check_f++;
      continue;
    }
    ans = ans - q1.front();
    q1.pop();
  }

  cout << ans << '\n';


  return 0;
}
