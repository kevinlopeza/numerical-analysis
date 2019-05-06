#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// Función para IPF
inline double g(double x){ return (-1.0/0.75)*log( exp(-0.2*x) - 1.0/4 );  }

/*
Iteración de punto fijo
p0: aproximación inicial
Nmax: número máximo de iteraciones
T: tolerancia
*/

void fixedPoint(double p0, int Nmax, double T){
	
	double p;	

	for(int i=0; i< Nmax; i++){
		p = g(p0);		
		cout << setprecision(10) <<  i << "\t" << p0 << "\t" << p << "\t" <<abs(p-p0) <<endl;
		
		if(abs(p-p0) < T) {
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}
		
		p0 = p;
	}
	
}

int main(){

	fixedPoint(1, 100, pow(10, -9));		
	cout << g(0.6023554647) << endl;
	return 0;
}
