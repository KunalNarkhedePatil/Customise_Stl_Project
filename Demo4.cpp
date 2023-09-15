#include "map.h"
int main()
{
    map<char, int> m;

    m.insert('a', 25);
    m.insert('b', 30);
    m.insert('c', 22);

    if (m.contains('a'))
    {
        cout << "m: " << m.get('a') << endl;
    }
    else
    {
        cout << "m not found in the map." << endl;
    }

    return 0;
}
