#include <iostream>
// #include <vector>
#include <stack>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int arr[N];
  stack<int> s;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;

    arr[i] = a;
  }

  long long sum = 0;

  for(int i = 0; i < N; i++){
    while(!s.empty() && s.top() <= arr[i]){
      s.pop();
    }

    s.push(arr[i]);

    sum += s.size() - 1;
  }

  cout << sum << '\n';

  return 0;
}
