#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> v;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;

    v.push_back(a);
  }

  int count = 1;
  int end = v.size()-1;
  int max_size = v[end];

  for(int i = 1; i < N+1; i++){
    if(v[end-i] > max_size){
      max_size = v[end-i];
      count++;
    }
  }

  cout << count << '\n';

  return 0;
}
