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

vector <stack<char>> st;
int n, from, to;

void init(){
    st.resize(9);
    vector <char> data[9];

    data[0] = {'V','J','B','D'};
    data[1] = {'F', 'D', 'R', 'W', 'B', 'V', 'P'};
    data[2] = {'Q', 'W', 'C', 'D', 'L', 'F', 'G', 'R'};
    data[3] = {'B', 'D', 'N', 'L', 'M', 'P', 'J', 'W'};
    data[4] = {'Q', 'S', 'C', 'P', 'B', 'N', 'H'};
    data[5] = {'G', 'N', 'S', 'B', 'D', 'R'};
    data[6] = {'H', 'S', 'F', 'Q', 'M', 'P', 'B', 'Z'};
    data[7] = {'F', 'L', 'W'};
    data[8] = {'R', 'M', 'F', 'V', 'S'};

    for (int i=0; i<9; i++){
        for (int j=sz(data[i])-1; j>=0; j--){
            st[i].push(data[i][j]);
        }
    }
}
void update(){
    from--;
    to--;
    char x;
    for (int i=0; i<n; i++){
        x = st[from].top();
        st[to].push(x);
        st[from].pop();
    }
}
void solve(){
    for (int i=0; i<9; i++){
        cout << st[i].top();
    }
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    init();

    string t1,t2,t3;
    while(cin >> t1 >> n >> t2 >> from >> t3 >> to){
        update();
    }
    solve();
    return 0;
}
