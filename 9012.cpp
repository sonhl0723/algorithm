#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  stack<char> s;
  string str;

  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> str;

    for(int j = 0; j < str.length(); j++){
      if(str[j] == '(' || str[j] == '['){
        s.push(str[j]);
      }
      else if(!s.empty()){
        if(str[j] == ')' && s.top() == '('){
          s.pop();
        }
        else if(str[j] == ']' && s.top() == '['){
          s.pop();
        }
        else{
          s.push(str[j]);
          break;
        }
      }
      else{
        s.push(str[j]);
        break;
      }
    }

    if(s.empty() == 1){
      cout << "YES" << '\n';
    }
    else{
      cout << "NO" << '\n';
      }
      while(!s.empty()){
        s.pop();
      }
    }

  return 0;
}
