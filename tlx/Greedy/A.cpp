#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

int n, key;
vector<int> v;

void solve(){
    sort(v.begin(), v.end(), greater<int>());

    int cnt = 0, ans = 0;
    for (int i=0; i<n; i++){
        if (cnt >= key) break;
        cnt += v[i];
        ans++;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> key;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    solve();

    return 0;
}
