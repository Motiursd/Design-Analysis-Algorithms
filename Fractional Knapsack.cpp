#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    Item arr[] = {{60,10}, {100,20}, {120,30}};
    int n = 3;
    int W = 50; 

    sort(arr, arr+n, compare);

    double totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= W) {
            
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    cout << "Maximum value = " << totalValue;
}
