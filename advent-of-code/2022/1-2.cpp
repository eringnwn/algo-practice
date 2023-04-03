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
vll sum;
void solve(){
    sort(sum.begin(), sum.end(), greater <ll> ());
    ll ans = sum[0] + sum[1] + sum[2];
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll cnt=0;
    string str;
    while(getline(cin,str)){
        if (str.length() == 0){
            sum.pb(cnt);
            cnt = 0;
        }
        else{
            cnt += stoi(str);
        }
    }
    sum.pb(cnt);
    solve();
    return 0;
}
