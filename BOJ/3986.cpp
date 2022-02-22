#include <iostream>
#include <stack>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int ans = 0;
  stack<char> stk;

  while(N--){
    string s;
    cin >> s;
    int s_length = s.length();

    for(int i = 0; i < s_length; i++){
      if(stk.empty()){
        stk.push(s[i]);
        continue;
      }

      char top = stk.top();

      if(top == s[i]){
        stk.pop();
      }
      else{
        stk.push(s[i]);
      }
    }

    if(stk.empty()){
      ans++;
    }
    else{
      while(!stk.empty()){
        stk.pop();
      }
    }
    s.clear();
  }


  cout << ans << '\n';

  return 0;
}
