#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

double Beta = -1.16583607818894;
double Gamma = 0.0542253936905836;
double Delta = -1.25100322759761*pow(10, -4); 
double R = 0.08205;
double T = 273.15;
double P = 200;

//Definimos la función
inline double f(double V) { return (R*T)/V + Beta/pow(V, 2) + Gamma/pow(V, 3) + Delta/pow(V, 4) - P;}

//Derivada de la función
inline double df(double V) { return  (-R*T)/pow(V, 2) - (2.0*Beta)/pow(V, 3) - (3.0*Gamma)/pow(V, 4) - (4.0*Delta)/pow(V, 5) ;}

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
	newton((R*T)/P, pow(10, -15), 40);
	return 0;
}
