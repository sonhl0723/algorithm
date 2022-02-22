#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1){
    int ans = 0;
    string s;
    stack<char> Stack;
    cin >> s;
    if(s[0] == '0'){
      return 0;
    }

    for(int i = 0; i < s.size(); i++){
      char c = s[i];
      Stack.push(c);
    }

    for(int i = 0; i < Stack.size(); i++){
      char c = s[i];
      if(c != Stack.top()){
        ans = 1;
        break;
      }
      Stack.pop();
    }

    if(ans == 1){
      cout << "no" << '\n';
    }
    else{
      cout << "yes" << '\n';
    }
  }

  return 0;
}
