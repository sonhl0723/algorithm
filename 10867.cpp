#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  vector<int> v;

  for(int i = 0; i < Testcase; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }

  return 0;
}
