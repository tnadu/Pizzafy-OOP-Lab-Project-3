#ifndef TEMA_3_VEGETARIAN_PIZZA_H
#define TEMA_3_VEGETARIAN_PIZZA_H

#include "product.h"
#include "pizza.h"

using namespace std;

class VegetarianPizza: public Pizza {
    Ingredient soy;

public:

    VegetarianPizza(): Pizza() {soy.setName("Soy");};

    VegetarianPizza(const VegetarianPizza &pizza);

    VegetarianPizza& operator=(const VegetarianPizza &pizza);

    friend istream& operator>>(istream &in, VegetarianPizza &pizza);

    friend ostream& operator<<(ostream &out, VegetarianPizza &pizza);

    float getPrice() const;

    ~VegetarianPizza() {};
};

#endif
