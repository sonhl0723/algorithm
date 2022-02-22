#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  map<string, string, greater<string> > m;

  for(int i = 0; i < n; i++){
    string name, state;
    cin >> name >> state;

    if(state == "leave"){
      m.erase(name);
    }
    else{
      m.insert(make_pair(name, state));
    }
  }

  map<string, string, greater<string> >::iterator iter;

  for(iter = m.begin(); iter != m.end(); iter++){
    cout << (*iter).first << '\n';
  }


  return 0;
}
