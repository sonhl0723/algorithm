#include <iostream>
#include <cstdio>

int main(void){
  long long S;
  long long sum = 0;
  int N = 0;

  scanf("%lld", &S);

  while(sum <= S){
    N++;
    sum = sum + N;
  }

  printf("%d\n", N-1);

  return 0;
}
