#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, m, x, y, count = 0, range = 0;
    cin >> t;
    while (t--)
    {
        cin >> m >> x >> y;
        vector<int> copsLocation(m);
        for (int i = 0; i < m; i++)
        {
            cin >> copsLocation[i];
        }
        vector<int> houses(101, 0);
        for (int i = 0; i < m; i++)
        {
            int index;
            index = ((copsLocation[i] - x * y) < 1) ? 1 : (copsLocation[i] - x * y);
            houses[index] += 1;
            index = ((copsLocation[i] + x * y > 100)) ? 100 : (copsLocation[i] + x * y);
            houses[index] += -1;           
        }
        range = 0;
        count = 0;

        cout << endl;
        for (int i = 1; i <= 100; i++)
        {
            if(houses[i]!=0)
                range+=houses[i];
            else if(range==0)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}