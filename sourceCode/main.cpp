#include <iostream>
#include <string> // 命令空间是全局，需要用到标准命令空间
using namespace std;
class book_base{
private:
    string isbn;
protected:
    float price;
public:
    book_base(string sales_isbn, float sales_price):price(sales_price),isbn(sales_isbn){};
    virtual float net_price(int n){
      return n*price;
    }
};
class bulk_item:public book_base{
private:
    float discount;
    int min_qty;
public:
    bulk_item():book_base("NULL",0.0),discount(0.0),min_qty(0.0){};
    bulk_item(string sales_isbn, float sales_price,int qty =0, float dis_rate =0.0):book_base(sales_isbn,sales_price),discount(dis_rate),min_qty(qty){};
    virtual float net_price(int n){
      return (n*price*(1-discount));
    }
};
float total_price(book_base &book,int n){
  return book.net_price(n);
}

int main() {
  book_base basebook("123",12.5);
  bulk_item bulkbook("123",12.5,30,0.1);
  cout<<basebook.net_price(50)<<endl;
  cout<<bulkbook.net_price((50))<<endl;
  cout<<total_price(basebook,50)<<endl;
  cout<<total_price(bulkbook,50)<<endl;
  return 0;
}
