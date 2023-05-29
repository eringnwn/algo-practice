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

void solve(){

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue <ll> q; ll tmp=0, sum=0, cnt=0;
    for (int i=0; i<3; i++){
        cin >> tmp;
        q.push(tmp);
        sum += tmp;
    }
    while(cin >> tmp){
        ll bef = q.front();
        if ((sum - bef + tmp) > sum){
            cnt++;
        }
        sum = sum - bef + tmp;
        q.pop();
        q.push(tmp);
    }
    cout << cnt << endl;
    return 0;
}
