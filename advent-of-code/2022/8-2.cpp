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

const int MAXN = 1000;
vi g[MAXN]; // row col
int idx = 0;

int findmxr(int s, int fin, int dir, int& r, int& key){
    //dir left or right
    int mx = -1, cnt = 0;
    for (int i=s; i!=fin; i+= dir){
//        if (g[r][i] >= mx){
//            cnt ++;
//            mx = g[r][i];
//        }
        cnt++;
        if (g[r][i] >= key) break;
    }
//    if (grid[r][fin] > mx) cnt++;
    return cnt;
}

int findmxc(int s, int fin, int dir, int& c, int& key){
    //dir up or down
    int mx = -1, cnt = 0;
    for (int i=s; i!=fin; i+= dir){
//        if (g[i][c] >= mx){
//            cnt ++;
//            mx = g[i][c];
//        }
        cnt++;
        if (g[i][c] >= key) break;
    }
//    if (grid[fin][c] > mx) cnt++;
    return cnt;
}

void solve(){
    int mx = -1;
    int col = sz(g[0]);
    for (int r=1; r<idx-1; r++){
//        db(r);
        for (int c=1; c<col-1; c++){
            int key = g[r][c];
            int tmp = findmxr(c+1,col,1,r, key) * findmxr(c-1,-1,-1,r, key) * findmxc(r+1,idx,1,c, key) * findmxc(r-1,-1,-1,c, key);
//            db(tmp);
//            out(findmxr(c+1,col,1,r, key), findmxr(c-1,-1,-1,r, key));
//            out(findmxc(r+1,idx,1,c, key), findmxc(r-1,-1,-1,c, key));
            mx = max(mx, tmp);
        }
    }
    cout << mx << endl;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    freopen("input.txt", "r", stdin);
    string str; int tmp;
    while(cin >> str){
        for (int i=0; i < str.length(); i++){
            tmp = str[i] - '0';
            g[idx].pb(tmp);
        }
        idx++;
    }
    solve();
    return 0;
}
