#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int main()
{
	string input;
	while(getline(cin,input))
	{
		list<char> beiju;
		list<char>::iterator iter;
		iter=beiju.begin();
		
		for(int i=0;i<input.length();i++)
		{
			if(input[i]=='[')
				iter=beiju.begin();
			else if(input[i]==']')
				iter=beiju.end();
			else
				beiju.insert(iter,input[i]);
		}
		for(iter=beiju.begin();iter!=beiju.end();iter++){
      		printf("%c", *iter);
    	}
		printf("\n");
	}
	
	return 0;
}
