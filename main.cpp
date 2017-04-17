#include <iostream>
#include <stdlib.h>
#include "TBitSet.h"

using namespace std;

int main()
{
    bool data[] = {1,0,1,0,1,1,0,0,1,0,0,1};
    cout<<"sizeof(data) = "<<sizeof(data)<<"\n";
    TBitSet bs(data, sizeof(data)), bs1(data, sizeof(data));
    size_t i = 0;
    while(i<bs.size())
	{

        cout<<"bs["<<i<<"]="<<bs[i]<<"\n";
        i++;
    }
    cout<<"bs==bs1:"<<(bs==bs1)<<'\n';

    cout<<"bs!=bs1:"<<(bs!=bs1)<<'\n';

    cout<<"bs<<2\n";
    bs<<=4;
    cout<<"bs>>3\n";
    bs1>>=3;
    cout<<"print:\n";
    i = 0;
    bs[1] = 1;
    bs1[1] = 1;
    bs1[0] = 1;
    TBitSet bs2 = bs1&bs;
    bs = bs2;
    while(i<bs.size())
	{

        cout<<"bs["<<i<<"] = "<<bs[i]<<" \t"<<"bs1["<<i<<"] = "<<bs1[i]<<"\n";
        i++;
    }
    cout<<"bs==bs1:"<<(bs==bs1)<<'\n';

    cout<<"bs!=bs1:"<<(bs!=bs1)<<'\n';
   
    return 0;
}
