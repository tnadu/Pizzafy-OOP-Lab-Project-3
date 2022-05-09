#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Menu {
    vector<T> menu;

public:
    Menu(vector <T> menu): menu(0, T()) {};

    Menu(T &menu);

    T& operator=(T &menu);

    T& operator+=(T &menu);

    friend istream& operator>>(istream &in, Menu &menu) {
        int n;
        menu.clear();

        cout<<">>> Enter the number of types of pizza you wish to input: ";
        in>>n;
        while (n<=0) {
            cout<<"Error: Number of types of pizza must be a positive integer\n";
            cout<<">>> Enter the number of types of pizza you wish to input: ";
            in>>n;
        }

        for (int i=0; i<n; i++) {
            cout<<">>> Enter a pizza: ";
            T auxiliary;
            in>>auxiliary;
            menu.push_back(auxiliary);
        }

        return in;
    }

    friend ostream& operator<< (ostream &out, const Menu &menu) {
        cout<<"MENU:\n";
        for (auto itr=menu.menu.begin(); itr!=menu.menu.end(); itr++)
            cout<<menu.menu[itr]<<'\n';

        return out;
    }

    void modifyProduct(int id);

    ~Menu() {};

    Menu();
};



template <typename T> Menu<T>::Menu(T &menu) {
    this->menu=menu.menu;
}

template <typename T> T& Menu<T>::operator=(T &menu) {
    this->menu=menu.menu;
    return *this;
}

template <typename T> T& Menu<T>::operator+=(T &menu) {
    cout<<">>> Enter a pizza: ";
    T auxiliary;
    cin>>auxiliary;
    menu.push_back(auxiliary);
    return *this;
}

template <typename T> void Menu<T>::modifyProduct(int id) {
    int option;
    string name;

    cout<<"Modify pizza field options:\n";
    cout<<"1) Name\n";
    cout<<"2) Add ingredient\n";
    cout<<"3) Modify ingredient\n";
    cout<<">>> Enter a valid option or command ID: ";
    cin>>option;
    while(option < -1 or option>3 or option==0) {
        cout<<"Error: Out of range modify-pizza-field-menu option (1-3) and command (-1)\n";
        cout<<">>> Enter a valid option or command ID: ";
        cin>>option;
    }

    if (option==-1) {
        cout<<"Aborting\n";
        return;
    }

    if (option==1) {
        cout<<">>> Enter a new name for \""<<menu[id]<<"\": ";
        cin>>name;
        menu[id].setName(name);
        cout<<"Pizza name has been modified\n";
        return;
    }

    if (option==2) {
        menu[id].modifyIngredient();
        return;
    }

    if (option==3) {
        menu[id].addIngredient();
        return;
    }
}

