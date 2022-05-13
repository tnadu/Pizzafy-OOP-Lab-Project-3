#include <iostream>
#include "online order.h"

using namespace std;

OnlineOrder::OnlineOrder (const OnlineOrder &order): Order(order) {
    distance=order.distance;
}

OnlineOrder& OnlineOrder::operator=(const OnlineOrder &order) {
    receipt=order.receipt;
    total=order.total;
    distance=order.distance;
}

ostream& operator<<(ostream &out, const OnlineOrder &order) {
    out<<"ONLINE "<<dynamic_cast<const Order&>(order);
}

void OnlineOrder::setDistance(float distance) {
    this->distance=distance;
}

float OnlineOrder::getPrice() {
    float price=total;
    for (int d=10; d<=distance; d+=10) price+=price*(float)0.05;
    return price;
}