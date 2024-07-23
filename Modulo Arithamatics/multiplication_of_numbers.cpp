#include <bits/stdc++.h>
using namespace std;
#define int long long

const int p = 1e9 + 7;

int mod_multiply(int a, int b, int p)
{
    a %= p;
    b %= p;

    return (a * b) % p;
}

int mod_power(int a, int power, int p)
{

    int ans = 1;
    while (power)
    {
        if (power % 2)
        {
            // ans=(ans*a)%p
            int ans = mod_multiply(ans, a, p);
            power--;
        }
        else
        {
            // a=(a*a)%p
            power = mod_multiply(a, a, p);
            power = power / 2;
        }
    }
    return ans;
}

int mod_divide(int a, int b, int p)
{
    // int inverse = pow(b, p - 2);
    int ans = mod_multiply(a, mod_power(b, p - 2, p), p);
}

int fact(int a, int p)
{
    int ans = 1;
    for (int i = 1; i <= a; i++)
    {
        ans = mod_multiply(ans, i, p);
    }
    return ans;
}

int factorial[1000001];
int precompute()
{
    factorial[0] = 1;
    for (int i = 1; i <= 1000001; i++)
    {
        factorial[i] = mod_multiply(factorial[i - 1], factorial[i], p);
    }
}

int ncr_optimised(int n, int r, int p)
{
    int num = factorial[n];
    int den = factorial[n - r];
    int den2 = factorial[r];

    int ans = mod_divide(num, den, p);
    int final = mod_divide(num, den2, p);
}

int ncr_brute(int n, int r, int p)
{
    int num = fact(n, p);
    int den = fact(r, p);
    int den2 = fact(n - r, p);

    int ans = mod_divide(num, den, p);
    int final = mod_divide(num, den2, p);

    return ans;
}
// brute time complexcity=O(n)+O(long(den)+o(log(den2)+O(n-r)))
signed main()
{

    precompute();
    int a, b, c;
    cin >> a >> b >> c;

    int ans = mod_multiply(a, b, p);
    int final_ans = mod_multiply(ans, c, p);
    cout << final_ans << "endl";
}