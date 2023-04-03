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
//vector<vector <bool>> vis; //vis[row],[col]
//int mxx=0, mxy=0;
int x=0, y=0, tx=0, ty=0;
set <pii> vis;
bool dia = false;

void geser(char& key, int& n){
    int idx = m[key];
    x += (n*px[idx]);
    y += (n*py[idx]);
    int newx = x;
    int newy = y;
//    out(x,y);

    if (dia) n--;
    for (int cnt=0; cnt<n-1; cnt++){
        newx += (-1*px[idx]);
        newy += (-1*py[idx]);
//        out(newx, newy);
        vis.insert({newx, newy});
    }
    if (n == 1) dia = true;
    else dia = false;
}
void solve(){
//    for (auto el: vis){
//        out(el.fi, el.se);
//    }
//    db("--");
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
    vis.insert({0,0});

    char key; int n;
    while(cin >> key >> n){
        geser(key, n);
    }
    solve();
    return 0;
}
