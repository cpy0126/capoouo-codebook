const double eps = 1e-9;
double F(double x){

}
double Simpson(double ,l,double r){
	return (r-l)*(F(r)+F(l)+4.0*F(r+l)*0.5)/6.0;
}
double simpson(double l,double r,double cur){
	double mid = (l+r)*0.5;
	double L = Simpson(l,mid), R = Simpson(mid,r);
	if(fabs(cur-L-R)<=eps)
		return L+R;
	else
		return simpson(l,mid,L)+simpson(mid,r,R);
}
double simpson_ada(double l,double r,double cur,double e){
	double mid = (l+r)*0.5;
	double L = Simpson(l,mid), R = Simpson(mid,r);
	if(fabs(cur-L-R)<=e)
		return L+R;
	else
		return simpson(l,mid,L,e*0.5)+simpson(mid,r,R,e*0.5);
}