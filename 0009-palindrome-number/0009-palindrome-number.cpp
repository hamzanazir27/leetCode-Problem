class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;

        return x == reverse(x);
    }

private:
    long long reverse(int remainingleft, long long right = 0)
    {
        if (remainingleft == 0) 
            return right;

        int ri = remainingleft % 10;
        int left = remainingleft / 10;

        return reverse(left, right * 10 + ri);
    }
};




// approch without recursion

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         //check negtive number 
//     if(0>x || x%10==0 &&x !=0 )
//     return false;
//    //171

//     int reversedHalf=0;  
//     while(reversedHalf<x)
//     {
//         int lastdigit=  x%10;    //171       171/10    
//         //adding to reverse
//         reversedHalf=reversedHalf*10+lastdigit;
//         x=x/10;     

//     }



//     return x==reversedHalf  || x ==reversedHalf/10;

//     }
// };