#ifndef T_13
#define T_13

#include<iostream>
#include<string>

using std::istream;
using std::ostream;
data_item add(const data_item&,const data_item);
std::ostream &print(std::ostream&,const data_item);
std::istream &read(std::istream&, data_item&);
class data_item
{
friend data_item add(const data_item&,const data_item);
friend std::ostream &print(std::ostream&,const data_item);
friend std::istream &read(std::istream&, data_item&);
public:
    data_item()=default;
    data_item(const std::string &s):bookNo(s){}
    data_item(const std::string &s,unsigned n,double p):
             bookNo(s),units_sold(n),revenue(p*n){}
    data_item(std::istream&);
    std::string isbn()const{return bookNo;}
    data_item&combine(const data_item&);
    inline double avg_price()const;
private:
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};




inline
double data_item::avg_price() const
{
    if(units_sold)
        return revenue/units_sold;
    else
            return 0;
}

data_item& data_item ::combine(const data_item&rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is,data_item &item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}

std::ostream &print(std::ostream& os,const data_item &item)
{
    os << item.isbn() << " "
       << item.units_sold << " "
       << item.revenue << " "
       << item.avg_price();
    return os;
}

data_item add(const data_item& lhs, const data_item& rhs) 
{
    data_item sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif

