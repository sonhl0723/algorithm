#include <iostream>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int start = 0;
  int end = 0;
  int count = 0;
  int sum = 0;

  while(1){
    if(sum == N){
      count++;
    }

    if(sum >= N){
      start++;
      sum = sum - start;
    }
    else if(end == N){
      break;
    }
    else{
      end++;
      sum = sum + end;
    }
  }

  cout << count << '\n';

  return 0;
}
