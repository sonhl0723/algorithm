#include <iostream>
#include <cstring>

using namespace std;

#define pb push_back

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  getline(cin, s);
  int s_size = s.length();

  int v[26];
  char arr[s_size];
  int index;

  memset(v, 0, sizeof(v));

  for(int i = 0; i < s_size; i++){
    index = s[i] - 65;
    v[index] = v[index] + 1;
  }

  int check = 0;

  for(int i = 0; i < 26; i++){
    if(v[i] % 2 != 0){
      check++;
      index = i;
    }
    if(s_size % 2 != 0 && check > 1){
      cout << "I'm Sorry Hansoo" << '\n';
      return 0;
    }
    else if(s_size % 2 == 0 && check > 0){
      cout << "I'm Sorry Hansoo" << '\n';
      return 0;
    }
  }

  if(check != 0){
    char mid = index + 65;
    arr[s_size/2] = mid;
    v[index] = v[index] - 1;
  }

  int left = 0;
  int right = s_size - 1;

  for(int i = 0; i < 26; i++){
    char a = i + 65;
    for(int j = 0; j < v[i]; j++){
      if(j % 2 == 0){
        arr[left] = a;
        left = left + 1;
      }
      else{
        arr[right] = a;
        right = right - 1;
      }
    }
  }

  for(int i = 0; i < s_size; i++){
    cout << arr[i];
  }


  return 0;
}
