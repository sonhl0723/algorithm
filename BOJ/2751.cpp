#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int elem, N;
  vector<int> elem_v;

  scanf("%d", &N);

  while(N--){
    scanf("%d", &elem);
    elem_v.push_back(elem);
  }

  sort(elem_v.begin(), elem_v.end());

  for(int i=0; i<elem_v.size(); i++){
    printf("%d\n", elem_v[i]);
  }

  return 0;
}
