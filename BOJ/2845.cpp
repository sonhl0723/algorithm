#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b;
  vector<int> v;

  cin >> a >> b;

  int sum = a * b;

  for(int i = 0; i < 5; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  for(int i = 0; i < 5; i++){
    v[i] = v[i] - sum;
    if(i != 4){
      cout << v[i] << " ";
    }
    else{
      cout << v[i] << '\n';
    }
  }

  return 0;

}
