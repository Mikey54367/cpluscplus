#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Í¨¼õ×Ö·û´®Æ¥Åä
vector<int> diStringMatch(string s) {
    int n = s.size();
    int Max = s.size();
    int Min = 0;
    vector<int> ret(n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'I') ret[i] = Min++;
        else ret[i] = Max--;
    }
    ret[n] = Min;
    return ret;
}
int main()
{

	return 0;
}