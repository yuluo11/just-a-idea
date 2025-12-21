#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main()
{
    /*
    vector<int>vi;
    int n;
    cin>>n;
    vector<double>vd(n);
    array<int,5>ai;
    array<double,10>ad={1.1,1.2,1.3};
    */
    int n;
    cin>>n;
    vector<int>vi(n);
    for(int i=0;i<n;i++)
    {
        cin>>vi[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(vi[j]>vi[j+1])
            {
                int temp;
                temp=vi[j];
                vi[j]=vi[j+1];
                vi[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<vi[i];
    }
    return 0;
}