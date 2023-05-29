#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

int n;
vector<pair <int,int>> teman;

void solve(){
    sort(teman.begin(), teman.end());

    int ans = 0;
    int nowtime = 0;
    for (int i=0; i<n; i++){
        if (teman[i].second >= nowtime){
            nowtime = teman[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mulai, durasi;
    for (int i=0; i<n; i++){
        cin >> mulai >> durasi;
        teman.push_back({mulai+durasi, mulai});
    }
    solve();

    return 0;
}
