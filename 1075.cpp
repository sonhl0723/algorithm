#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define pb push_back

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, F;
  cin >> N >> F;

  vector<char> v;

  string s = to_string(N);
  int s_length = s.length();
  v.pb(s[s_length-2]);
  v.pb(s[s_length-1]);

  int a = (v[0] - '0') * 10;
  int b = v[1] - '0';
  N = N - a - b - 1;

  while(1){
    N++;

    if(N % F == 0){
      s = to_string(N);
      v[0] = s[s_length-2];
      v[1] = s[s_length-1];
      break;
    }

  }

  for(int i = 0; i < 2; i++){
    cout << v[i];
  }

  return 0;
}
