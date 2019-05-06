#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

//Definimos la función
inline long double f(long double x){return 0.5 + 0.5*exp( (-x)/(2.0*M_PI) )*sin(x) - 0.75;}

/*
p0: aproximación inicial
p1: aproximación inicial
TOL: tolerancia
Nmax: número máximo de iteraciones
*/
void secant(long double p0,long double p1,long double TOL,int Nmax){

	long double p;
	for(int i=0; i < Nmax; i++){
		p = p1 - f(p1)*(p1 - p0 )/( f(p1) - f(p0));		
		cout << i << setprecision(15) << "\t" << p0 << "\t" << p1 << "\t" << p << "\t"<< abs(p1 - p)<< endl;		
		if(abs(p - p1) < TOL)	break;
		
		p0 = p1;
		p1 = p;		
		
	}

} 
	
int main(){

	//Invocamos el método con los parámetros dados en el problema	
	secant(0.65625, 0.65625 + 0.1 , pow(10, -12), 40);
	cout << f(0.0) << endl;
	cout << f(2.1) << endl;
	return 0;
}
