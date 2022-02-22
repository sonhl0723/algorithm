#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int M, N;
int arr[1001][1001];
queue< pair<int, int> > q;
int next_tomato = 0;

void bfs(int check_x, int check_y){
  for(int i = 0; i < 4; i++){
    int next_x = check_x + dx[i];
    int next_y = check_y + dy[i];

    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M){
      continue;
    }

    if(arr[next_x][next_y] == 0){
      arr[next_x][next_y] = 1;
      q.push(make_pair(next_x, next_y));
      next_tomato++;
    }

  }
}


int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      int a;
      cin >> a;
      arr[i][j] = a;
      if(a == 1){
        q.push(make_pair(i, j));
      }
    }
  }

  int complete_tomato = q.size();
  int day = 0;

  while(q.size()){
    pair <int, int> p = q.front();
    complete_tomato--;
    bfs(p.first, p.second);
    if(complete_tomato == 0){
      complete_tomato = next_tomato;
      next_tomato = 0;
      day++;
    }
    q.pop();
  }
  
  day = day - 1;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(arr[i][j] == 0){
        day = -1;
        break;
      }
    }
  }

  cout << day << '\n';

  return 0;
}
