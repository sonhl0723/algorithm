#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;

  while(N--){
    int a, b;

    cin >> a >> b;

    cout << a+b << '\n';
  }

  return 0;
}
