#include <iostream>
#include "pizza.h"

Pizza::Ingredient::Ingredient(const Ingredient &ingredient) {
    name=ingredient.name;
    quantity=ingredient.quantity;
    price=ingredient.price;
}

Pizza::Ingredient& Pizza::Ingredient::operator=(const Ingredient &ingredient) {
    name=ingredient.name;
    quantity=ingredient.quantity;
    price=ingredient.price;
    return *this;
}

istream& operator>>(istream &in, Pizza::Ingredient &ingredient) {
    in>>ingredient.name>>ingredient.quantity;
    while(ingredient.quantity<0.0) {
        cout<<"Error: Ingredient quantity must be positive\n";
        cout<<">>> Enter a valid ingredient quantity: ";
        in>>ingredient.quantity;
    }

    in>>ingredient.price;
    while(ingredient.price<0.0) {
        cout<<"Error: Ingredient price must be positive\n";
        cout<<">>> Enter a valid ingredient price: ";
        in>>ingredient.price;
    }

    return in;
}

ostream& operator<<(ostream &out, const Pizza::Ingredient &ingredient) {
    out<<"Name: "<<ingredient.name<<" - Quantity: "<<ingredient.quantity<<"g - Price: "<<ingredient.price<<"€";
    return out;
}

void Pizza::Ingredient::setName(string name) {
    this->name=name;
}

string Pizza::Ingredient::getName() const {
    return name;
}

void Pizza::Ingredient::setQuantity(float quantity) {
    this->quantity=quantity;
}

float Pizza::Ingredient::getQuantity() const {
    return quantity;
}

void Pizza::Ingredient::setPrice(float price) {
    this->price=price;
}

float Pizza::Ingredient::getPrice() const {
    return price;
}