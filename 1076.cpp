#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map < string, pair <int, long long> > color;

  color["black"] = make_pair(0,1);
  color["brown"] = make_pair(1,10);
  color["red"] = make_pair(2,100);
  color["orange"] = make_pair(3,1000);
  color["yellow"] = make_pair(4,10000);
  color["green"] = make_pair(5,100000);
  color["blue"] = make_pair(6,1000000);
  color["violet"] = make_pair(7,10000000);
  color["grey"] = make_pair(8,100000000);
  color["white"] = make_pair(9,1000000000);

  string a,b,c;
  cin >> a >> b >> c;
  cout << (color.find(a) -> second.first * 10 + color.find(b) -> second.first)*color.find(c) -> second.second << '\n';


  return 0;
}
