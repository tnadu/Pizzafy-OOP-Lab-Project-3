#ifndef TEMA_3_VEGETARIAN_PIZZA_H
#define TEMA_3_VEGETARIAN_PIZZA_H

class VegetarianPizza: public Pizza {
    Ingredient soy;

public:

    VegetarianPizza();

    VegetarianPizza(const VegetarianPizza &pizza);

    VegetarianPizza& operator=(const VegetarianPizza &pizza);

    friend istream& operator>>(istream &in, VegetarianPizza &pizza);

    friend ostream& operator<<(ostream &out, VegetarianPizza &pizza);

    int getPrice();

    ~VegetarianPizza();
};

#endif
