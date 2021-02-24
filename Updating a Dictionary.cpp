#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int q;
	while(cin>>q)
	{
		string s1,s2;
		for(int i=0;i<q;i++)
		{
			cin>>s1;
			cin>>s2;
			
			map<string,string> dic1,dic2,tmp1,tmp2;
			string key,value,buffer;
			
			for(int j=1;j<s1.length()-1;j++)
			{
				if(s1[j]==':')
				{
					key=buffer;
					buffer.clear();
				}
				else if(s1[j]==',')
				{
					value=buffer;
					buffer.clear();
					dic1[key]=value;
					//cout<<key<<" "<<value<<endl;
				}
				else
				{
					buffer.push_back(s1[j]);
				}
			}
			value=buffer;
			dic1[key]=value;
			key.clear();
			value.clear();
			buffer.clear();
			for(int k=1;k<s2.length()-1;k++)
			{
				if(s2[k]==':')
				{
					key=buffer;
					buffer.clear();
				}
				else if(s2[k]==',')
				{
					value=buffer;
					buffer.clear();
					dic2[key]=value;
					//cout<<key<<" "<<value<<endl;
				}
				else
				{
					buffer.push_back(s2[k]);
				}
			}
			value=buffer;
			dic2[key]=value;
			//cout<<key<<" "<<value<<endl;
			map<string,string>::iterator it,it2;
			it=dic1.begin();
			vector<string> add,del,change;
			
			tmp1=dic1;
			tmp2=dic2;
			for(;it!=dic1.end();it++)
			{
				//cout<<it->first<<endl;
				it2=dic2.find(it->first);
				if(it2!=dic2.end())
				{
					//cout<<it->second<<" "<<it2->second<<endl;
					if(it->second!=it2->second)
						change.push_back(it->first);
					tmp1.erase(it->first);
					tmp2.erase(it2->first);
				}
			}
			
			for(it=tmp1.begin();it!=tmp1.end();it++)
				del.push_back(it->first);
			for(it2=tmp2.begin();it2!=tmp2.end();it2++)
				add.push_back(it2->first);
			sort(add.begin(),add.end());
			sort(del.begin(),del.end());
			sort(change.begin(),change.end());
			if(add.empty()&&del.empty()&&change.empty())
			{
				cout<<"No changes"<<endl<<endl;
			}
			else
			{
				if(!add.empty()&&!add[0].empty())
				{
					cout<<"+";
					for(int i=0;i<add.size()-1;i++)
						cout<<add[i]<<",";
					cout<<add[add.size()-1]<<endl;
				}
				if(!del.empty()&&!del[0].empty())
				{
					cout<<"-";
					for(int j=0;j<del.size()-1;j++)
						cout<<del[j]<<",";
					cout<<del[del.size()-1]<<endl;
				}
				if(!change.empty())
				{
					cout<<"*";
					for(int k=0;k<change.size()-1;k++)
						cout<<change[k]<<",";
					cout<<change[change.size()-1]<<endl;
				}
				cout<<endl;
			}
		}
	}
	return 0;
} 
