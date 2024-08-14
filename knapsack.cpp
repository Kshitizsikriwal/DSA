#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item
{
public:
    float price;
    float weight;
    float ratio;

public:
    Item(float p, float w)
    {
        this->price = p;
        this->weight = w;
        this->ratio = p / w;
    }
};

bool comparator(Item a, Item b)
{
    return (a.ratio > b.ratio);
}

class Knapsack
{
public:
    int capacity;
    vector<Item> items;

public:
    Knapsack(int c)
    {
        this->capacity = c;
    }

    void addItems(float p, float w)
    {
        items.push_back(Item(p, w));
    }

    float maximizedPrice()
    {
        sort(items.begin(), items.end(), comparator);

        float totalPrice = 0.0;
        float currWeight = 0.0;

        for (auto &item : items)
        {
            if (currWeight + item.weight <= capacity)
            {
                currWeight += item.weight;
                totalPrice += item.price;
            }
            else
            {
                double remWeight = capacity - currWeight;
                totalPrice += remWeight * item.ratio;
                break;
            }
        }
        return totalPrice;
    }
};

int main()
{
    Knapsack k1(20);
    k1.addItems(10000, 7);
    k1.addItems(20000, 5);
    k1.addItems(5000, 10);

    float p = k1.maximizedPrice();
    cout << "Maximized price is: " << p << endl;

    return 0;
}
