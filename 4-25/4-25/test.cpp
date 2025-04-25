#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//·Ö·¢±ý¸É
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int ret = 0;
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (j == g.size()) break;
        if (s[i] >= g[j])
        {
            ret++;
            j++;
        }
    }
    return ret;
}
int main()
{
	return 0;
}