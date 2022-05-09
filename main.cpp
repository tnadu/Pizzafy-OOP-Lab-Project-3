#include <iostream>
#include "product.h"
#include "pizza.h"
#include "vegetarian pizza.h"
#include "pizza.cpp"
#include "ingredient.cpp"


using namespace std;

int main() {
    int i;
    string name;
    VegetarianPizza test;
    cin>>test;
    cout<<'\n'<<test<<"\n\n";
    cout<<"Price: "<<test.getPrice();

    return 0;
}