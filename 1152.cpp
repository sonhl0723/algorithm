#include <iostream>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  getline(cin, s);
  int ans = 0;
  int check = 0;

  for(int i = 0; i < s.length(); i++){
    if(check == 0 && s[i] != ' '){
      ans++;
      check = 1;
    }
    else if(check != 0 && s[i] == ' '){
      check = 0;
    }
    else{
      continue;
    }
  }


  cout << ans << '\n';

  return 0;
}
