inline char readchar() {
  static const size_t bufsize = 65536;
  static char buf[bufsize];
  static char *p = buf, *end = buf;
  if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
  return *p++;
}
inline int readint(){
	int f=1,x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(c<'0'||c>'9');
	do{x=x*10+c-'0';c=getchar();}while(c>='0'&&c<='9');
	return f*x;
}