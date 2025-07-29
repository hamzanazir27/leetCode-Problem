class Solution {
public:
    bool isPalindrome(int x) {
        //check negtive number 
    if(0>x || x%10==0 &&x !=0 )
    return false;
   //171

    int reversedHalf=0;  
    while(reversedHalf<x)
    {
        int lastdigit=  x%10;    //171       171/10    
        //adding to reverse
        reversedHalf=reversedHalf*10+lastdigit;
        x=x/10;     

    }



    return x==reversedHalf  || x ==reversedHalf/10;

    }
};