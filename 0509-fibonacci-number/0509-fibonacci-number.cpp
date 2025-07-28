class Solution {
public:
    int fib(int n) {
        // return  fibN(n);
        
        //base case 
        if(n==1)
          return 1;
         if(n==0)
          return 0;

        return fib(n-1)+fib(n-2);
    }


// private:
//     int fibN(int a)
//     {
//         //base case 
//         if(a==1)
//           return 1;
//          if(a==0)
//           return 0;

//         return fibN(a-1)+fibN(a-2);
//     }
};