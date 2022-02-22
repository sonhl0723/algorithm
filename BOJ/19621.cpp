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
  int start, end, size;
  int max_s;

  for(int i = 0; i < N; i++){
    cin >> start >> end >> size;

    if(i < 2){
      arr[i] = size;
    }
    else if(i == 2){
      arr[i] = arr[i-2] + size;
      max_s = max(arr[i-2], arr[i-1]);
    }
    else{
      arr[i] = max_s + size;
      max_s = max(arr[i-2], arr[i-1]);
    }
  }

  cout << max(arr[N-1], arr[N-2]) << '\n';

  return 0;
}
