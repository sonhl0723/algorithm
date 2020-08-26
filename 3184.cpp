#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int goat = 0;
int wolf = 0;
string arr[251][251];
vector<pair <int, int> > v;
bool visit[251][251];

void dfs(int check_x, int check_y){

  visit[check_x][check_y] = 1;

  for(int i = 0; i < 4; i++){
    int next_x = check_x + dx[i];
    int next_y = check_y + dy[i];

    if(visit[next_x][next_y] || arr[next_x][next_y] == "#"){
      continue;
    }

    if(!visit[next_x][next_y] && arr[next_x][next_y] == "o"){
      goat++;
      dfs(next_x, next_y);
    }
    else if(!visit[next_x][next_y] && arr[next_x][next_y] == "v"){
      wolf++;
      dfs(next_x, next_y);
    }
    else if(!visit[next_x][next_y] && arr[next_x][next_y] == "."){
      dfs(next_x, next_y);
    }
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int R, C;
  cin >> R >> C;

  memset(visit, 0, sizeof(visit));

  // string arr[R][C];
  // vector<pair <int, int> > v;
  // bool visit[R][C];

  for(int i = 0; i < R; i++){
    string s;
    cin >> s;
    for(int j = 0; j < C; j++){
      arr[i][j] = s[j];
      if(s[j] == 'o'){
        v.push_back(make_pair(i, j));
      }
      if(s[j] == 'v'){
        v.push_back(make_pair(i, j));
      }
    }
  }

  int Runtime = v.size();
  int survive_goat = 0;
  int survive_wolf = 0;

  for(int i = 0; i < Runtime; i++){
    if(visit[v[i].first][v[i].second]){
      continue;
    }

    if(arr[v[i].first][v[i].second] == "o"){
      goat++;
    }
    else if(arr[v[i].first][v[i].second] == "v"){
      wolf++;
    }

    dfs(v[i].first, v[i].second);

    // cout << goat << " " << wolf << '\n';

    if(goat > wolf){
      survive_goat = survive_goat + goat;
      goat = 0;
      wolf = 0;
    }
    else{
      survive_wolf = survive_wolf + wolf;
      goat = 0;
      wolf = 0;
    }
  }

  cout << survive_goat << " " << survive_wolf << '\n';

  return 0;
}
