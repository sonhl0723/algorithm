#include <iostream>
#include <cstring>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int arr[26];
  int check = 0;
  int ans = 0;

  while(N--){
    string s;
    cin >> s;

    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < s.length(); i++){
      int index = s[i] - 97;
      if(arr[index] == 0){
        arr[index] = 1;
      }
      else{
        if(s[i] != s[i-1]){
          check = 1;
          break;
        }
        else{
          continue;
        }
      }
    }

    if(check == 0){
      ans = ans + 1;
    }

    s.clear();
    check = 0;
  }

  cout << ans << '\n';

  return 0;
}
