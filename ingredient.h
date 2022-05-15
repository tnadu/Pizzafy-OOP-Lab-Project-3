#ifndef TEMA_3_INGREDIENT_H
#define TEMA_3_INGREDIENT_H

using namespace std;

class Ingredient {
    string name;
    float quantity, price;

public:
    Ingredient(const string &name = "Default", float quantity = 0, float price = 0) : name(name), quantity(quantity), price(price) {};

    Ingredient(const Ingredient &ingredient);

    Ingredient &operator=(const Ingredient &ingredient);

    friend istream &operator>>(istream &in, Ingredient &ingredient);

    friend ostream &operator<<(ostream &out, const Ingredient &ingredient);

    void setName(string name);

    string getName() const;

    void setQuantity(float quantity);

    float getQuantity() const;

    void setPrice(float price);

    float getPrice() const;

    ~Ingredient() {};
};

#endif
