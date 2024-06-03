#include <bits/stdc++.h>
using namespace std;
struct item{
    int weight;
    int profit;
    double uniteprice;
    item(int w, int p) : weight(w), profit(p), uniteprice((double)p / w) {}

    bool operator<(const item &other) const{
        return uniteprice > other.uniteprice;
    }
};
int main() {
    int profit[] = {5, 10, 15, 7, 8, 9, 4};
    int weight[] = {1, 3, 5, 4, 1, 3, 2};
    int capacity = 12;
    vector<item> items;
    for (int i = 0; i < 7; i++)
    {
        items.push_back(item(weight[i], profit[i]));
    }

    sort(items.begin(), items.end());

    for (const auto &it : items)
    {
        cout << it.weight << "\t" << it.profit << "\t" << it.uniteprice << endl;
    }

    double total = 0.0;
    
    for (const auto &it : items)
    {
        if (it.weight <= capacity){
            total += it.profit;
            capacity -= it.weight;
        }
        else{
            total += it.uniteprice * capacity;
            break;
        }
    }
    cout << total << endl;
}
