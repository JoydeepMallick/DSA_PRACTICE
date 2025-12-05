class Solution {
public:
    int divide(int dividend, int divisor) {
        int ispos = true;
        if((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0)) ispos = false;
        long N = abs(1l*dividend), d = abs(1l*divisor);
        long quotient = 0; // to handle boundaries of int

        while(N >= d){
            int cnt = 0;
            while( N >= (d << (cnt+1)) ){
                cnt++;
            }

            quotient += (1ll << cnt);
            N -= (d << cnt);
        }
        if(ispos && quotient >= (1ll << 31) - 1) return ((1ll << 31) - 1);
        if(ispos == false && quotient >= (1ll << 31)) return (-1*(1ll << 31));//we are dealing with absolute values so conversions are needed

        return ispos ? quotient : -quotient;
    }
};