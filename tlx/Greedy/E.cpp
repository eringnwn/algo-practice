#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

int n, m;
vector<int> bebek;
unordered_map<int,int> uk;

void solve(){
    int cnt = 0, now, match;
    sort(bebek.begin(), bebek.end(), greater<int>());
    for (int i=0; i<n; i++){
        now = bebek[i];
        match = -1;
        if (uk.count(now+1)){
            match = now+1;
        }
        else if ((int)uk.count(now)){
            match = now;
        }
        if (match != -1){
            cnt++;
            uk[match]--;
            if (uk[match] == 0) uk.erase(match);
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        bebek.push_back(tmp);
    }
    for (int i=0; i<m; i++){
        cin >> tmp;
        uk[tmp]++;
    }
    solve();

    return 0;
}
