#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
  return a > b;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int arr[N];

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    arr[i] = a;
  }

  long long sum = 0;

  if(N <= 2){
    if(N == 1){
      sum = arr[0];
    }
    else{
      sort(arr, arr+N);
      sum = arr[1] - arr[0];
    }
    cout << sum << '\n';
    return 0;
  }



  cout << sum << '\n';

  return 0;
}
