#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Quiz{
  int score;
  int problem_num;
};

bool comp1(const Quiz& a, const Quiz& b){
  return a.score > b.score;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  struct Quiz quiz[8];

  for(int i = 0; i < 8; i++){
    int a;
    cin >> a;

    quiz[i].score = a;
    quiz[i].problem_num = i+1;
  }

  sort(quiz, quiz+8, comp1);

  int sum = 0;
  vector<int> v;

  for(int i = 0; i < 5; i++){
    sum = sum + quiz[i].score;
    v.push_back(quiz[i].problem_num);
  }

  cout << sum << '\n';

  sort(v.begin(), v.end());

  for(int i = 0; i < 5; i++){
    cout << v[i] << " ";
  }

  return 0;
}
