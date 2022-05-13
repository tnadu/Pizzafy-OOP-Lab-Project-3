#include <iostream>
#include <vector>
#include "pizza.cpp"
#include "ingredient.cpp"
#include "order.cpp"
#include "online order.cpp"

using namespace std;

void addPizza(vector<Product *> &menu) {
    Product *aux;
    string input;
    int option;
    cout << "Add pizza menu:\n";
    cout << "Pizza types:\n";
    cout << "1) Regular\n";
    cout << "2) Vegetarian\n";
    cout << ">>> Enter a valid pizza type: ";

    cin >> input;
    try {
        option = stoi(input);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << input << "' not a number!";
        exit(1);
    }

    while (option < -1 or option > 2 or option == 0) {
        cout << "Error: Pizza type must be eiter 1, 2\n";
        cout << ">>> Enter a valid pizza type: ";
        cin >> input;
        try {
            option = stoi(input);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << input << "' not a number!";
            exit(1);
        }
    }

    if (option == -1) return;
    else if (option == 1) {
        aux = new Pizza;
        cout << "Pizza #" << menu.size() + 1 << ":\n";
        cin >> dynamic_cast<Pizza &>(*aux);
    } else {
        aux = new VegetarianPizza;
        cout << "Pizza #" << menu.size() + 1 << ":\n";
        cin >> dynamic_cast<VegetarianPizza &>(*aux);
    }

    menu.push_back(aux);
}

void print(const vector<Product *> &menu) {
    int i = 0;
    cout << "MENU:\n";
    for (auto itr = menu.begin(); itr != menu.end(); itr++) {
        cout << "#" << i << ": ";
        if (dynamic_cast<VegetarianPizza *>(*itr))
            cout << *dynamic_cast<VegetarianPizza *>(*itr);
        else cout << *dynamic_cast<Pizza *>(*itr);
        if (itr + 1 != menu.end()) cout << '\n';
        i++;
    }
}

int main() {
    vector<Product *> menu;
    Order *order = nullptr;
    int n;
    float auxf;
    string command = "-3", option1 = "-3", auxs;

    cout << "Welcome to Pizzafy v1.0 !\n";
    cout << "Ingredient input format (SPACE is used as a field delimiter):\n";
    cout << "\t\tIngredientName    Quantity   Price\n";
    cout << "Pizza input format (SPACE is used as a field delimiter):\n";
    cout << "\t\tPizzaName    NumberOfIngredients\n";

    cout << ">>> Enter labour cost: ";
    cin >> auxs;
    try {
        auxf = stof(auxs);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
        exit(1);
    }

    while (auxf <= 0.0) {
        cout << "Error: Labour cost must be positive\n";
        cout << ">>> Enter a valid labour cost: ";

        cin >> auxs;
        try {
            auxf = stof(auxs);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << auxs << "' not a number!";
            exit(1);
        }
    }
    Product::setLabourCost(auxf);

    cout << ">>> Enter the number of pizzas to be stored in the menu: ";
    cin >> auxs;
    try {
        n = stoi(auxs);
    }
    catch (...) {
        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
        exit(1);
    }

    while (n <= 0) {
        cout << "Error: Number of pizzas must be a positive integer\n";
        cout << ">>> Enter the number of pizzas to be stored in the menu: ";

        cin >> auxs;
        try {
            n = stoi(auxs);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << auxs << "' not a number!";
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) addPizza(menu);

    // program functions and instructions listing
    cout << "Pizzafy employs the following functions:\n";
    cout << "1) set labour cost\n";
    cout << "2) add pizza to menu\n";
    cout << "3) add ingredient to pizza from menu\n";
    cout << "4) remove pizza from menu\n";
    cout << "5) add pizza to order\n";
    cout << "6) remove pizza from order\n";
    cout << "7) new order \n";
    cout << "8) print menu\n";
    cout << "9) print order details\n";
    cout << "10) view instruction manual\n";
    cout << "11) view input formats\n";
    cout << "12) view program functions\n";


    while (stoi(command) != -2) {
        // request and verify input is valid (1-9 for menu options, -1 to abort, -2 to quit)
        cout << ">>> Enter a valid function-menu or command ID: ";
        cin >> command;
        try {
            stoi(command);
        }
        catch (...) {
            cout << "FATAL ERROR: \'" << command << "' not a number!";
            exit(1);
        }

        switch (stoi(command)) {
            case 1:
                cout << ">>> Enter labour cost: ";
                cin >> auxs;
                try {
                    auxf = stof(auxs);
                }
                catch (...) {
                    cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                    exit(1);
                }

                while (auxf <= 0.0) {
                    cout << "Error: Labour cost must be positive\n";
                    cout << ">>> Enter a valid labour cost: ";

                    cin >> auxs;
                    try {
                        auxf = stof(auxs);
                    }
                    catch (...) {
                        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                        exit(1);
                    }
                }
                Product::setLabourCost(auxf);
                break;

            case 2:
                addPizza(menu);
                break;

            case 3:
                cout << ">>> Enter the ID of the pizza to which an ingredient will be added: ";
                cin >> auxs;
                try {
                    n = stoi(auxs);
                }
                catch (...) {
                    cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                    exit(1);
                }

                while (n < -1 or n >= (int)menu.size()) {
                    cout << "Error: ID out of range\n";
                    cout << ">>> Enter the ID of the pizza to which an ingredient will be added: ";

                    cin >> auxs;
                    try {
                        n = stoi(auxs);
                    }
                    catch (...) {
                        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                        exit(1);
                    }
                }
                if (n == -1) break;

                dynamic_cast<Pizza *>(menu[n])->addIngredient();
                break;

            case 4:
                cout << ">>> Enter the ID of the pizza to be removed: ";
                cin >> auxs;
                try {
                    n = stoi(auxs);
                }
                catch (...) {
                    cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                    exit(1);
                }

                while (n < -1 or n >= (int)menu.size()) {
                    cout << "Error: ID out of range\n";
                    cout << ">>> Enter the ID of the pizza to be removed: ";

                    cin >> auxs;
                    try {
                        n = stoi(auxs);
                    }
                    catch (...) {
                        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                        exit(1);
                    }
                }
                if (n == -1) break;

                menu.erase(menu.begin() + n);
                break;

            case 5:
                if (not order) {
                    cout << "Error: No order has been created\n";
                    break;
                }

                order->add(menu);
                break;

            case 6:
                if (not order) {
                    cout << "Error: No order has been created\n";
                    break;
                }

                order->remove(menu);
                break;

            case 7:
                cout << "New order menu:\n";
                cout << "Order types:\n";
                cout << "1) Regular\n";
                cout << "2) Online (5% commission for every 10km) \n";
                cout << ">>> Enter a valid order type: ";

                cin >> option1;
                try {
                    stoi(option1);
                }
                catch (...) {
                    cout << "FATAL ERROR: \'" << option1 << "' not a number!";
                    exit(1);
                }

                while (stoi(option1) < -1 or stoi(option1) > 2 or stoi(option1) == 0) {
                    cout << "Error: Order type must be eiter 1 or 2\n";
                    cout << ">>> Enter a valid order type: ";

                    cin >> option1;
                    try {
                        stoi(option1);
                    }
                    catch (...) {
                        cout << "FATAL ERROR: \'" << option1 << "' not a number!";
                        exit(1);
                    }
                }

                if (stoi(option1) == -1) break;

                if (stoi(option1) == 1) {
                    if (not order) {
                        order = new Order;
                        break;
                    } else {
                        delete order;
                        order = new Order;
                        break;
                    }
                }

                if (stoi(option1) == 2) {
                    if (not order) {
                        order = new OnlineOrder;
                    } else {
                        delete order;
                        order = new OnlineOrder;
                    }

                    cout<<">>> Enter order distance: ";
                    cin >> auxs;
                    try {
                        stof(auxs);
                    }
                    catch (...) {
                        cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                        exit(1);
                    }

                    while (stof(auxs) <= 0.0) {
                        cout << "Error: Distance must be positive\n";
                        cout<<">>> Enter order distance: ";

                        cin >> auxs;
                        try {
                            stof(auxs);
                        }
                        catch (...) {
                            cout << "FATAL ERROR: \'" << auxs << "' not a number!";
                            exit(1);
                        }
                    }

                    dynamic_cast<OnlineOrder *>(order)->setDistance(stof(auxs));
                }

                break;

            case 8:
                print(menu);
                cout<<'\n';
                break;

            case 9:
                if (not order) {
                    cout << "Error: No order has been created\n";
                    break;
                }

                if (dynamic_cast<OnlineOrder *>(order))
                    cout << *dynamic_cast<OnlineOrder *>(order);
                else
                    cout << *order;

                cout<<"Total: "<<order->getPrice()<<"€\n";
                break;

            case 10:
                cout << "Instruction manual:\n";
                cout << "- function-menus, pizzas and ingredients can only be accessed by giving their ID number as input\n";
                cout << "- to abort current function-menu, type '-1'\n";
                cout << "- to quit the program, type '-2' in the home menu\n";
                break;

            case 11:
                cout << "Ingredient input format (SPACE is used as a field delimiter):\n";
                cout << "\t\tIngredientName    Quantity   Price\n";
                cout << "Pizza input format (SPACE is used as a field delimiter):\n";
                cout << "\t\tPizzaName    NumberOfIngredients\n";
                break;

            case 12:
                cout << "Pizzafy employs the following functions:\n";
                cout << "1) set labour cost\n";
                cout << "2) add pizza to menu\n";
                cout << "3) add ingredient to pizza from menu\n";
                cout << "4) remove pizza from menu\n";
                cout << "5) add pizza to order\n";
                cout << "6) remove pizza from order\n";
                cout << "7) new order \n";
                cout << "8) print menu\n";
                cout << "9) print order details\n";
                cout << "10) view instruction manual\n";
                cout << "11) view input formats\n";
                cout << "12) view program functions\n";
                break;

            case -1:
                cout << "Error: abort command can only be used inside function-menus\n";
                break;
            case -2:
                break;
            default:
                cout << "Error: out of range function-menu (1-10) and command (-1,-2) IDs\n";
                break;
        }
    }

    return 0;
}