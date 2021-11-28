// Author - Yash Sinha , date:28-11-2021
// Shopping cart

#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
       Product(1,"iPhone", 2600),
       Product(3,"googlePixel", 2200),
       Product(2,"oneplus", 1500),
       Product(4,"samsung", 2600),
       Product(6,"macbookPro", 3200),
       
};

Product* chooseProduct(){
    //display the list of products
    string productList;
    cout<<"Products Available: "<<endl;

    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;
    cout<<"-----------------"<<endl;

    string choice;
    cout<<"Enter Your Choice(initial letter of the product): ";
    cin>>choice;

    for(int i=0; i < allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found!"<<endl;
    return NULL;
}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in Cash: ";
     int paid;
     cin>>paid;
     if(paid>=total){
         cout<<"Your Change: "<<paid-total<<endl;
         cout<<"Thank You for Shopping!";
         return true;
     }
     else{
         cout<<"Not enough Cash!";
         return false;
     }
}

int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action: (a)dd item, (v)iew cart, (c)heckout, (e)xit"<<endl;
        cin>>action;
        if(action=='a'){
           //ToDo: Add to cart
           //view all products + choose products + Add to the cary
           Product * product = chooseProduct();
           if(product!=NULL){
               cout<<"Item Added to the Cart "<<product->getDisplayName()<<endl;
               cart.addProduct(*product);
           }
        }
        else if(action == 'v'){
            // view the cart
            cout<<"-----------------"<<endl;
            cout<<cart.viewCart();
            cout<<"-----------------"<<endl;
        }
        else if(action == 'e'){
            cout<<"Shop some other time with us, Thank You!"<<endl;
            break;
        }
        else{
            //checkout
         cart.viewCart();
         if(checkout(cart)){
             break;
         }
        }
    }
   return 0;
}
