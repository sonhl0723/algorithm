#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;
  bool length[51];

  vector<string> v;
  memset(length, 0, sizeof(length));

  while(Testcase--){
    string s;
    cin >> s;
    if(!length[s.length()]){
      length[s.length()] = 1;
    }
    v.push_back(s);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  vector<string> ans;
  int v_size = v.size();

  for(int i = 0; i < 51; i++){
    if(!length[i]){
      continue;
    }
    for(int j = 0; j < v_size; j++){
      if(v[j].length() == i){
        ans.push_back(v[j]);
      }
    }
  }

  for(int i = 0; i < v.size(); i++){
    cout << ans[i] << '\n';
  }

  return 0;
}
