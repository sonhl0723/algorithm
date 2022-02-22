#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, result;
  int count = 0;

  cin >> N;

  if(N % 5 == 0){
    result = N / 5;
  }
  else if(N % 5 == 1 && N / 3 != 0){
    result = ((N-6) / 5) + 2;
  }
  else if(N % 5 == 2 && N >= 12){
    result = ((N-12) / 5) + 4;
  }
  else if(N % 5 == 3){
    result = (N / 5) + 1;
  }
  else if(N % 5 == 4 && N > 4){
    result = ((N-9) / 5) + 3;
  }
  else{
    result = -1;
  }

  cout << result << '\n';

  return 0;
}
