#include <iostream>

using namespace std;

// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

int dividendide(int dividend, int divisor) {

    if(divisor == -2147483648){
        if(dividend == -2147483648)
            return 1;
        return 0;
    }
    bool flag = true, maxDiv = false;
    if(dividend == -2147483648){
        dividend = dividend >> 1;
        maxDiv = true;
    }

    if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
        flag = false;
    if(dividend < 0)
        dividend = 0 - dividend;
    if(divisor < 0)
        divisor = 0 - divisor;
    if(dividend < divisor && !maxDiv)
        return 0;

    int result = 0, midVal = 0, pos = 1, i = 31, andVal;
    while(i>-1) {
        pos = 1;
        pos = pos << i--;
        andVal = pos & dividend;
        if(andVal > 0)
            andVal = 1;
        midVal = (midVal << 1) + andVal;

        if(midVal >= divisor){
            midVal -= divisor;
            result = (result << 1) + 1;
        }else
            result = (result << 1) + 0;
    }
    // negetive
    if(!flag){
        result = 0 - result;
        if(maxDiv){
            result = result << 1;
            if(midVal > (divisor>>1) )
                result--;
        }
    }else{
        if(maxDiv){
            result = result << 1;
            if(result == -2147483648)
                result = 2147483647;
            else{
                if(midVal > (divisor>>1) )
                    result++;
            }
        }
    }
    if(maxDiv && result == 0)
        result = 1;
    return result;
}


int main() {
    int a = INT_MAX;
    int pos = 1;
    pos = pos << 29;
    int res = (pos & a);
    cout << a << "||" << res <<endl;

    cout << dividendide(-2147483648, 122481295) << endl;

    int dividend = -2147483648;
    cout << (0-dividend)<<endl;
//    cout << (dividend-1);
}
