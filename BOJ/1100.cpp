#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  vector<char> v[8];

  for(int i = 0; i < 8; i++){
    getline(cin, s);
    for(int j = 0; j < 8; j++){
      v[i].pb(s[j]);
    }
  }

  int ans = 0;

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(i == 0 || i % 2 == 0){
        if(j == 0 || j % 2 == 0){
          if(v[i][j] == 'F'){
            ans = ans + 1;
          }
        }
      }
      else{
        if(j % 2 == 1){
          if(v[i][j] == 'F'){
            ans = ans + 1;
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
