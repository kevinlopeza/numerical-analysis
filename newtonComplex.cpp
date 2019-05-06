#include <iostream> // std::cout, std::endl
#include <iomanip> //std::setprecision
#include <complex>

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;
using std::complex;

//Definimos la función
complex<double> f(complex<double> z) { return pow(z, 3.0) - 2.0*z + 2.0; }

//Derivada de la función
complex<double> df(complex<double> z) { return 3.0*pow(z, 2.0) - 2.0; }

/*
p0: Aproximación inicial
TOL: tolerancia
Nmax: número máximo de iteraciones
*/
void newton(complex<double> p0,double TOL,int Nmax){

	complex<double> p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(11) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	

	complex<double> p0(1.0, 1.0);
			
	newton(p0, pow(10, -10), 40);

	complex<double> root(0.884646177119316,-0.589742805022206);
	cout << f(root) << endl;
	return 0;
}

