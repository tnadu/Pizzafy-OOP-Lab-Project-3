#ifndef TEMA_3_ORDER_H
#define TEMA_3_ORDER_H

#include "product.h"
#include "pizza.h"
#include "vegetarian pizza.h"
#include <unordered_map>

using namespace std;

class Order {
protected:
    unordered_map<const Product*, int> receipt;
    float total;

public:
    Order(): total(0) {};

    Order(const Order &order);

    Order& operator=(const Order &order);

    friend ostream& operator<<(ostream &out, const Order &order);

    void add(vector<Product *>menu);

    void remove(vector<Product *>menu);

    virtual float getPrice() {return total;};

    ~Order() {};
};

#endif