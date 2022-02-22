#include <iostream>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  while(Testcase--){
    int N;
    cin >> N;

    vector< pair<int, int> > v;

    for(int i = 0; i <= N; i++){
      if(i == 0){
        v.push_back(make_pair(1, 0));
      }
      else if(i == 1){
        v.push_back(make_pair(0, 1));
      }
      else{
        v.push_back(make_pair(v[i-2].first + v[i-1].first, v[i-2].second + v[i-1].second));
      }
    }

    cout << v[v.size()-1].first << " " << v[v.size()-1].second << '\n';

    v.clear();
  }

  return 0;
}
