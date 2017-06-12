#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<vll> vvll;

// act - action 1 = paste and 0 = copy ; 0 is always followed by 1;
// rem is remaining
// hav is how many already there
// cpy is no of emoticons in clipboard
ll fun(ll rem, ll hav, ll cpy, bool act, ll t){
  if(rem == 0)
    return t+1;
  if(act){
    // copy is always followed by paste
    if(rem >= cpy){
      rem -= cpy;
      hav += cpy;
      act = false;
      cout << endl << "paste is done : " << "rem : " << rem
	   << " hav : " << hav << " act: " << act << " cpy: " << cpy << " t: " << t; 
      t = fun(rem, hav, cpy, act, ++t);
      return t+1;
    }
    else{
      cout << endl << "rem: " << rem << " < " << "cpy: " << cpy;
      return -1;
    }
  } else {
    // paste can be followed by copy or paste
    // for copy
    ll rC;
    ll rP;
    if(rem >= hav){
      cpy = hav;
      act = true;
      cout << endl << "copy is done : " << "rem : " << rem
	   << " hav : " << hav << " act: " << act << " cpy: " << cpy
 	   << " t: " << t;
      rC = fun(rem, hav, cpy, act, ++t);
      //rC = t;
    }
    else{
      cout << endl << "rem: " << rem << " < " << "hav: " << hav << endl
	   << "######" << "\t rC = -1";
      rC = -1;
    }
    if(rem >= cpy){
      rem -= cpy;
      hav += cpy;
      act = false;
      cout << endl << "paste is done : " << "rem : " << rem
	   << " hav : " << hav << " act: " << act << " cpy: " << cpy
	   << " t: " << t;
      rP = fun(rem, hav, cpy, act, ++t);
      //rP = t+1;
    }
    else{
      cout << endl << "rem: " << rem << " < " << "cpy: " << cpy << endl
	   << "######" << "\t rP = -1";
      rP = -1;
    }
    if(rP == -1 && rC == -1){
      return -1;
    }
    if(rP != -1 && rC != -1){
      return (rP < rC ? rP : rC);
    }
    if(rP == -1)
      return rC;
    if(rC == -1)
      return rP;
  }
}

int main(){
  ll n;
  cin >> n;
  ll t ;
  t = fun(n-1, 1, 1, true, 1);
  cout << endl << endl << "Soln : "<< t << endl;
}
