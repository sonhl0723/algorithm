#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
  return b ? gcd(b, a % b) : a;
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int elem_1, elem_2;

  cin >> elem_1 >> elem_2;

  cout << gcd(elem_1, elem_2) << '\n' << (elem_1*elem_2) / gcd(elem_1, elem_2) << '\n';

  return 0;
}
