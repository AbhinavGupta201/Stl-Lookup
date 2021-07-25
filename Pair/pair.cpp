/* Pair: it is a derived datatype not a container
 */
#include <iostream>
using namespace std;

int main()
{
    // Syntax: pair< T, T > p;
    pair<int, int> p; // {0,0}
    cout << "first: " << p.first << " second: " << p.second << endl;

    //initilisation whiledeclearation 
    pair<int, int> p2 = {2, 3}; // {2,3}

    // after the declearation
    // To access : p.first and p.second
    pair<int, int> p3;
    p3.first = 20;
    p3.second = 39;

    // pair of pair
    pair< pair<int,int> , int >p4; // { {0,0},0}
    p4.first={2,3};
    p4.second=5;
    cout<<p4.first.first<<endl;
    cout<<p4.first.second<<endl;
    cout<<p4.second<<endl;

    return 0;
}