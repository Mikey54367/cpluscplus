#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = heights.size();
    vector<int> index(n);
    for (int i = 0; i < n; ++i)
    {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&heights](int i, int j) {
        return heights[i] > heights[j];
        });
    vector<string> ret;
    for (int i = 0; i < n; ++i)
    {
        ret.emplace_back(names[index[i]]);
    }
    return ret;
}
int main()
{
	return 0;
}