#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;	using std::endl;
using std::setprecision;

inline double f(float x){return 0.5 + 0.5*exp( (-x)/(2.0*M_PI) )*sin(x) - 0.75;}

void bisection(float a,float b,float T){

	unsigned int n = ceil( log2( (b - a)/T ) );
	
	for(size_t i = 0; i < n ; i++){
		
		double p = (a + b)/2.0;

		cout << setprecision(10) << i << "\t" << a << "\t" << b << "\t" << p << "\t" << f(p) << "\t" << (b - a)/2.0 <<endl;

		if (f(a)*f(p) < 0) b = p;
		else a = p;    
	}
}

int main(){
	bisection(0, 2.1, 0.2);	
	return 0;
}
