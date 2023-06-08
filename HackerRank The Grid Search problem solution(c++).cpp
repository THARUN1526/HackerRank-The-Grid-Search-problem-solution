#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char arr[1001][1001]; 
char find2[1001][1001]; 
int main() {
    int a; cin >> a;
    for (int g=0;g<a; g++)
    {
        int b,c;cin>>b>>c;
        for (int g=0;g<b; g++)
            {
            for (int y=0;y<c; y++)
                {
                cin >> arr[g][y]; 
            }
        }
        int d,e;cin>>d>>e;
        for (int g=0;g<d; g++)
            {
            for (int y=0;y<e; y++)
                {
                cin >> find2[g][y]; 
            }
        }
        if (d>b || e>c)
            {
            cout << "NO" << '\n'; continue; 
        }int realcheck=0; 
        for (int z=0;z<=b-d; z++)
            {
            for (int zz=0; zz<=c-e; zz++)
                {int checker=0; 
                for (int l=z; l<z+d; l++)
                    {
                    for (int ll=zz; ll<zz+e; ll++)
                        {
                        if (find2[l-z][ll-zz]!=arr[l][ll])
                         {
                            checker=1; break;    
                        }
                    }if (checker==1)break; 
                }
                 if (checker==0) {realcheck=1; break;}
            }if (realcheck==1) break; 
        }
        if (realcheck) cout << "YES" << '\n'; 
        else cout << "NO" << '\n';
    }
    return 0;
}