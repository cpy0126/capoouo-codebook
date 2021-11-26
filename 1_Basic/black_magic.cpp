#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp> //rb_tree
using namespace __gnu_pbds;
struct myhash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    ll operator()(ll x) const { return hash_f(x)^RANDOM; }
};
typedef gp_hash_table<ll, int, myhash> hashtable;
typedef __gnu_pbds::priority_queue<int> heap;
int main() {
  heap h1, h2;
  h1.push(1), h1.push(3);
  h2.push(2), h2.push(4);
  h1.join(h2);
  cout << h1.size() << h2.size() << h1.top() << endl; //404
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> st;
  tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update> mp;
  for (int x : {0, 2, 3, 4}) st.insert(x);
  cout << *st.find_by_order(2) << st.order_of_key(1) << endl; //31
}
//__int128_t,__float128_t
