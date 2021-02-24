#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct data{
	int O;
	int D;
};

bool cmp(const data& a,const data& b)
{
	if(a.O<b.O)
		return true;
	else if(a.O==b.O)
		if(a.D<b.D)
			return true;
	return false;
}
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
    	vector<data> list1,list2;
		data tmp1,tmp2;
        bool ok = true;
        int o,d;
        for(int i = 0 ; i < n;++i){
            scanf("%d%d", &o,&d);
            tmp1.D=d;
            tmp1.O=o;
            tmp2.D=o;
            tmp2.O=d;
            list1.push_back(tmp1);
            list2.push_back(tmp2);
        }
        if(n % 2){
            ok = false;
        }
        else{
            sort(list1.begin(),list1.end(),cmp);
            sort(list2.begin(),list2.end(),cmp);
            for(int i=0;i<n;i++)
            {
            	if(list1[i].O!=list2[i].O||list1[i].D!=list2[i].D)
            		ok=false;
			}
        }

        printf("%s\n", (ok ? "YES" : "NO"));
    }
    return 0;
}
