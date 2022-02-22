#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long memo[100];
long long fibonacci(int n){
  if(n <= 1){
    return n;
  }
  else{
    if(memo[n] > 0){
      return memo[n];
    }
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
  }
}

int main(void){
  int N;

  cin >> N;

  cout << fibonacci(N) << '\n';

  return 0;
}
