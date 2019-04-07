#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

//Definimos la función
inline double f(double x) { return exp(x) - x - 2; }

//Derivada de la función
inline double df(double x) { return exp(x) - 1; }

/*
p0: Aproximación inicial
TOL: tolerancia
Nmax: número máximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){

	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el método según los datos del problema
	newton(1.0, pow(10, -15), 40);
	return 0;
}
