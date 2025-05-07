#include<iostream>
using namespace std;
//»µÁËµÄ¼ÆËãÆ÷
int brokenCalc(int startValue, int target) {
    int ret = 0;
    while (target != startValue)
    {
        if (target % 2)
        {
            ret++;
            target++;
        }
        else
        {
            if (target > startValue)
            {
                target /= 2;
                ret++;
            }
            else
            {
                target++;
                ret++;
            }
        }
    }
    return ret;
}
int main()
{
	return 0;
}