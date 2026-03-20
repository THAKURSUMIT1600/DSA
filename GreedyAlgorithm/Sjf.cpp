#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

double calculateAverageWaitingTime(vector<int> &jobs)
{
    int totalwaitingtime = 0;
    int currentwaitingtime = 0;
    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < jobs.size(); i++)
    {

        totalwaitingtime += currentwaitingtime;
        currentwaitingtime += jobs[i];
    }

    return (double)totalwaitingtime / jobs.size();
}

int main()
{

    // Input
    vector<int> jobs = {4, 3, 7, 1, 2};

    // Function call
    double avg = calculateAverageWaitingTime(jobs);

    // Output
    cout << "Average Waiting Time: " << avg << endl;

    return 0;
}