/// XXXX


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int N, H, half;
        cin >> N >> H;
        half = N/2;

        int up[half], dn[half], ret[H+1];
        memset(ret, 0, sizeof ret);
        for(int i=0; i<half; i++)
        {
                cin >> dn[i] >> up[i];
        }
        sort(dn, dn+half);
        sort(up, up+half);

        for(int i=1; i<=H; i++)
        {
                unsigned long cross = 0;
                cross += dn + half - lower_bound(dn, dn+half, i);
                cross += up + half - upper_bound(up, up+half, H-i);
                ret[i] = (int) cross;
        }
        sort(ret+1, ret+H+1);
        cout << ret[1] << ' ' << upper_bound(ret+1, ret+H+1, ret[1]) - (ret+1);

}

