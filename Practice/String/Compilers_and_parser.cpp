#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t, n, i;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int n;
        n = s.size();
        stack<char> st;
        int res = 0, count = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                st.push('<');
            }
            else if (st.empty() == false)
            {
                count += 2;
                st.pop();
                if(st.empty()==true)
                    res = max(res, count);
            }
            else
            {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}