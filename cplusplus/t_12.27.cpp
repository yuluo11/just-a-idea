#include<iostream>
void sortbyuse(std::vector<int>&v,int n);
int main()
{
    int n;
    std::cin>>n;
    std::vector<int>vi(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>vi[i];
    }
    sortbyuse(vi,n);
    for(int i=0;i<n;i++)
    {
        std::cout<<vi[i];
    }
    return 0;
}
void sortbyuse(std::vector<int>&v,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                int & temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
            //int & temp=v[i];
            //v[i]=
        }
    }
}