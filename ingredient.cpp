#include <iostream>
#include "ingredient.h"

Ingredient::Ingredient(const Ingredient &ingredient) {
    name=ingredient.name;
    quantity=ingredient.quantity;
    price=ingredient.price;
}

Ingredient& Ingredient::operator=(const Ingredient &ingredient) {
    name=ingredient.name;
    quantity=ingredient.quantity;
    price=ingredient.price;
    return *this;
}

istream& operator>>(istream &in, Ingredient &ingredient) {
    string input;
    cout<<">>> Enter an ingredient: ";

    in>>ingredient.name;
    in>>input;
    try {
        ingredient.quantity=stof(input);
    }
    catch (...) {
        cout<<"FATAL ERROR: \'"<<input<<"' not a number!";
        exit(1);
    }

    while(ingredient.quantity<=0.0) {
        cout<<"Error: Ingredient quantity must be positive\n";
        cout<<">>> Enter a valid ingredient quantity: ";

        in>>input;
        try {
            ingredient.quantity=stof(input);
        }
        catch (...) {
            cout<<"FATAL ERROR: \'"<<input<<"' not a number!";
            exit(1);
        }
    }

    in>>input;
    try {
        ingredient.price=stof(input);
    }
    catch (...) {
        cout<<"FATAL ERROR: \'"<<input<<"not a number!";
        exit(1);
    }
    while(ingredient.price<=0.0) {
        cout<<"Error: Ingredient price must be positive\n";
        cout<<">>> Enter a valid ingredient price: ";

        in>>input;
        try {
            ingredient.price=stof(input);
        }
        catch (...) {
            cout<<"FATAL ERROR: \'"<<input<<"not a number!";
            exit(1);
        }
    }

    return in;
}

ostream& operator<<(ostream &out, const Ingredient &ingredient) {
    out<<"Ingredient Name: "<<ingredient.name<<" - Quantity: "<<ingredient.quantity<<"g - Price (per gram): "<<ingredient.price<<"€";
    return out;
}

void Ingredient::setName(string name) {
    this->name=name;
}

string Ingredient::getName() const {
    return name;
}

void Ingredient::setQuantity(float quantity) {
    this->quantity=quantity;
}

float Ingredient::getQuantity() const {
    return quantity;
}

void Ingredient::setPrice(float price) {
    this->price=price;
}

float Ingredient::getPrice() const {
    return price;
}