// Author - Yash Sinha , date:28-11-2021
// Shopping cart

#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
       Product(1,"iPhone13", 2600),
       Product(3,"Google Pixel 6", 2200),
       Product(3,"Oneplus 9", 1500),
       Product(3,"Samsung Galaxy Fold", 2600),
       Product(3,"Macbook Pro", 3200),
       
};

Product* chooseProduct(){
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

    for(int i=0; i< allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found!"<<endl;
    return NULL;
}

int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action: (a)dd item, (v)iew cart, (c)heckout"<<endl;
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
        else{
            //checkout
        }
    }
   return 0;
}
