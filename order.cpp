#include <iostream>
#include <vector>
#include "order.h"

using namespace std;

Order::Order(const Order &order) {
    this->receipt = order.receipt;
    this->total = order.total;
}

Order &Order::operator=(const Order &order) {
    this->receipt = order.receipt;
    this->total = order.total;
    return *this;
}

ostream &operator<<(ostream &out, const Order &order) {
    out << "RECEIPT:\n";
    for (auto itr = order.receipt.begin(); itr != order.receipt.end(); itr++) {
        if (dynamic_cast<const VegetarianPizza *>(itr->first))
            cout << " - " << dynamic_cast<const VegetarianPizza *>(itr->first)->getName() << " - quantity: " << itr->second << '\n';
        else
            cout << " - " << dynamic_cast<const Pizza *>(itr->first)->getName() << " - quantity: " << itr->second << '\n';
    }

    return out;
}

void Order::add(const vector<Product *> menu) {
    string input;
    int index, quantity;
    Product *auxiliary;

    cout << ">>> Enter the ID of the pizza to be added: ";
    cin >> input;
    try {
        index = stoi(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (index < -1 or index >= (int) menu.size()) {
        cout << "Error: ID out of range\n";
        cout << ">>> Enter the ID of the pizza to be added: ";

        cin >> input;
        try {
            index = stoi(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "not a number!";
            exit(1);
        }
    }
    if (index == -1) return;

    cout << ">>> Enter a valid quantity: ";
    cin >> input;
    try {
        quantity = stoi(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (quantity <= 0) {
        cout << "Error: Quantity must be a positive integer\n";
        cout << ">>> Enter a valid quantity: ";
        cin >> input;
        try {
            quantity = stoi(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "not a number!";
            exit(1);
        }
    }

    auxiliary = menu[index];
    if (dynamic_cast<const VegetarianPizza *>(auxiliary))
        total += dynamic_cast<const VegetarianPizza *>(auxiliary)->getPrice() * (float) quantity;
    else
        total += dynamic_cast<const Pizza *>(auxiliary)->getPrice() * (float) quantity;
    receipt[auxiliary] = quantity;
}

void Order::remove(vector<Product *> menu) {
    string input;
    int index;
    Product *auxiliary;

    cout << ">>> Enter the ID of the pizza to be removed: ";
    cin >> input;
    try {
        index = stoi(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "not a number!";
        exit(1);
    }

    while (index < -1 or index >= (int) menu.size()) {
        cout << "Error: ID out of range\n";
        cout << ">>> Enter the ID of the pizza to be removed: ";

        cin >> input;
        try {
            index = stoi(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "not a number!";
            exit(1);
        }
    }
    if (index == -1) return;

    auxiliary = menu[index];
    if (dynamic_cast<const VegetarianPizza *>(auxiliary))
        total -= dynamic_cast<const VegetarianPizza *>(auxiliary)->getPrice() * receipt[auxiliary];
    else
        total -= dynamic_cast<const Pizza *>(auxiliary)->getPrice() * receipt[auxiliary];
    receipt.erase(auxiliary);
}