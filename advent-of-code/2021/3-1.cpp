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

vector <string> str;
void solve(){
    int len = str[0].length();
    int sze = sz(str);
    ll ans = 0;
    for (int idx = 0; idx < len; idx++){
        int _1 = 0;
        for (int i = 0; i < sze ; i++){
            if (str[i][idx] == '1') _1++;
        }
        if (_1 > (sze-_1)){
            ans |= (1 << (len-idx-1));
        }
    }
    ll flipans = ((ll)(pow(2,len) - 1)^ans);
    ans *= flipans;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    while(cin >> tmp){
        str.pb(tmp);
    }
    solve();
    return 0;
}
