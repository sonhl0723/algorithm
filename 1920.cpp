#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

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

  sort(v.begin(), v.end());

  int M;
  cin >> M;

  for(int i = 0; i < M; i++){
    int b;
    cin >> b;

    if(binary_search(v.begin(), v.end(), b)){
      cout << "1" << '\n';
    }
    else{
      cout << "0" << '\n';
    }
  }
  
  return 0;
}
