#include <iostream>
using namespace std;

class GroceryItem{
    friend ostream& operator<<(ostream& o, const GroceryItem& g);
    private:
        string name;
        string description;
        double price;
        int quantity;
        int ID;
    public:
        GroceryItem();
        GroceryItem(int ID, string name, string description, double price, int quantity);
        GroceryItem(string name, string description, double price, int quantity);
        string getName() const;
        string getDescription() const;
        double getPrice() const;
        int getQuantity() const;
        int getID() const;
        void setName(string name);
        void setDescription(string description);
        void setPrice(double price);
        void setQuantity(int quantity);
        void setID(int ID);
        
        
};

class GroceryList{
    friend ostream& operator<<(ostream& o, const GroceryList& g);
    private:
        GroceryItem* grocery;
        int size, capacity;
        void resize();

    public:
        GroceryList();
        GroceryList(const GroceryList& g); 
        GroceryList& operator=(const GroceryList& g);
        ~GroceryList();
        void Create(const GroceryItem& g);
        GroceryItem Read() const;
        void Update(int ID);
        void Delete(int ID);
};