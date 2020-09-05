#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  long long ans = 0;
  int s_size = s.length();

  for(int i = 0; i < s_size; i++){
    if(s[i] <= '9' && s[i] >= '0'){
      int a = s[i] - '0';
      ans = ans + (a*pow(16, s_size - 1 - i));
    }
    else{
      int a = s[i] - 55;
      ans = ans + (a * pow(16, s_size - 1 - i));
    }
  }

  cout << ans << '\n';

  return 0;
}
