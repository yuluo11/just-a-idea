#include<iostream>
#include"Sales_item.h"
int main()
{
    Sales_item Curritem,Valitem;
    if(std::cin>>Curritem)
    {
        int cnt=1;
        while(std::cin>>Valitem)
        {
            if(Curritem.isbn()==Valitem.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout<<Curritem<<"occurs"<<cnt<<"times"<<std::endl;
                Curritem=Valitem;
                cnt=1;
            }
        }
        std::cout<<Curritem<<"occurs"<<cnt<<"times"<<std::endl;
    }

}