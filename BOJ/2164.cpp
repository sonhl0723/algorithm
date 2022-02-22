#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int count = 0;
  queue<int> q;

  cin >> N;

  for(int i = 1; i < N + 1; i++){
    q.push(i);
  }

  while(q.size() != 1){
    if(count % 2 == 0){
      q.pop();
      count ++;
    }
    else{
      int shelter = q.front();
      q.pop();
      q.push(shelter);
      count--;
    }
  }

  cout << q.front() << '\n';

  return 0;
}
