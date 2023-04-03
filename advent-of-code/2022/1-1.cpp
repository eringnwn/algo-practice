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
    ll sum=0, cnt=0;
    string str;
    while(getline(cin,str)){
        if (str.length() == 0){
            sum = max(sum, cnt);
            cnt = 0;
        }
        else{
            cnt += stoi(str);
        }
    }
    sum = max(sum, cnt);
    cout << sum << endl;
    return 0;
}
