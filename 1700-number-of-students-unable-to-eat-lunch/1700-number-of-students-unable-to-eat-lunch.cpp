class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentq;
        for (int st : students)
            studentq.push(st);

        int sandwichesIndex = 0;
        int processing = 0;
        while (!studentq.empty() && processing < students.size()) {

            int currStudent = studentq.front();
            studentq.pop();
            if (currStudent == sandwiches[sandwichesIndex]) {
                processing = 0;
                sandwichesIndex++;

            } else {
               processing++;
               studentq.push(currStudent);

            }
        }

        return sandwiches.size()- sandwichesIndex;
    }
};
