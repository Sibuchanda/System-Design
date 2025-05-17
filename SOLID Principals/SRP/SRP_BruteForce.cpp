#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Produxt class
class Product{
public:
    int price;
    string name;

    Product(string name, int price){
        this->price=price;
        this->name=name;
    }
};

// --- Shopping cart ---
class ShoppingCart{
    private:
     vector<Product*> products;

     public:
     // Adding products
       void addProduct(Product *p){
        products.push_back(p);
       }

       vector<Product *>  &getAllProducts(){
             return products;
       }

       // Calculate Total 
       double calculateTotal(){
        double total=0;
        for(int i=0;i<products.size();i++){
            total+=products[i]->price;
        }
        return total;
       }

    // Printing Invoice
       void PrintInvoice(){
        cout<<"---- Invoice of Shopping card -----"<<endl;

        for(int i=0;i<products.size();i++){
            cout<<products[i]->name<<" -Rs "<<products[i]->price<<endl;
        }

        cout<<"Total is : "<< calculateTotal() <<endl;
       }

       // Save data into database ---- comment
       void saveToDataBase(){
        cout<<"Saving cart to database"<<endl;
       }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Mobile", 12000));
    cart->addProduct(new Product("Shirt", 600));

    cart->PrintInvoice();
    cart->saveToDataBase();
    return 0;
    
}