#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  map<string, int> m1;
  map<int, string> m2;

  for(int i = 0; i < N; i++){
    string s;
    cin >> s;

    m1.insert(make_pair(s, i+1));
    m2.insert(make_pair(i+1, s));
  }

  while(M--){
    string output;
    cin >> output;

    if('A' <= output[0] && 'Z' >= output[0]){
      cout << m1.find(output)->second << '\n';
    }
    else{
      int index = stoi(output);
      cout << m2.find(index)->second << '\n';
    }

    output.clear();
  }

  return 0;
}
