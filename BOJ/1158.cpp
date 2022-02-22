#include <iostream>
#include <queue>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  queue<int> q1, q2;

  for(int i = 0; i < N; i++){
    q1.push(i+1);
  }

  int top;

  while(q2.size() != N){
    if(q1.size() == 1){
      top = q1.front();
      q2.push(top);
      break;
    }
    for(int i = 0; i < K; i++){
      if(i == K-1){
        top = q1.front();
        q1.pop();
        q2.push(top);
      }
      else{
        top = q1.front();
        q1.pop();
        q1.push(top);
      }
    }
  }

  cout << '<';
  while(!q2.empty()){
    if(q2.size() == 1){
      cout << q2.front() << '>' << '\n';
      q2.pop();
    }
    else{
      cout << q2.front() << ", ";
      q2.pop();
    }
  }

  return 0;
}
