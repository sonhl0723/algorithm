#include <iostream>
#include <algorithm>

using namespace std;

struct Index{
  int x;
  int y;
};

bool comp(const Index& a, const Index& b){
  if(a.y != b.y){
    return a.y < b.y;
  }
  else{
    return a.x < b.x;
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  struct Index index[Testcase];

  for(int i = 0; i < Testcase; i++){
    int x1, y1;
    cin >> x1 >> y1;

    index[i].x = x1;
    index[i].y = y1;
  }

  sort(index, index + Testcase, comp);

  for(int i = 0; i < Testcase; i++){
    cout << index[i].x << " " << index[i].y << '\n';
  }

  return 0;
}
