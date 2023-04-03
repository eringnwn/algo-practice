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

string str1, str2, str3;
ll ans = 0;

void add(char n){
    ll tmp = n-'a'+1;
    if (n - 'a' < 0){
        tmp = (n - 'A');
        tmp += 26 + 1;
    }
    ans += tmp;
}

void solve(){
    map<char,bool> c1, c2, c3;
    for (int i=0; i<str1.length(); i++){
        c1[str1[i]] = 1;
    }
    for (int i=0; i<str2.length(); i++){
        c2[str2[i]] = 1;
    }
    for (int i=0; i<str3.length(); i++){
        c3[str3[i]] = 1;
    }
    for (auto el: c1){
        if (c2.count(el.fi) && c3.count(el.fi)){
            //db(el.fi);
            add(el.fi);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> str1 >> str2 >> str3){
        solve();
    }
    cout << ans << endl;
    return 0;
}
