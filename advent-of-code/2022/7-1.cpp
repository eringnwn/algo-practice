#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back
#define sz(x) int((x).size())

using pii = pair <int, int>;
#define mp make_pair
#define fi first
#define se second

map<string, int> m; //dir, idx position
vll sze;
vi parent;

void update(int& idx, ll& val){
    sze[idx] += val;
    if (parent[idx] != idx){
        update(parent[idx], val);
    }
    return;
}

void add(string s1, string s2, int idxdir){
    if(s1 == "dir"){
        m[s2] = sz(parent);
        parent.pb(idxdir);
        sze.pb(0);
    }
    else{
        ll fsize = stoll(s1, nullptr, 10);
        update(idxdir, fsize);
    }
}

void solve(){
    ll kurang = 30000000 - (70000000 - sze[0]);
    out(sze[0], kurang);
    sort(sze.begin(), sze.end());
    ll ans = *lower_bound(sze.begin(), sze.end(), kurang);

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char sign; string cd, dir, tmp;
    m["/"] = 0;
    parent.pb(0);
    sze.pb(0);
    cin >> sign >> cd;
    while(cin >> dir){
        if (dir == ".."){
            cin >> sign >> cd;
            continue;
        }
//        db(dir);
//        out(m[dir], parent[m[dir]]);
        cin >> tmp;
        getline(cin, tmp); //$ ls
        string s1, s2;
        while(cin >> s1 >> s2){
            if (s1 == "$" && s2 == "cd") break;
            add(s1, s2, m[dir]);
        }
    }
    solve();
    return 0;
}
