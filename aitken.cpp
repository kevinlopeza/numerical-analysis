#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// Función para IPF
inline long double g(long double x){ return (-1.0/0.75)*log( exp(-0.2*x) - 1.0/4);  }

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

	for(int i = 0; i <= Nmax; i++){
		p1 = g(p0);	
		p2 = g(p1);
		
		p1_hat = p_hat(p0, p1, p2);		

		if(i == 0) cout << i <<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << endl;
		else cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << "\t" << abs(p1_hat - p0_hat) <<endl;

		
		if(abs(p0_hat - p1_hat) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;			
			break;						
		} 

		p0 = p1;
		p0_hat = p1_hat; 
	
	}		
}


int main(){

	aitken(1, 100, pow(10, -9));		
	
	return 0;
}
