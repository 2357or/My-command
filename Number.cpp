#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

bool is_prime(const ll param){
    if(param < 2) return false;
    if(param % 2 == 0 || param % 3 == 0) return false;
    for(ll i = 5; i*i <= param; i += 6){
        if((param % i == 0) || (param % (i+2) == 0)) return false;
    }
    return true;
}

vector<pair<ll, ll>> prime_factorization(ll param){
    vector<pair<ll, ll>> res;
    ll ex = 0;
    while (param % 2 == 0) {
        ex++;
        param /= 2;
    }
    if(ex != 0) res.push_back({2, ex});
    for(ll i = 3; i*i <= param; i += 2 ){
        ex = 0;
        while(param % i == 0){
            ex++;
            param /= i;
        }
        if(ex != 0) res.push_back({i, ex});
    }
    if(param != 1) res.push_back({param, 1});
    return res;
}


ll n;
int main() {
    cin >> n;
    cout << "[Result]" << endl;
    if(is_prime(n)){
        cout << n << " is prime number" << endl;
    }
    else{
        cout << n << " is composite number" << endl;
        const auto &res = prime_factorization(n);
        for (auto p : res)
            for (int i = 0; i < p.second; ++i) cout << p.first << " ";
        cout << endl;
    }
    return 0;
}

