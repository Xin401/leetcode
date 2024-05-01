#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    // 2ms
    //  int countStudents(vector<int> &students, vector<int> &sandwiches)
    //  {
    //      deque<int> studentsDeque(students.begin(), students.end());
    //      deque<int> sandwichesDeque(sandwiches.begin(), sandwiches.end());
    //      int count = studentsDeque.size();
    //      int flag = count;
    //      while (flag)
    //      {
    //          if (studentsDeque.front() == sandwichesDeque.front())
    //          {
    //              studentsDeque.pop_front();
    //              sandwichesDeque.pop_front();
    //              count--;
    //              flag = count;
    //          }
    //          else
    //          {
    //              studentsDeque.push_back(studentsDeque.front());
    //              studentsDeque.pop_front();
    //              flag--;
    //          }
    //      }
    //      return count;
    //  }
    //  0ms
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        vector<int> count(2, 0);
        for (int student : students)
        {
            count[student]++;
        }
        for (int sandwich : sandwiches)
        {
            if (count[sandwich] == 0)
            {
                break;
            }
            else
            {
                count[sandwich]--;
            }
        }
        return count[0] + count[1];
    }
};

int main()
{
    Solution s;
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << s.countStudents(students, sandwiches) << endl;
    return 0;
}