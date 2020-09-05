#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v(26);

  string s;
  getline(cin, s);
  int index = 0;

  for(int i = 0; i < s.length(); i++){
    if(s[i] <= 'Z' && s[i] >= 'A'){
      index = s[i] - 65;
      v[index] = v[index] + 1;
    }
    else if(s[i] <= 'z' && s[i] >= 'a'){
      index = s[i] - 97;
      v[index] = v[index] + 1;
    }
  }

  int maximum = -1;

  for(int i = 0; i < 26; i++){
    maximum = max(maximum, v[i]);

    if(maximum == v[i]){
      index = i;
    }
  }

  sort(v.begin(), v.end());

  if(v[25] == v[24]){
    cout << '?' << '\n';
  }
  else{
    char a = 65 + index;
    cout << a << '\n';
  }



  return 0;
}
