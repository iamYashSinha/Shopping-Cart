
#include<string>
using namespace std;
//forward declaration
class item;
class cart;

class Product{
   int id;
   string name;
   int price;

   public:
   //constructor- if i want to create a new product later
   Product(int unique_id, string name, int price){
       id = unique_id;
       this->name = name;
       this->price = price;
   }
    string getDisplayName(){
        return name + ": Rs" + to_string(price) + "\n";
    }
    string getShortName(){
        return name.substr(0,1);
    }
    friend class Item;
};

class Item{
    const Product product;
    int quantity;
    public:
    //constructor using a Init List 
    Item(Product p, int q):product(p), quantity(q){}

    int getItemPrice(){
        return quantity * product.price;
    }
    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + " Rs."+ to_string(quantity * product.price);
    }
};

class Cart{


};