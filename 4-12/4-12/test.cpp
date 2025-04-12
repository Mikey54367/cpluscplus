#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int i = 0;
	for (; i < n; ++i)
	{
		if (s1[i] == '.' && s2[i] == '.')
		{
			continue;
		}
		break;
	}
	int j = 0;
	for (j = n - 1; j >= 0; --j)
	{
		if (s1[j] == '.' && s2[j] == '.')
		{

		}
		else break;
	}
	n = j + 1;
	vector<int> dp(n, 0);
	dp[i] = 0;
	i++;
	for (; i < n; ++i)
	{
		if (s1[i] == '#' && s2[i] == '#')
			dp[i] = dp[i - 1];
		else if (s1[i] == '.' && s2[i] == '#')
		{
			if (s2[i - 1] == '#')
			{
				dp[i] = dp[i - 1];
			}
			else
			{
				if (s1[i - 1] == '#')
				{
					dp[i] = dp[i - 1] + 1;
					s1[i] = '#';
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
		}
		else if (s2[i] == '.' && s1[i] == '#')
		{
			if (s1[i - 1] == '#')
			{
				dp[i] = dp[i - 1];
			}
			else
			{
				if (s2[i - 1] == '#')
				{
					dp[i] = dp[i - 1] + 1;
					s2[i] = '#';
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
		}
		else
		{
			if (s1[i - 1] == '#' && s2[i - 2] == '#')
				dp[i] = dp[i - 1] + 1;
			else if (s1[i - 1] == '.' && s2[i - 1] == '.')
				dp[i] = dp[i - 1] + 1;
			else
			{
				if (s1[i - 1] == '#')
					s1[i] == '#';
				else
					s2[i] = '#';
				dp[i] = dp[i - 1] + 1;
			}
		}

	}
	int ret = *max_element(dp.begin(), dp.end());
	printf("%d\n", ret);
	return 0;
}
/*int main()
{
	int n=0;
	int m=0;
	scanf("%d %d",&n,&m);
	vector<long long> v(n);
	for(int i=0;i<n;++i)
	{
		scanf("%ld",&v[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i)
	{
		v[i]=v[i]*v[i];
	}
	int mini=(long long)INT_MAX*(long long)20;
	int k=0;
	for(int i=0;i+m-1<n;++i)
	{
		if(v[i+m-1]-v[i]<mini)
		{
			mini=v[i+m-1]-v[i];
			k=i;
		}
	}
	int ret=0;
	for(int i=k+1;i<=k+m-1;++i)
	{
		ret+=v[i]-v[i-1];
	}
	printf("%ld\n",ret);
	return 0;
}

int ret=0;
int mul1=1;
int mul2=1;
bool arr[2026]={false};
void dfs()
{
	for(int i=1;i<=2025;i++)
	{
		if(arr[i]) continue;

	}
}
int main()
{

	return 0;
}*/
/*int main()
{
	int a=8;
	printf("%d\n",a);
}
int main()
{
	int k=1e9+7;
	int n=0;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&v[i]);
	}
	if(n==1)
	{
		printf("%d\n",v[0]);
		return 0;
	}
	if(n==2)
	{
		int a=((v[0]+v[0])%k+(v[0]^v[1]))%k;
		printf("%d\n",a);
		return 0;
	}
	if(n==3)
	{
		int a=0;
		a+=v[0]^v[1]^v[2];
		a%=k;
		a+=v[0]^v[1];
		a%=k;
		a+=v[2];
		a%=k;
		a+=v[0]^v[1]-v[2];
		a%=k;
		//a+=v[0]+(v[1]^v[2]);
		a+=v[0];
		a%=k;
		a+=(v[1]^v[2]);
		a%=k;
		a+=v[0]-(v[1]^v[2]);
		a+=v[0];
		a%=k;
		a+=v[0];
		a%=k;
		a+=v[0];
		a%=k;
		a+=v[0];
		a%=k;
		printf("%d\n",a);
		return 0;
	}
	return 0;
}*/

/*int main()
{
	int n=0;
	int m=0;
	scanf("%d %d",&n,&m);
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i)
	{
		v[i]=v[i]*v[i];
	}
	int mini=INT_MAX;
	int k=0;
	for(int i=0;i+m-1<n;++i)
	{
		if(v[i+m-1]-v[i]<mini)
		{
			mini=v[i+m-1]-v[i];
			k=i;
		}
	}
	int ret=0;
	for(int i=k+1;i<=k+m-1;++i)
	{
		ret+=v[i]-v[i-1];
	}
	printf("%d\n",ret);
	return 0;
}
/*int main()
{
	int n=0;
	scanf("%d",&n);
	int ret=0;
	while(n--)
	{
		int a=0;
		scanf("%d",&a);
		if(a%3==0)
			ret++;
	}
	printf("%d\n",ret);
	return 0;
}
int main1()
{
	int t=0;
	scanf("%d",&t);
	while(t--)
	{
		int a=0;
		int b=0;
		int c=0;
		int k=0;
		scanf("%d %d %d %d",&a,&b,&c,&k);
		while(k--)
		{
			int tmpa=a;
			int tmpb=b;
			int tmpc=c;
			a=(tmpb+tmpc)/2;
			b=(tmpa+tmpc)/2;
			c=(tmpa+tmpb)/2;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}*/