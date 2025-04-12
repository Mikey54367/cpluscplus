#include<iostream>
#include<stack>
#include<string>
using namespace std;
//»ù±¾¼ÆËãÆ÷2
int calculate(string s) {
    char ope = '+';
    stack<int> st;
    int num = 0;
    int i = 0;
    for (; i < s.size(); ++i)
    {
        if (s[i] == ' ') continue;
        if (s[i] >= '0' && s[i] <= '9')
        {
            num *= 10;
            num += s[i] - '0';
        }
        else
        {
            if (ope == '+')
            {
                ope = s[i];
                st.push(num);
                num = 0;
            }
            else if (ope == '-')
            {
                ope = s[i];
                st.push(-num);
                num = 0;
            }
            else if (ope == '*')
            {
                ope = s[i];
                int tmp = st.top();
                st.pop();
                tmp = tmp * num;
                st.push(tmp);
                num = 0;
            }
            else if (ope == '/')
            {
                ope = s[i];
                int tmp = st.top();
                st.pop();
                tmp = tmp / num;
                st.push(tmp);
                num = 0;
            }
        }
    }
    if (ope == '+')
    {
        ope = s[i];
        st.push(num);
        num = 0;
    }
    else if (ope == '-')
    {
        ope = s[i];
        st.push(-num);
        num = 0;
    }
    else if (ope == '*')
    {
        int tmp = st.top();
        st.pop();
        tmp = tmp * num;
        st.push(tmp);
        num = 0;
    }
    else if (ope == '/')
    {
        int tmp = st.top();
        st.pop();
        tmp = tmp / num;
        st.push(tmp);
        num = 0;
    }
    int ret = 0;
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    return ret;
}
int main()
{
    calculate("2*3+4");
	return 0;
}