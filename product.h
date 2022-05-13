#ifndef TEMA_3_PRODUCT_H
#define TEMA_3_PRODUCT_H

using namespace std;

class Product {
protected:
    static float labour;
    virtual float getPrice() const = 0;
public:
    static void setLabourCost(float cost);
    static float getLabourCost();
};

float Product::labour=0;

void Product::setLabourCost(float cost) {labour=cost;}

float Product::getLabourCost() {return labour;}

#endif