#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int maximum = 0;
  long long all_bead = 0;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    
    all_bead = all_bead + a;
    maximum = max(a, maximum);
  }

  long long extra_bead = all_bead-maximum;
  long long ans;

  if(maximum > extra_bead){
    ans = maximum - extra_bead;
  }
  else{
    if(all_bead % 2 == 0){
      ans = 0;
    }
    else{
      ans = 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
