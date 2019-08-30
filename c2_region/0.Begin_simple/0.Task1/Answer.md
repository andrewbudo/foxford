# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###

#include <iostream>
#include <cmath>
#include <algorithm>
 
#define ll long long
 
using namespace std;
 
int main() {
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    ll cnt;
    cnt = min(a1, a2) + min(a3, a4);
    cout << int(sqrt(cnt));
    return 0;
}
