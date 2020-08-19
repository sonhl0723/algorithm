#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

struct Team{
  int team_id;
  int sum_score;
  int sum_sub;
  int last_sub;
};

bool comp(const Team& a, const Team& b){
  if(a.sum_score != b.sum_score){
    return a.sum_score > b.sum_score;
  }
  else{
    if(a.sum_sub != b.sum_sub){
      return a.sum_sub < b.sum_sub;
    }
    else{
      return a.last_sub < b.last_sub;
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  while(Testcase--){
    int n, k, t, m;
    cin >> n >> k >> t >> m;

    struct Team team[n];
    int prob_score[n][k];

    for(int i = 0; i < n; i++){
      // team[i].team_id = i + 1;
      team[i].sum_score = 0;
      team[i].sum_sub = 0;
    }

    // for(int i = 0; i < n; i++){
   memset(prob_score, 0, sizeof(prob_score));
    // }

    for(int i = 0; i < m; i++){
      int a, b, c;
      cin >> a >> b >> c;

      team[a-1].team_id = a;
      team[a-1].last_sub = i;
      team[a-1].sum_sub = team[a-1].sum_sub + 1;

      if(prob_score[a-1][b-1] < c){
        prob_score[a-1][b-1] = c;
      }
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < k; j++){
        team[i].sum_score += prob_score[i][j];
      }
    }

    sort(team, team + n, comp);

    // cout << '\n';
    //
    // for(int i = 0; i < n; i++){
    //   cout << team[i].team_id << " " << team[i].sum_score << " " << team[i].sum_sub << '\n';
    // }

    for(int i = 0; i < n; i++){
      if(team[i].team_id == t){
        cout << i+1 << '\n';
      }
    }

  }

  return 0;
}
