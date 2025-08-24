class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        // Count how many students want 0 and 1
        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }

        // Process each sandwich
        for (int sw : sandwiches) {
            if (sw == 0) {
                if (count0 > 0) count0--;  // one student eats
                else break;                // no student wants 0 → stop
            } else { // sw == 1
                if (count1 > 0) count1--;  // one student eats
                else break;                // no student wants 1 → stop
            }
        }

        return count0 + count1; // remaining students
    }
};
