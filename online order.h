#ifndef TEMA_3_ONLINE_ORDER_H
#define TEMA_3_ONLINE_ORDER_H

#include "order.h"

class OnlineOrder: public Order {
    float distance;

public:
    OnlineOrder(float distance=0): Order(), distance(distance) {};

    OnlineOrder(const OnlineOrder &order);

    OnlineOrder& operator=(const OnlineOrder &order);

    friend ostream& operator<<(ostream &out, const OnlineOrder &order);

    void setDistance(float distance);

    float getPrice();

    ~OnlineOrder() {};
};

#endif