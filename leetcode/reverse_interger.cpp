class Solution {
public:
    int reverse(long long num){
        long long reverse = 0;
        long long abs_num=std::abs(num);
        while (abs_num > 0) {
        reverse = reverse * 10 + abs_num % 10;
        abs_num /= 10;
        }
        if(-reverse < 1 << 31) return 0;
        if(num < 0) reverse *= -1;
        return reverse;
    }
};