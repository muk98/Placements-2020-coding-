#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		if(s[0]=='0')
			break;
		vector<int> arr(256,0);
		int i=0;
		while(i<s.length())
		{
			arr[s[i]]++;
			i++;
		}
		int c=0;
		for(int i=0;i<256;i++)
			if(arr[i]%2==1)
				c++;
		if(c>1)
			cout<<"Impossible"<<endl;
		else
		{
			int n=s.length();
			int i=0;
			int swaps=0;
			while(i<n/2)
			{
				int j=n-i-1;
				if(s[i]==s[j])
					i++;
				else
				{
					// cout<<"HI";
					int p=0,q=0;
					for(q=i+1;s[j]!=s[q];q++);
					for(p=j-1;s[i]!=s[p];p--);
						// cout<<q<<" "<<p<<endl;
					swaps+=min(q-i,j-p);
					// cout<<swaps<<endl;
					if(q-i<j-p)
					{
						for(int k=q;k>i;k--)
							swap(s[k],s[k-1]);
					}
					else
					{
						for(int k=p;k<j;k++)
							swap(s[k],s[k+1]);
					}
					// i++;
				}
			}
            cout<<s<<endl;
			cout<<swaps<<endl;
		}
	}
	return 0;

}