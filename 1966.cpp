#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while(N--){
        int ans=0, input, idx, element;
        pair<int, int> tmp;
        queue< pair<int, int> > q;
        map< int, int, greater<int> > m;

        cin >> input >> idx;

        while(input--){
            cin >> element;
            
            if(q.size()==idx) q.push(make_pair(element, 1));
            else q.push(make_pair(element, 0));

            if(m.find(element)==m.end()) m.insert(make_pair(element, 1));
            else m[element]++;
        }
        idx=m.begin()->first;
        while(!q.empty()){
            if(q.front().first==idx){
                ans++;
                if(q.front().second==1) break;
                else q.pop();

                m[idx]--;
                if(m[idx]==0){
                    m.erase(idx);
                    idx=m.begin()->first;
                }
            }
            else{
                tmp=q.front();
                q.pop();
                q.push(tmp);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}