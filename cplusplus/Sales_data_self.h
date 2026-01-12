#include<iostream>
#include<string>
typedef struct item
{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
}data;
int main()
{
    data total;
    double totalPrice;
    if(std::cin>>total.bookNo>>total.units_sold>>totalPrice)
    {
        total.revenue=totalPrice*total.units_sold;
        data trans;
        double transPrice;
        while(std::cin>>trans.bookNo>>trans.units_sold>>transPrice)
        {
            trans.revenue=transPrice*trans.units_sold;
        }
        if(trans.bookNo==total.bookNo)
        {
           total.units_sold+=trans.units_sold;
           total.revenue+=trans.revenue;
        }
        else
        {
            std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
        }
    
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}