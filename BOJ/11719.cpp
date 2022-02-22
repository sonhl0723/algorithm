#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string ch[101];

  for(int i = 0; i < 100; i++){
    getline(cin, ch[i]);

    cout << ch[i] << '\n';
  }

  return 0;
}
