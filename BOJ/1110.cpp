#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int N, front, end;
  int count = 0;

  cin >> N;

  int result = N;

  while(result != N || count == 0){
      front = ((result % 10) * 10);
      end = ((result / 10) + (result % 10)) % 10;
      result = front + end;
      count ++;
  }

  cout << count << '\n';

  return 0;
}
