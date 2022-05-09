#include <iostream>
#include "pizza.h"
#include "vegetarian pizza.h"

using namespace std;

//  Regular Pizza

Pizza::Pizza(const Pizza &pizza) {
    name=pizza.name;
    numberOfIngredients=pizza.numberOfIngredients;
    ingredients=new Ingredient[pizza.numberOfIngredients];

    for (int i=0; i<numberOfIngredients; i++) ingredients[i]=pizza.ingredients[i];
}

Pizza& Pizza::operator=(const Pizza &pizza) {
    name=pizza.name;
    numberOfIngredients=pizza.numberOfIngredients;

    for (int i=0; i<numberOfIngredients; i++) ingredients[i]=pizza.ingredients[i];
    return *this;
}

istream& operator>>(istream &in, Pizza &pizza) {
    in>>pizza.name>>pizza.numberOfIngredients;

    while(pizza.numberOfIngredients<=0) {
        cout<<"Error: Number of ingredients must be a positive integer\n";
        cout<<">>> Enter a valid number of ingredients: ";
        in>>pizza.numberOfIngredients;
    }

    for(int i=0; i<pizza.numberOfIngredients; i++) {
        cout<<"Ingredient #"<<i<<": ";
        in>>pizza.ingredients[i];
    }

    return in;
}

ostream& operator<<(ostream &out, const Pizza &pizza) {
    out<<"Pizza Name: "<<pizza.name<<"\nIngredients:\n";

    for(int i=0; i<pizza.numberOfIngredients; i++) {
        out<<"\tIngredient #"<<i<<": ";
        out<<pizza.ingredients[i];
        if(i!=pizza.numberOfIngredients-1) out<<'\n';
    }

    return out;
}

void Pizza::setName(const string &name) {
    this->name=name;
}

string Pizza::getName() const {return name;}

void Pizza::addIngredient() {
    Ingredient auxiliary[++numberOfIngredients];
    for (int i=0; i<numberOfIngredients-1; i++) auxiliary[i]=ingredients[i];
    delete[]ingredients;
    ingredients=new Ingredient[numberOfIngredients];
    cin>>ingredients[numberOfIngredients-1];
    for (int i=0; i<numberOfIngredients-1; i++) ingredients[i]=auxiliary[i];
    return;
}

void Pizza::modifyIngredient() {
    int index;
    cout<<">>> Enter an index between 0 and "<<numberOfIngredients-1<<", or -1 to abort: ";
    cin>>index;
    while (index<-1 or index>=numberOfIngredients) {
        cout<<"Error: Index out of range\n";
        cout<<">>> Enter an index between 0 and "<<numberOfIngredients-1<<", or -1 to abort: ";
        cin>>index;
    }

    if (index==-1) return;
    cin>>ingredients[index];
}

float Pizza::getPrice() const {
    float total=0;
    for(int i=0; i<numberOfIngredients; i++) total+=ingredients[i].getQuantity() * ingredients[i].getPrice();
    return total;
}

//  Vegetarian Pizza

VegetarianPizza::VegetarianPizza(const VegetarianPizza &pizza): Pizza(pizza) {
    soy=pizza.soy;
}

VegetarianPizza& VegetarianPizza::operator=(const VegetarianPizza &pizza) {
    name=pizza.name;
    numberOfIngredients=pizza.numberOfIngredients;
    soy=pizza.soy;

    for (int i=0; i<numberOfIngredients; i++) ingredients[i]=pizza.ingredients[i];
    return *this;
}

istream& operator>>(istream &in, VegetarianPizza &pizza) {
    in>>dynamic_cast<Pizza&>(pizza);
    cout<<"Soy (quantity, price): ";
    float quantity, price;
    cin>>quantity>>price;
    pizza.soy.setQuantity(quantity);
    pizza.soy.setPrice(price);
    return in;
}

ostream& operator<<(ostream &out, VegetarianPizza &pizza) {
    out<<dynamic_cast<const Pizza&>(pizza)<<"\n\tSoy: Quantity: "<<pizza.soy.getQuantity()<<"g - Price: "<<pizza.soy.getPrice()<<"€";
    return out;
}

float VegetarianPizza::getPrice() const {
    Pizza auxiliary(dynamic_cast<const Pizza&>(*this));
    float price=auxiliary.getPrice();
    price+=this->soy.getPrice()*this->soy.getQuantity();
    return price;
}