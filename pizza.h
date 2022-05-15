#ifndef TEMA_3_PIZZA_H
#define TEMA_3_PIZZA_H

#include <iostream>
#include "product.h"
#include "ingredient.h"

using namespace std;

class VegetarianPizza;

class Pizza : public Product {
protected:
    string name;
    int numberOfIngredients;
    Ingredient *ingredients;

public:

    Pizza(const string &name = "Default", int numberOfIngredients = 0) : Product(), name(name), numberOfIngredients(numberOfIngredients) {
        ingredients = new Ingredient[13];
    };

    Pizza(const Pizza &pizza);

    Pizza &operator=(const Pizza &pizza);

    friend istream &operator>>(istream &in, Pizza &pizza);

    friend ostream &operator<<(ostream &out, const Pizza &pizza);

    void setName(const string &name);

    string getName() const;

    void addIngredient();

    float getPrice() const;

    ~Pizza() { delete[]ingredients; };

};

#endif