#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main()
{
	string input;
	int q;
	stack<char> stack;
	bool balance;
	
	while(scanf("%d ",&q)==1)
	{
		for(int i=0;i<q;i++)
		{
			balance=true;
			while( !stack.empty() ) stack.pop();
			getline(cin,input);
			for(int i=0;i<input.length();i++)
			{
				if( input[i] == '(' || input[i] == '[' )
          			stack.push( input[i] );
       			else if( input[i] == ')' ){
          			if( stack.empty() || stack.top() != '(' ){
            			balance = 0;
           				break;
          			}
          			stack.pop();
        		}
       			else if( input[i] == ']' ){
          			if( stack.empty() || stack.top() != '[' ){
            			balance = 0;
            			break;
          			}
          			stack.pop();
        		}	
			}
			if( !stack.empty() ) balance = 0; //alarm
			if(balance)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
} 
