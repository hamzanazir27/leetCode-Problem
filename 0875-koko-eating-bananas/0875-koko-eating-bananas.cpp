// /*
// ##Understanding
// Koko has several piles of bananas. She has h hours before the guards return.
// She will choose a fixed eating speed k (bananas per hour).
// In each hour, she will choose one pile and eat exactly k bananas from it.
// If the pile has more than k bananas → she eats k and leaves the rest for
// later. If the pile has less than k bananas → she eats all of them and doesn’t
// eat anything else in that hour. The goal is to find the smallest possible k
// that allows Koko to finish all bananas in h hours or less. If k is too small
// → she will be too slow and run out of time. If k is big enough → she will
// finish earlier, but we want the slowest speed that still finishes on time.

// Approch

// max number in array
// minimum 1 kha sakta hai koko banana
// ab maximum lgain tu hours k equal b ho sakta hai aur km b aur minimum
// lgayauin tu array k size k equal b aur km b tu hum ne ya tu min ya max ya in
// k drmayan wala koi number lena hai

// tu hum binary search lgai mid ko check kiya hourn  k equal aur km acceptble
// hai koshesh kro equal mil jaye
//   nhi tu km tu hum ne condition lgai min<=max
// mid ko check krtey tehy ager tu mid k hisab se km value aye tu hour se km
// value aye tu hamey ye axceptble hai but hum ne kaha ager tu is se br jaye
// slice tu best hai slice tb hi barey ga ager min jb slice chota kiya jaye
// metlab maximum mid k bad rakh do else ager slice hour se bsr jaye tu slice ko
// bara kro left mid k bad rakho

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int minV = 1;
        int mid = 0;
        int maxV = INT_MIN;
        for (int pil : piles)
            maxV = max(pil, maxV);

        while (minV <= maxV) {
            mid = minV + (maxV - minV) / 2;

            if (h == helperCheck(piles, mid)) {
                return mid;
            }

            else if (h >= helperCheck(piles, mid)) {
                maxV = mid - 1;
            } else {
                minV = mid + 1;
            }

        } // while ---->|||||||||||||||||||||||||||||||| ------->

        return minV;
    }

    long long  helperCheck(vector<int>& piles, int h) {
        long long  num = 0;
        for (int pil : piles)
            num = num + ceil((double)pil / (double)h);

        return num;
    }
};
