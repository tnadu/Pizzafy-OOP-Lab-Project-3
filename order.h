#ifndef TEMA_3_ORDER_H
#define TEMA_3_ORDER_H

#include "product.h"
#include "pizza.h"
#include "vegetarian pizza.h"
#include "menu.cpp"
#include <unordered_map>

using namespace std;

class Order {
    unordered_map<string, int> order, queue;
    float total;

public:
    Order(const unordered_map<string, int> &order, const unordered_map<string, int> &queue): order(order), queue(queue), total(0) {};

    Order(const Order &order);

    Order& operator=(const Order &order);

    friend istream& operator>>(istream &in, Order &order);

    friend ostream& operator<<(ostream &out, const Order &order);

    friend void update(Order &order, const Menu &menu);

    float getPrice() {return total;};

    ~Order() {};
};

#endif
