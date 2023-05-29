#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

using ll = long long;
using ull = unsigned ll;
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back
#define sz(x) int((x).size())

using pii = pair <int, int>;
#define mp make_pair
#define fi first
#define se second

vector <string> str; int len; ll ans=1;
void debug(vector<string> v){
    for (auto el: v){
        cout << el << " ";
    }
    cout << endl;
}
void getans(string s){
    ll ret = 0;
    for (int idx = 0; idx < len; idx++){
        if (s[idx] == '1'){
            ret |= (1 << (len-idx-1));
        }
    }
    //db(ret);
    ans = ans*ret;
}
void solve(vector <string> v, int idx, bool flag){
    int sze = sz(v);
    vector <string> oxy, co;

    if (sze == 1){
        getans(v[0]);
        return;
    }
    int _1 = 0;
    vector <string> b1, b0;
    for (int i = 0; i < sze ; i++){
        if (v[i][idx] == '1'){
            b1.pb(v[i]);
            _1 ++;
        }
        else{
            b0.pb(v[i]);
        }
    }
    //db(idx);
    if (flag){
        if (_1 >= (sze - _1)) oxy = b1;
        else oxy = b0;
        //debug(oxy);
        solve(oxy, idx+1, 1);
    }
    if (idx == 0) flag = 0;
    if (!flag){
        if ((sze - _1) <= _1) co = b0;
        else co = b1;
        //debug(co);
        solve(co, idx+1, 0);
    }
    idx++;

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    while(cin >> tmp){
        str.pb(tmp);
    }
    len = tmp.length();
    solve(str,0,1);
    cout << ans <<endl;
    return 0;
}
