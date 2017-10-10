#include <iostream>
#include <HashNode.h>
#include <KeyHash.h>
#include <HashMap.h>

using namespace std;

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};

int main()
{
    HashMap<int, string, MyKeyHash> hmap;
    hmap.put(1, "val1");
    hmap.put(2, "val2");
    hmap.put(3, "val3");

    string value;
    hmap.get(2, value);
    cout << value << endl;
    bool res = hmap.get(3, value);
    if (res)
        cout << value << endl;
    hmap.remove(3);
    res = hmap.get(3, value);
    if (res)
        cout << value << endl;

    return 0;
}
