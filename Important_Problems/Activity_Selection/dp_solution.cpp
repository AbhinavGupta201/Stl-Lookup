/* 
We can observe that there are many overlapping problems
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Job
{
    int start;
    int finish;
    int profit;
};

bool comp(Job B, Job A)
{
    return (A.finish > B.finish);
}

int main()
{

    int n;
    cin >> n;
    vector<Job> activity(n);
    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> activity[i].start;
        cin >> activity[i].finish;
        cin >> activity[i].profit;
    }

    sort(activity.begin(), activity.end(), comp);
    int time = -1;
    cout << "jobs are:\nstart\tfinish\nprofit\n";
    for (int i = 0; i < n; i++)
    {
        cout << activity[i].start << "\t" << activity[i].finish << "\t" << activity[i].profit << endl;
    }
    cout << endl;

    int profit = 0;
    profit = maximiseProfit(activity, -1, 0);
    cout << profit << endl;
    return 0;
}
