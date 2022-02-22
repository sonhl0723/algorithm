#include <iostream>
#include <queue>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string Test;
  getline(cin, Test);

  queue<string> q;
  int cnt_X = 0;
  int ans = 0;

  for(int i = 0; i < Test.length(); i++){
    if(Test[i] == '.'){
      if(cnt_X == 2){
        q.push("BB");
        q.push(".");
        cnt_X = 0;
        continue;
      }
      else if(cnt_X == 0){
        q.push(".");
        continue;
      }
      else{
        ans = -1;
        break;
      }
    }

    if(Test[i] == 'X'){
      cnt_X++;

      if(cnt_X == 4){
        q.push("AAAA");
        cnt_X = 0;
        continue;
      }
    }

    if(i == Test.length()-1){
      if(cnt_X == 2){
        q.push("BB");
      }
      else if(cnt_X == 4){
        q.push("AAAA");
      }
      else{
        ans = -1;
      }
    }
  }

  if(ans == -1){
    cout << ans << '\n';
  }
  else{
    while(!q.empty()){
      cout << q.front();
      q.pop();
    }
  }

  return 0;
}
