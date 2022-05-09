#include <iostream>
#include "order.h"

using namespace std;

Order::Order(const Order &order) {
    this->order=order.order;
    this->queue=order.queue;
    this->total=order.total;
}

Order& Order::operator=(const Order &order) {
    this->order=order.order;
    this->queue=order.queue;
    this->total=order.total;
    return *this;
}

//  add (string, int) pair to 'queue', which will be verified in the update() method
istream& operator>>(istream &in, Order &order) {
    int id;
    string name;
    order.queue[name]=id;
    return in;
}

ostream& operator<<(ostream &out, const Order &order) {


    return out;
}

void update(Order &order, const Menu &menu) {
    unordered_map<string, int>::iterator itr;
    for(itr=order.queue.begin(); itr!=order.queue.end(); itr++)
        for
}