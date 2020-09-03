#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define pb push_back

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> v;
  int sum = 0;
  int check = 0;

  for(int i = 1; i < N+1; i++){
    if(i < 10){
      sum++;
      continue;
    }

    check = 0;

    string s = to_string(i);
    for(int j = 0; j < s.length(); j++){
      int a = s[j] - '0';
      v.pb(a);
    }

    int gap = v[1] - v[0];

    for(int k = 2; k < s.length(); k++){
      if(v[k] - v[k-1] == gap){
        continue;
      }
      else{
        check++;
        break;
      }
    }

    if(check == 0){
      sum++;
    }

    v.clear();
    s.clear();
  }

  cout << sum << '\n';

  return 0;
}
