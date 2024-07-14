#include <bits/stdc++.h>
using namespace std;

// Link : leetcode.com/problems/stock-price-fluctuation/

class StockPrice {
    unordered_map<int,int> timeToPrice;
    map<int,int> priceToFreq;
    int latestTime;
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);

        // Decrease frequency of old price.
        if(timeToPrice.count(timestamp)) {
            int oldPrice = timeToPrice[timestamp];
            if(priceToFreq[oldPrice] == 1)
                priceToFreq.erase(oldPrice);
            else
                priceToFreq[oldPrice] -= 1;
        }

        // Increment the frequency of new price
        priceToFreq[price] += 1;

        // Update the price in timeToPrice map;
        timeToPrice[timestamp] = price;
    }
    
    int current() {
        return timeToPrice[latestTime];
    }
    
    int maximum() {
        auto it = --priceToFreq.end();
        return it->first; // return the maximum price.
    }
    
    int minimum() {
        auto it = priceToFreq.begin();
        return it->first; // return the maximum price.
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main() {
	// your code goes here
	return 0;
}