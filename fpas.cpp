#include <iostream> // std::cout, std::endl
#include <cmath> //std::ceil, log, std::abs
#include <algorithm> // std::max
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::ceil;	using std::abs;
using std::max;		using std::setprecision;

// Función para IPF
inline double g(double x){ return 1 + pow(sin(x), 2);  }

/*
Iteración de punto fijo
a: extremo izquierdo del intervalo
b: extremo derecho del intervalo
p0: aproximación inicial
k: constante asintótica del error
T: tolerancia
*/
void fixedPoint(double a, double b, double p0, double k, double T){
	
	// A diferencia del código en Python, aquí hay que aplicar cambio de base para el logaritmo
	int n = ceil( log( T/max(b -p0, p0-a) )/log(k) );

	double p;	

	for(int i=0; i<n; i++){
		p = g(p0);		
		cout << i << "\t" << p0 << "\t" << p << "\t" <<abs(p-p0) <<endl;
		p0 = p;
	}
	
}

// Inline para calcular cada término de la sucesión de Aitken
inline double p_hat(double p0, double p1, double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximación inicial
Nmax: número máximo de iteraciones
T: tolerancia
*/
void aitken(double p0, int Nmax, double T){	

	double p0_hat; //último valor en la sucesión de Aitken
	double p1_hat; //valor actual en la sucesión de Aitken
		
	double p1, p2; //valores en la iteración de punto fijo 

	for(int i = 1; i <= Nmax; i++){
		p1 = g(p0);	
		p2 = g(p1);
		
		p1_hat = p_hat(p0, p1, p2);		

		if(i == 1) cout << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << endl;
		else cout << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << "\t" << abs(p1_hat - p0_hat) <<endl;

		
		if(i > 1 and abs(p0_hat - p1_hat) < T){
			cout << "Objetivo logrado con i =" << i << endl;			
			break;						
		} 

		p0 = p1;
		p0_hat = p1_hat; 
	
	}		
}


int main(){

	//fixedPoint(1, 2, 1.5, 0.60740985, pow(10, -9));

	//aitken(1.5, 100, pow(10, -9));		
	
	return 0;
}
