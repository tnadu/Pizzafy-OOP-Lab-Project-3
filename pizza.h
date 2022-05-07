#ifndef TEMA_3_PIZZA_H
#define TEMA_3_PIZZA_H

using namespace std;

class Pizza: public Product {
protected:
    class Ingredient {
        string name;
        float quantity, price;

    public:
        Ingredient(string name="Default", float quantity=0, float price=0): name(name), quantity(quantity), price(price) {};

        Ingredient(const Ingredient &ingredient);

        Ingredient& operator=(const Ingredient &ingredient);

        friend istream& operator>>(istream &in, Ingredient &ingredient);

        friend ostream& operator<<(ostream &out, const Ingredient &ingredient);

        void setName(string name);

        string getName();

        void setQuantity(float quantity);

        float getQuantity();

        void setPrice (float price);

        float getPrice();

        ~Ingredient();
    };

private:
    string name;
    int numberOfIngredients;
    static int labour;
    Ingredient ingredients[13];     //  average pizza has 12.5 ingredients (https://www.spoonablerecipes.com/common-ingredients-in-pizza-dishes)

public:

    Pizza(string name="Default", int numberOfIngredients=0);

    Pizza(const Pizza &pizza);

    Pizza& operator=(const Pizza &pizza);

    friend istream& operator>>(istream &in, Pizza &pizza);

    friend ostream& operator<<(ostream &out, const Pizza &pizza);

    void setName(const string &name);

    string getName();

    void addIngredient(); //    increment numberOfIngredients; cin>>ingredients[index]

    void printIngredients(); //     for i... cout<<ingredients[i]

    int getPrice();

    static void setLabour();

    ~Pizza();
};

int Pizza::labour=0;

#endif
