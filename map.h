#include <iostream>
#include <vector>
using namespace std;

template <class K, class V>
class map
{
private:
    vector<K> keys;
    vector<V> values;

public:
    void insert(const K &key, const V &value);
    V get(const K &key) const;
    bool contains(const K &key) const;
};
////////////////////////////////////////////////////////////////////
//
// Function Name : insert
// Description   : It is map Data Structure and this function is used to inset the
//                 the data in the form of keys and values.
// Parameter     : const key(reference),const value(reference)
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class K, class V>
void map<K, V>::insert(const K &key, const V &value)
{
    keys.push_back(key);
    values.push_back(value);
}

////////////////////////////////////////////////////////////////////
//
// Function Name : get
// Description   : It is map Data Structure and this function is used to get the value
//                 using keys.
// Parameter     : const key(reference)
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class K, class V>
V map<K, V>::get(const K &key) const
{
    for (register int i = 0; i < keys.size(); i++)
    {
        if (keys[i] == key)
        {
            return values[i];
        }
    }
    throw out_of_range("Key not found");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : contains
// Description   : It is map Data Structure and this function is used to check key 
//                 present or not
// Parameter     : const key(reference)
// Return Value  : bool
//
////////////////////////////////////////////////////////////////////

template <class K, class V>
bool map<K, V>::contains(const K &key) const
{
    for (const auto &k : keys)
    {
        if (k == key)
        {
            return true;
        }
    }
    return false;
}
