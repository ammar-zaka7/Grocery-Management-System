#pragma once

#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <fstream>
#include <iomanip>
using namespace std;

struct GroceryItem 
{
    int code;
    string name;
    int price;
    int quantity;

    GroceryItem(int c, string n, int p, int q)
    {
        code = c;
        name = n;
        price = p;
        quantity = q;
    }
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    list<GroceryItem>* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = new list<GroceryItem>();
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            delete table[i];
        }
    }

    int hash(int key) const {
        return key % TABLE_SIZE;
    }

    int getQ(int c) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto it = table[i]->begin(); it != table[i]->end(); ++it)
            {
                if (c == it->code)
                    return it->quantity;
            }
        }
    }
    int getP(int c) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto it = table[i]->begin(); it != table[i]->end(); ++it)
            {
                if (c == it->code)
                    return it->price;
            }
        }
    }
    void setQ(int c, int q)
    {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto it = table[i]->begin(); it != table[i]->end(); ++it)
            {
                if (c == it->code)
                    it->quantity -= q;
            }
        }
    }

    void insert(const GroceryItem& item) {
        int index = hash(item.code);
        table[index]->push_front(item);
    }

   /* bool sell(const int& code, const float& quantity) {
        int index = hash(code);
        list<GroceryItem>* list = table[index];
        for (auto it = list->begin(); it != list->end(); ++it) {
            if (it->code == code) {
                if (it->quantity >= quantity) {
                    it->quantity -= quantity;
                    if (it->quantity == 0) {
                        it = list->erase(it);
                    }
                    else {
                        --it;
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return false;
    }

    bool addQuantitties(const int& code, const float& quantity) {
        int index = hash(code);
        list<GroceryItem>* list = table[index];
        for (auto it = list->begin(); it != list->end(); ++it) {
            if (it->code == code)
            {
                it->quantity += quantity;
                return true;
            }
        }
        return false;
    }*/

    //void saveToFile(const string& filename) const {
    //    ofstream outFile(filename);
    //    if (!outFile) {
    //        cout << "Error: cannot open file " << filename << " for writing" << endl;
    //        return;
    //    }
    //    for (int i = 0; i < TABLE_SIZE; i++) {
    //        for (auto it = table[i]->begin(); it != table[i]->end(); ++it) {
    //            outFile << it->code << " " << it->name << " " << it->price << " " << it->quantity << endl;
    //        }
    //    }
    //    cout << "Data saved to file " << filename << endl;
    //}

    void loadFromFile(const string& filename) 
    {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error: cannot open file " << filename << " for reading" << endl;
            return;
        }
        int code, quantity, price;
        string name;
        while (inFile >> code >> name >> price >> quantity) {
            insert(GroceryItem(code, name, price, quantity));
        }

    }


    void print() const {

        cout << "Displaying products." << endl;
        cout << "_____________________________\n";
        cout << left << setw(5) << "No";
        cout << left << setw(10) << "Name";
        cout << left << setw(7) << "Price";
        cout << left << setw(5) << "Quatity";
        cout << endl;
        cout << "_____________________________\n";


        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto it = table[i]->begin(); it != table[i]->end(); ++it) 
            {
                cout << left << setw(5) << it->code;
                cout << left << setw(10) << it->name;
                cout << left << setw(7) << it->price;
                cout << left << setw(5) << it->quantity;
                cout << endl;
            }
        }
        
    }

    bool search()
    {
        int c;
        bool flag = false;
        cout << "Enter code of item: ";
        cin >> c;
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto it = table[i]->begin(); it != table[i]->end(); ++it)
            {
                if (c == it->code)
                {
                    flag = true;

                    cout << "\nDisplaying product." << endl;
                    cout << "_____________________________\n";
                    cout << left << setw(5) << "No";
                    cout << left << setw(10) << "Name";
                    cout << left << setw(7) << "Price";
                    cout << left << setw(5) << "Quatity";
                    cout << endl;
                    cout << "_____________________________\n";
                    cout << left << setw(5) << it->code;
                    cout << left << setw(10) << it->name;
                    cout << left << setw(7) << it->price;
                    cout << left << setw(5) << it->quantity;
                    cout << endl;
                    break;
                }
            }
        }
        if (!flag)
            cout << "Product not found." << endl;


        return flag;
    }
};