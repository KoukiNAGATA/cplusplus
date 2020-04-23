using ll = long long;
ll GCD(ll x, ll y) {//最大公約数：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x%y) : y;
}

ll LCM(ll x, ll y) {//最小公倍数
    return x * y / GCD(x, y);
}