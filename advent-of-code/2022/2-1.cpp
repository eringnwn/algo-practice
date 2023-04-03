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

unordered_map<char, int> m;
ll ans = 0;

void solve(char& u, char& me){
    ll cnt = m[me];
    if (me == 'Y') cnt += m[u];
    else if (me == 'X'){
        if (u == 'A') cnt += 3;
        else if (u == 'B') cnt += 1;
        else cnt += 2;
    }
    else{
        if (u == 'A') cnt += 2;
        else if (u == 'B') cnt += 3;
        else cnt += 1;
    }
    ans += cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    m['A'] = 1;
    m['X'] = 0;
    m['B'] = 2;
    m['Y'] = 3;
    m['C'] = 3;
    m['Z'] = 6;

    char u, me;
    while(cin >> u >> me){
        solve(u, me);
    }
    cout << ans << endl;
    return 0;
}
