#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    int arr[3][4];
    for(auto& row:arr )
    {
        for(auto& col:row)
        {
            cin>>col;
            cout<<col;
        }
    }
    
    return 0;
}