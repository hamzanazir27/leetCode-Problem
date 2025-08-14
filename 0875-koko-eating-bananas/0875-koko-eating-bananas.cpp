// /*
// ##Understanding
// Koko has several piles of bananas. She has h hours before the guards return.
// She will choose a fixed eating speed k (bananas per hour).
// In each hour, she will choose one pile and eat exactly k bananas from it.
// If the pile has more than k bananas → she eats k and leaves the rest for later.
// If the pile has less than k bananas → she eats all of them and doesn’t eat
// anything else in that hour. The goal is to find the smallest possible k that
// allows Koko to finish all bananas in h hours or less. If k is too small → she
// will be too slow and run out of time. If k is big enough → she will finish
// earlier, but we want the slowest speed that still finishes on time.





// */

// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {

//         int left = 1;
//         int mid = 0;
//         int right = INT_MIN;
//         for (int pil : piles)
//             right = max(pil, right);

//         while (left <= right) {
//             mid = left + (right - left) / 2;
//             if (h == helperCheck(piles, mid)) {
//                 return mid;
//             } else if (mid > h) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }

//         } // while ---->|||||||||||||||||||||||||||||||| ------->

//         return mid;
//     }

//     int helperCheck(vector<int>& piles, int h) {
//         int num = 0;
//         for (int pil : piles)
//             num = num + ceil(pil / h);

//         return num;
//     }
// };



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalHours = helperCheck(piles, mid);

            if (totalHours <= h) {

                // Speed is enough, try slower
                right = mid - 1;

            } else {

                // Speed is too slow
                left = mid + 1;

            }
        }
        return left; // smallest valid speed
    }

    long long  helperCheck(vector<int>& piles, int speed) {
        long long  total = 0;
        for (int pil : piles) {
            total += ceil((double)pil / speed);
        }
        return total;
    }
};
