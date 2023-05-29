#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

int n; ll anggaran;
vector<pair<ll,ll>> barang;

void solve(){
    sort(barang.begin(), barang.end());

    ll ans = 0, cnt = 0;
    ll sisa, krg;
    for (auto el: barang){
        if (cnt > anggaran - el.first) break;
        sisa = anggaran - cnt;
        krg = min(el.second, sisa / el.first);
//        db("--")
//        out(el.first, el.second);
        cnt += (krg*el.first);
        ans += krg;
//        out(sisa, krg);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> anggaran;
    ll harga, jlh;
    for (int i=0; i<n; i++){
        cin >> harga >> jlh;
        barang.push_back({harga, jlh});
    }
    solve();

    return 0;
}
