#include <iostream>
#include "pizza.cpp"
#include "ingredient.cpp"
//#include "order.cpp"
#include "menu.cpp"

using namespace std;

int main() {
    int i;
    string name;
    VegetarianPizza test;
    cin>>test;
    cout<<'\n'<<test<<"\n\n";
    cout<<"Price: "<<test.getPrice();

    Menu<Pizza> hmm;
//    cout<<">>> Enter the ID of the pizza to be modified: ";
//    cin>>index;
//    while (index<-1 or index>=menu.size()) {
//        cout<<"Error: Index out of range\n";
//        cout<<">>> Enter an index between 0 and "<<menu.size()-1<<", or -1 to abort: ";
//        cin>>index;
//    }
//    if (index==-1) return;


    return 0;
}

