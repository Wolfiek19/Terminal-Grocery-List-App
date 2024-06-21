#include "grocery.h"
using namespace std;
//================================GroceryItem===================================
ostream& operator<<(ostream& o, const GroceryItem& g){
    o << g.ID << " : " << g.quantity << " : " << g.name << " : " << g.description << " : " << "$" << g.price;
    return o;
}
GroceryItem::GroceryItem(){
    name = " ";
    description = " ";
    price = 0;
    quantity = 0;
    ID = 1;
}
GroceryItem::GroceryItem(int ID, string name, string description, double price, int quantity){
    this -> ID = ID;
    this -> name = name;
    this -> description = description;
    this -> price = price;
    this -> quantity = quantity;
}
GroceryItem::GroceryItem(string name, string description, double price, int quantity){
    this -> name = name;
    this -> description = description;
    this -> price = price;
    this -> quantity = quantity;
}
string GroceryItem::getName() const{
    return name;
}
string GroceryItem::getDescription() const{
    return description;
}
double GroceryItem::getPrice() const{
    return price;
}
int GroceryItem::getQuantity() const{
    return quantity;
}
int GroceryItem::getID() const {
    return ID;
}
void GroceryItem::setName(string name){
    this -> name = name;
}
void GroceryItem::setDescription(string description){
    this -> description = description;
}
void GroceryItem::setPrice(double price){
    this -> price = price;
}
void GroceryItem::setQuantity(int quantity){
    this -> quantity = quantity;
}
void GroceryItem::setID(int ID){
    this -> ID = ID;
}


//================================GroceryList===================================
ostream& operator<<(ostream& o, const GroceryList& g){
    for(int i = 0; i < g.size; i++){
        o << g.grocery[i] << endl;
    }
    return o;
}
void GroceryList::resize(){
    GroceryItem* tmp = new GroceryItem[capacity + 1];
    for(int i = 0; i < size; i++){
        tmp[i] = grocery[i];
    }
    delete [] grocery;
    grocery = tmp;
    capacity = capacity + 1;
}
GroceryList::GroceryList(){
    capacity = 5;
    size = 0;

    grocery = new GroceryItem[capacity];
}
GroceryList::GroceryList(const GroceryList& g){
    size = g.size;
    capacity = g.capacity;

    grocery = new GroceryItem[capacity];
    for(int i = 0; i < size; i++){
        grocery[i] = g.grocery[i];
    }
}
GroceryList& GroceryList::operator=(const GroceryList& g){
    size = g.size;
    capacity = g.capacity;
    delete [] grocery;
    grocery = new GroceryItem[capacity];
    for(int i = 0; i < size; i++){
        grocery[i] = g.grocery[i];
    }
    return *this;
}
GroceryList::~GroceryList(){
    delete [] grocery; //Destructor used to delete the data on the heap
}
void GroceryList::Create(const GroceryItem& g){
    int ID;
    string name;
    string description;
    double price;
    int quantity;
    
    if(size >= capacity){
        resize();
    }
    grocery[size++] = g; 
       
}
GroceryItem GroceryList::Read() const {
    cout << "Here is yout current shopping list." << endl;
    for(int i = 0; i < size; i++){
        cout << grocery[i] << endl;
    }
    return GroceryItem();
}
void GroceryList::Update(int ID){
    string name, description;
    double price;
    int quantity;
    for(int i = 0; i < size; i ++){
        if(grocery[i].getID() == ID){
            cout << "Please enter your updated values" << endl;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Description: ";
            getline(cin, description);
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;
            grocery[i].setName(name);
            grocery[i].setQuantity(quantity);
            grocery[i].setPrice(price);
            grocery[i].setDescription(description);
            break;
        }
        
    }
    cout << "Here is your updated list." << endl;
    for(int i = 0; i < size; i++){
        cout << grocery[i] << endl;
    }
}
void GroceryList::Delete(int ID){
    int deleteIndex = -1;
    for(int i = 0; i < size; i++){
        if(grocery[i].getID() == ID){
            deleteIndex = i;
            break;
        }
    }
    if(deleteIndex != -1){
        grocery[deleteIndex] = grocery[size + 1];
        size--;
    }
}