#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

int n;
vector<ll> x,y;

void solve(){
    sort(x.begin(), x.end());
    sort(y.begin(), y.end(), greater<int>());
    ll ans = 0;
    for (int i=0; i<n; i++){
        ans += (x[i] * y[i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        x.push_back(tmp);
    }
    for (int i=0; i<n; i++){
        cin >> tmp;
        y.push_back(tmp);
    }
    solve();

    return 0;
}
