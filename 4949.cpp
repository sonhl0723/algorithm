#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<char> s;
  char ch[101];

  while(1){
    cin.getline(ch, 101);

    if((char)ch[0] == '.'){
      break;
    }

    for(int i = 0; i < strlen(ch); i++){
      if(ch[i] == '('){
        s.push(ch[i]);
      }
      else if(ch[i] == '['){
        s.push(ch[i]);
      }
      else if(ch[i] == ')'){
        if(!s.empty() && s.top() == '('){
          s.pop();
        }
        else{
          s.push(ch[i]);
          break;
        }
      }
      else if(ch[i] == ']'){
        if(!s.empty() && s.top() == '['){
          s.pop();
        }
        else{
          s.push(ch[i]);
          break;
        }
      }
    }

    if(s.empty()){
      cout << "yes" << '\n';
    }
    else{
      cout << "no" << '\n';
    }

    while(false == s.empty()){
      s.pop();
    }
  }

  return 0;
}
