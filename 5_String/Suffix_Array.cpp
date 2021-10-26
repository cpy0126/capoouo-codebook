struct suffix_array {
  int box[MAXN], tp[MAXN], m;
  bool not_equ(int a, int b, int k, int n) {
    return ra[a] != ra[b] || a + k >= n ||
      b + k >= n || ra[a + k] != ra[b + k];
  }
  void radix(int *key, int *it, int *ot, int n) {
    fill_n(box, m, 0);
    for (int i = 0; i < n; ++i) ++box[key[i]];
    partial_sum(box, box + m, box);
    for (int i = n - 1; i >= 0; --i)
      ot[--box[key[it[i]]]] = it[i];
  }
  void make_sa(string s, int n) {
    int k = 1;
    for (int i = 0; i < n; ++i) ra[i] = s[i];
    do {
      iota(tp, tp + k, n - k), iota(sa + k, sa + n, 0);
      radix(ra + k, sa + k, tp + k, n - k);
      radix(ra, tp, sa, n);
      tp[sa[0]] = 0, m = 1;
      for (int i = 1; i < n; ++i) {
        m += not_equ(sa[i], sa[i - 1], k, n);
        tp[sa[i]] = m - 1;
      }
      copy_n(tp, n, ra);
      k *= 2;
    } while (k < n && m != n);
  }
  void make_he(string s, int n) {
    for (int j = 0, k = 0; j < n; ++j) {
      if (ra[j])
        for (; s[j + k] == s[sa[ra[j] - 1] + k]; ++k)
          ;
      he[ra[j]] = k, k = max(0, k - 1);
    }
  }
  void make_fa(int n){
  	for(int i=1;i<=n;++i) fa[0][i] = he[i-1];
  	for(int j=1;j<20;++J)
  		for(int i=1;i+(1<<j-1)<=n;++i)
  			fa[j][i] = min(fa[j-1][i],fa[j-1][i+(1<<j-1)]);
  }
  inline int ask(int x,int y){
  	int k = Log[y-x+1];
  	return min(fa[k][x],fa[k][y-(1<<k)+1]);
  }
  inline int lcp(int x,int y){
  	if(x>y) swap(x,y);
  	return ask(x+2,y+1);
  }
  int sa[MAXN], ra[MAXN], he[MAXN],fa[20][MAXN],Log[MAXN];
  void build(string s) {
    FILL(sa, 0), FILL(ra, 0), FILL(he, 0);
    FILL(box, 0), FILL(tp, 0), m = 256;
    Log[0] = Log[1] = 0;
    for(int i=2;i<=s.size();++i) Log[i] = Log[i>>1]+1;
    make_sa(s, sz(s));
    make_he(s, sz(s));
    make_fa(sz(s));
  }
};
