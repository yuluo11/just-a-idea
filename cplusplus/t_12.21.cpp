#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
//Bubble Sort use vector 
//vector
void vector_sort(vector<int>&v,int n);
//void point_sort(int*n);
int main()
{
    //int *p=new int[n];
    //cin>>*p;
    //int s=strlen(*p);false
    int n;
    cin>>n;
    vector<int> vi(n);

    for(int i=0;i<n;i++)
    {
        cin>>vi[i];
    }
    vector_sort(vi,n);
    for(int i=0;i<n;i++)
    {
        cout<<vi[i];
    }
    ofstream file("test.txt",ios::out);
    if(!file)
    {
        cerr<<"open file fail"<<endl;
        exit(1);
    }
    for(int i=0;i<n;i++)
    {
        file<<vi[i]<<" ";
    }
    file.close();
    //point_sort(p);
    return 0;
}
void vector_sort(vector<int>& v,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}
//void point_sort(int*n)
//{
    //for(int i=0;i<)
//}