//コンビネーション
ll combination(ll n, ll r){
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  FOR(i, 1, r){
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}