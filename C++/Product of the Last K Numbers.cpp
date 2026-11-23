#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class ProductOfNumbers
{
public:
    vector<int> b;
    ProductOfNumbers()
    {
        b.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            b.clear();
            b.push_back(1);
        }
        else
        {
            b.push_back(b[b.size() - 1] * num);
        }
    }

    int getProduct(int k)
    {
        if (k > b.size())
            return 0;
        else
            return b[b.size() - 1] / b[b.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */