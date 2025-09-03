#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int price;
    int stock;

    Item(string n, int p, int s) {
        name = n;
        price = p;
        stock = s;
    }
};

class CartItem {
public:
    string name;
    int price;
    int quantity;

    CartItem(string n, int p, int q) {
        name = n;
        price = p;
        quantity = q;
    }
};

class VendingMachine {
private:
    vector<Item> inventory;
    vector<CartItem> cart;
    int insertedMoney;

public:
    VendingMachine() {
        insertedMoney = 0;
        inventory.push_back(Item("Coke", 50, 5));
        inventory.push_back(Item("Chips", 30, 3));
        inventory.push_back(Item("Water", 20, 10));
    }

    void showItems() {
        cout << "\nAvailable Items:\n";
        for (int i = 0; i < (int)inventory.size(); i++) {
            cout << i + 1 << ". " << inventory[i].name
                 << " | Price: " << inventory[i].price
                 << " | Stock: " << inventory[i].stock << "\n";
        }
    }

    void addToCart() {
        int choice, quantity;
        showItems();
        cout << "Enter item number to add to cart: ";
        cin >> choice;
        if (choice < 1 || choice > (int)inventory.size()) {
            cout << "Invalid item number!\n";
            return;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        if (quantity <= 0 || quantity > inventory[choice - 1].stock) {
            cout << "Invalid quantity or not enough stock!\n";
            return;
        }
        cart.push_back(CartItem(inventory[choice - 1].name, inventory[choice - 1].price, quantity));
        cout << quantity << " " << inventory[choice - 1].name << "(s) added to cart.\n";
    }

    int calculateTotal() {
        int total = 0;
        for (int i = 0; i < (int)cart.size(); i++) {
            total += cart[i].price * cart[i].quantity;
        }
        return total;
    }

    void insertMoney() {
        int money;
        cout << "Insert money: ";
        cin >> money;
        if (money <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        insertedMoney += money;
        cout << "Total inserted: " << insertedMoney << "\n";
    }

    void checkout() {
        int totalCost = calculateTotal();
        if (totalCost == 0) {
            cout << "Cart is empty!\n";
            return;
        }
        cout << "Total cost: " << totalCost << "\n";
        while (insertedMoney < totalCost) {
            cout << "Insufficient money. Please insert more.\n";
            insertMoney();
        }
        cout << "Purchase successful! Dispensing items:\n";
        for (int i = 0; i < (int)cart.size(); i++) {
            cout << cart[i].quantity << " x " << cart[i].name << "\n";
            for (int j = 0; j < (int)inventory.size(); j++) {
                if (inventory[j].name == cart[i].name) {
                    inventory[j].stock -= cart[i].quantity;
                }
            }
        }
        int change = insertedMoney - totalCost;
        if (change > 0) {
            cout << "Returning change: " << change << "\n";
        }
        cart.clear();
        insertedMoney = 0;
    }

    void start() {
        int choice;
        do {
            cout << "\n--- Vending Machine Menu ---\n";
            cout << "1. Show Items\n";
            cout << "2. Add Item to Cart\n";
            cout << "3. Insert Money\n";
            cout << "4. Checkout\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();
            if (choice == 1) showItems();
            else if (choice == 2) addToCart();
            else if (choice == 3) insertMoney();
            else if (choice == 4) checkout();
            else if (choice == 5) cout << "Exiting Vending Machine.\n";
            else cout << "Invalid choice!\n";
        } while (choice != 5);
    }
};

int main() {
    VendingMachine vm;
    vm.start();
    return 0;
}
