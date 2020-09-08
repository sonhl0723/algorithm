#include <iostream>
#include <algorithm>

using namespace std;

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
  long long ans;

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

  sort(arr, arr+N);

  for(int i = 0; i <= N-2; i++){
    sum = sum + arr[i];
  }

  if(sum < arr[N-1]){
    ans = arr[N-1] - sum;
  }
  else if(sum == arr[N-1]){
    ans = 0;
  }
  else{
    ans = sum - arr[N-1] - ((N-1) * 2);
  }

  cout << ans << '\n';

  return 0;
}
