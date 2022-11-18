vector<pll> f(ll x){
  vector<pll> factors;
  for(ll i = 2; i * i <= x; i++)
    if(x % i == 0){
      ll a = 0;
      for(; x % i == 0; x /= i, a++);
      factors.pb(make_pair(i, a));
    }
  if(x > 1) factors.pb(make_pair(x, 1));
  return factors;
}


