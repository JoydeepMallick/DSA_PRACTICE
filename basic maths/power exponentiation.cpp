class Solution {
public:
    double myPow(double x, int n) {
        int N = abs(n);
        double num = x;
        if(n < 0){
            num = 1/x;
        }
        double ans = 1;

        while(N > 0){
            if(N&1){
                ans *= num;
                N -= 1;
            }else{
                num *= num;
                N /= 2;
            }
        }
        return ans;
    }
};