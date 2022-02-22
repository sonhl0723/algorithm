#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  vector<int> v1, v2;

  while(Testcase--){
    int N;
    cin >> N;

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < N; i++){
      int a;
      cin >> a;

      // int sum1 = 0;
      // int sum2 = 0;

      if(i == 0){
        v1.push_back(a);
        v2.push_back(a);
      }
      else{
        sum1 = v1[i-1] + a;
        v1.push_back(sum1);

        if(a < 0){
          sum2 = 0;
          v2.push_back(a);
        }
        else{
          if(sum2 == 0){
            sum2 = a;
            v2.push_back(sum2);
          }
          else{
            sum2 = v2[i-1] + a;
            v2.push_back(sum2);
          }
          // sum2 = v2[i-1] + a;
          // v2.push_back(sum2);
        }
      }
      if(v1[i] < v2[i]){
        v1[i] = v2[i];
      }
    }

    // for(int i = 0; i < v1.size(); i++){
    //   cout << v1[i] << " ";
    // }
    // cout << '\n';
    // for(int i = 0; i < v2.size(); i++){
    //   cout << v2[i] << " ";
    // }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // for(int i = 0; i < v1.size(); i++){
    //   cout << v1[i] << " ";
    // }

    cout << max(v1[v1.size()-1], v2[v2.size()-1]) << '\n';

    v1.clear();
    v2.clear();
  }

  return 0;
}
