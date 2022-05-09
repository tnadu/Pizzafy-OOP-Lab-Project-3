#ifndef TEMA_3_PIZZA_H
#define TEMA_3_PIZZA_H

#include <iostream>
#include "product.h"

using namespace std;

class VegetarianPizza;

class Pizza: public Product {
protected:
    class Ingredient {
        string name;
        float quantity, price;

    public:
        Ingredient(const string &name="Default", float quantity=0, float price=0): name(name), quantity(quantity), price(price) {};

        Ingredient(const Ingredient &ingredient);

        Ingredient& operator=(const Ingredient &ingredient);

        friend istream& operator>>(istream &in, Ingredient &ingredient);

        friend ostream& operator<<(ostream &out, const Ingredient &ingredient);

        void setName(string name);

        string getName() const;

        void setQuantity(float quantity);

        float getQuantity() const;

        void setPrice (float price);

        float getPrice() const;

        ~Ingredient() {};
    };

    string name;
    int numberOfIngredients;
    static float labour;
    Ingredient *ingredients;

public:

    Pizza(const string &name="Default", int numberOfIngredients=0): Product(), name(name), numberOfIngredients(numberOfIngredients) {
        ingredients=new Ingredient[13];
    };

    Pizza(const Pizza &pizza);

    Pizza& operator=(const Pizza &pizza);

    friend istream& operator>>(istream &in, Pizza &pizza);

    friend ostream& operator<<(ostream &out, const Pizza &pizza);

    void setName(const string &name);

    string getName() const;

    void addIngredient();

    void modifyIngredient();

    float getPrice() const;

    static void setLabourCost(float cost);

    ~Pizza() {delete[]ingredients;};

    friend istream& operator>>(istream &in, Ingredient &ingredient);

    friend ostream& operator<<(ostream &out, const Pizza::Ingredient &ingredient);

    friend istream& operator>>(istream &in, VegetarianPizza &pizza);

    friend ostream& operator<<(ostream &out, VegetarianPizza &pizza);

};

float Pizza::labour=0;

void Pizza::setLabourCost(float cost) {labour=cost;}

#endif