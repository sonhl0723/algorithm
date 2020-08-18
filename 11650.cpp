#include <iostream>
#include <algorithm>

using namespace std;

struct Map{
  int x;
  int y;
};

bool comp(const Map& a, const Map& b){
  if(a.x != b.x){
    return a.x < b.x;
  }
  else{
    return a.y < b.y;
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  struct Map map[Testcase];

  for(int i = 0; i < Testcase; i++){
    int x, y;
    cin >> x >> y;

    map[i].x = x;
    map[i].y = y;
  }

  sort(map, map + Testcase, comp);

  for(int i = 0; i < Testcase; i++){
    cout << map[i].x << " " << map[i].y << '\n';
  }

  return 0;
}
