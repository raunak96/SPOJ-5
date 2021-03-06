#include <bits/stdc++.h>

using namespace std;

const int me = 500025;
const int BLOCKS = 700;

int n, q, l, r, x;
int type;
int a[me];
vector<pair<int, int> > v[BLOCKS];

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    /*
     vector<pair<int, int> > v;
     v.push_back(make_pair(4, 1));
     v.push_back(make_pair(6, 2));
     v.push_back(make_pair(1, 3));
     v.push_back(make_pair(2, 4));
     sort(v.begin(), v.end());
     int x = lower_bound(v.begin(), v.end(), make_pair(4, 10)) - v.begin();
     cout << x << endl;
     */
    
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
        v[i / BLOCKS].push_back(make_pair(a[i], i));
    }
    for(int i = 0; i < BLOCKS; i ++)
        sort(v[i].begin(), v[i].end());
    scanf("%d", &q);
    while(q --){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d%d%d", &l, &r, &x);
            int d = r - l;
            l --, r --, x --;
            int s = 0;
            for( ; l % BLOCKS && l <= r; l ++)
                if(a[l] <= x)
                    s ++;
            for( ; l + BLOCKS <= r; l += BLOCKS)
                s += lower_bound(v[l / BLOCKS].begin(), v[l / BLOCKS].end(), make_pair(x, INT_MAX)) - v[l / BLOCKS].begin();
            for( ; l <= r; l ++)
                if(a[l] <= x)
                    s ++;
            printf("%d\n", d + 1 - s);
        }
        else{
            scanf("%d%d", &l, &x);
            l --;
            int w = l / BLOCKS;
            for(auto & i : v[w])
                if(i.second == l){
                    i.first = x;
                    break;
                }
            sort(v[w].begin(), v[w].end());
            a[l] = x;
        }
    }
    
    
    return 0;
}
