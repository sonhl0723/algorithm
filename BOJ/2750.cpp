#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

  vector<int> elem_v;
  int elem;
  int N;

  cin >> N;

  while(N--){
    cin >> elem;
    elem_v.push_back(elem);
  }

  sort(elem_v.begin(), elem_v.end());

  for(int i=0; i<elem_v.size(); i++){
    cout << elem_v[i] << endl;
  }

  return 0;
}
