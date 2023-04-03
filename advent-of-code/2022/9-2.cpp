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

int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
map <char,int> m;
int hx=0, hy=0, tx=0, ty=0;
set <pii> vis;

void update(int& a, int& b){
    if (abs(hx-tx) <= 1 && abs(hy-ty) <= 1){
        return;
    }
    if (abs(hx-tx) >= 1 && abs(hy-ty) >= 1){
        //jika diagonal
//        db("dia");
//        out(hx,hy);
//        out(hx-a, hy-b);
        tx = hx - a;
        ty = hy - b;
    }
    else{
        tx += a;
        ty += b;
    }
    return;
}
void geser(char& key, int& n){
    int idx = m[key];
    for (int cnt=0; cnt<n; cnt++){
        hx += px[idx];
        hy += py[idx];
        update(px[idx], py[idx]);
//        out(tx,ty);
        vis.insert({tx,ty});
    }
}
void solve(){
//    db("----");
//    for (auto el: vis){
//        out(el.fi, el.se);
//    }
    cout << sz(vis) << endl;
}
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    freopen("input.txt", "r", stdin);
    m['R'] = 0;
    m['L'] = 1;
    m['U'] = 2;
    m['D'] = 3;

    char key; int n;
    while(cin >> key >> n){
        geser(key, n);
    }
    solve();
    return 0;
}
