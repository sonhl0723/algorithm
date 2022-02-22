#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> v;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int start = 0;
  int end = 0;
  int sum = 0;
  int count = 0;

  while(1){
    if(sum == M){
      count++;
    }

    if(sum >= M){
      sum = sum - v[start];
      start++;
    }
    else if(end == N){
      if(sum == M){
        count++;
      }
      break;
    }
    else{
      sum = sum + v[end];
      end++;
    }
  }

  cout << count << '\n';

  return 0;
}
