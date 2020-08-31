#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
  // if(a.first < b.first){
  //   return a.second < b.second;
  // }
  // else{
  //   return a.second < b.second;
  // }
  return a.first < b.first;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int start, end;
  vector< pair<int, int> > v;
  vector<int> v2;
  int visit[100000];

  memset(visit, 0, sizeof(visit));

  for(int i = 0; i < N; i++){
    cin >> start >> end;
    v.push_back(make_pair(start, end));
  }

  int ans = 1;
  // int check = 0;

  sort(v.begin(), v.end(), comp);

  // for(int i = 0; i < N; i++){
  //   cout << v[i].first << " " << v[i].second << '\n';
  // }

  for(int i = 0; i < N; i++){
    if(v2.empty()){
      v2.push_back(v[i].second);
      continue;
    }

    for(int j = 0; j < v2.size(); j++){
      if(v2[j] <= v[i].first){
        v2[j] = v[i].second;
        break;
      }

      if(j == v2.size()-1){
        v2.push_back(v[i].second);
        break;
      }

    }

  }


  cout << v2.size() << '\n';

  return 0;
}
