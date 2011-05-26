template<typename T>
T gcd(T a, T b)
{
  if(a > b) swap(a, b);
  return a == 0 ? b : gcd(b % a, a);
}

template<typename T>
T lcm(T a, T b)
{
  return a / gcd(a, b) * b;
}
