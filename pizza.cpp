#include <iostream>
#include "pizza.h"
#include "vegetarian pizza.h"

using namespace std;

//  Regular Pizza

Pizza::Pizza(const Pizza &pizza) {
    name = pizza.name;
    numberOfIngredients = pizza.numberOfIngredients;
    ingredients = new Ingredient[pizza.numberOfIngredients];

    for (int i = 0; i < numberOfIngredients; i++) ingredients[i] = pizza.ingredients[i];
}

Pizza &Pizza::operator=(const Pizza &pizza) {
    name = pizza.name;
    numberOfIngredients = pizza.numberOfIngredients;

    for (int i = 0; i < numberOfIngredients; i++) ingredients[i] = pizza.ingredients[i];
    return *this;
}

istream &operator>>(istream &in, Pizza &pizza) {
    string input;
    cout << ">>> Enter a pizza:\n";

    in >> pizza.name;
    in >> input;
    try {
        pizza.numberOfIngredients = stoi(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (pizza.numberOfIngredients <= 0) {
        cout << "Error: Number of ingredients must be a positive integer\n";
        cout << ">>> Enter a valid number of ingredients: ";

        in >> input;
        try {
            pizza.numberOfIngredients = stoi(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "not a number!";
            exit(1);
        }
    }

    for (int i = 0; i < pizza.numberOfIngredients; i++) {
        cout << "Ingredient #" << i << ":\n";
        in >> pizza.ingredients[i];
    }

    return in;
}

ostream &operator<<(ostream &out, const Pizza &pizza) {
    out << "Pizza Name: " << pizza.name << "\n\tIngredients:\n";

    for (int i = 0; i < pizza.numberOfIngredients; i++) {
        out << "\t\t#" << i << ": ";
        out << pizza.ingredients[i];
        if (i != pizza.numberOfIngredients - 1) out << '\n';
    }

    return out;
}

void Pizza::setName(const string &name) {
    this->name = name;
}

string Pizza::getName() const { return name; }

void Pizza::addIngredient() {
    Ingredient auxiliary[++numberOfIngredients];
    for (int i = 0; i < numberOfIngredients - 1; i++) auxiliary[i] = ingredients[i];
    delete[]ingredients;
    ingredients = new Ingredient[numberOfIngredients];
    cout << "Ingredient #" << numberOfIngredients - 1 << ":\n";
    cin >> ingredients[numberOfIngredients - 1];
    for (int i = 0; i < numberOfIngredients - 1; i++) ingredients[i] = auxiliary[i];
    return;
}

float Pizza::getPrice() const {
    float total = 0;
    for (int i = 0; i < numberOfIngredients; i++) total += ingredients[i].getQuantity() * ingredients[i].getPrice();
    return total + labour;
}

//  Vegetarian Pizza

VegetarianPizza::VegetarianPizza(const VegetarianPizza &pizza) : Pizza(pizza) {
    soy = pizza.soy;
}

VegetarianPizza &VegetarianPizza::operator=(const VegetarianPizza &pizza) {
    name = pizza.name;
    numberOfIngredients = pizza.numberOfIngredients;
    soy = pizza.soy;

    for (int i = 0; i < numberOfIngredients; i++) ingredients[i] = pizza.ingredients[i];
    return *this;
}

istream &operator>>(istream &in, VegetarianPizza &pizza) {
    string input;
    float quantity, price;

    in >> dynamic_cast<Pizza &>(pizza);
    cout << "Soy (quantity, price): ";

    in >> input;
    try {
        quantity = stof(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (quantity <= 0.0) {
        cout << "Error: Ingredient quantity must be positive\n";
        cout << ">>> Enter a valid ingredient quantity: ";

        in >> input;
        try {
            quantity = stof(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "' not a number!";
            exit(1);
        }
    }

    in >> input;
    try {
        price = stof(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (price <= 0.0) {
        cout << "Error: Ingredient price must be positive\n";
        cout << ">>> Enter a valid ingredient price: ";

        in >> input;
        try {
            price = stof(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "' not a number!";
            exit(1);
        }
    }

    pizza.soy.setQuantity(quantity);
    pizza.soy.setPrice(price);
    return in;
}

ostream &operator<<(ostream &out, VegetarianPizza &pizza) {
    out << dynamic_cast<const Pizza &>(pizza) << "\nSoy: Quantity: " << pizza.soy.getQuantity() << "g - Price (per gram): " << pizza.soy.getPrice() << "€";
    return out;
}

float VegetarianPizza::getPrice() const {
    Pizza auxiliary(dynamic_cast<const Pizza &>(*this));
    float price = auxiliary.getPrice();
    price += this->soy.getPrice() * this->soy.getQuantity();
    return price;
}