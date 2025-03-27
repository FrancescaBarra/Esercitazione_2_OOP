#include <iostream>
#include <iomanip>

//Classe template per i numeri complessi
template <typename T>
class complex_number{
	
private:
	T reale;
	T immaginaria;
public:

	explicit complex_number(T a): reale(a), immaginaria(0.0) {}
	
	//Costruttore di default
	complex_number():
		reale(0), immaginaria(0){}
		
	//Costruttore user-defined
	complex_number(T r, T i):
		reale(r), immaginaria(i){}
		
	//Metodi per ottenere parte reale e parte immaginaria
	T get_reale() const{
		return reale;
	}
	T get_immaginaria() const{
		return immaginaria;
	}
		
	//Metodo per ottenere il coniugato
	complex_number coniugato() const{
		return complex_number(reale, -immaginaria);
	}
		
	//Overload dell'operatore +=
	complex_number& operator+=(const complex_number& other) {
		reale += other.reale;
		immaginaria += other.immaginaria;
		return *this;
	}
		
	//Overload dell'operatore +
	complex_number operator + (const complex_number& other){
		return complex_number(reale + other.reale, immaginaria + other.immaginaria);
	}
	
	//Overload dell'operatore +: complesso + altra classe
	complex_number operator+ (const T& n) const{
		return complex_number(reale + n, immaginaria);
	}
		
	//Overload dell'operatore *=
	complex_number& operator*= (const complex_number& other) {
		T e = reale;
		T f = immaginaria;
		T g = other.reale;
		T h = other.immaginaria;
		reale = e * f - g * h;
		immaginaria = e * h + f * g;
		return *this;
	}
		
	//Overload dell'operatore *
	complex_number operator* (const complex_number& other) const{
		T new_reale = reale * other.reale - immaginaria * other.immaginaria;
		T new_immaginaria = reale * other.immaginaria + immaginaria * other.reale;
		return complex_number(new_reale, new_immaginaria);
	}
	
	//Overload dell'operatore *: complesso * altra classe
	complex_number operator* (const T& n) const{
		return complex_number(reale * n, immaginaria * n);
	}	
};

//Overload operatore +: altro + complesso
template <typename T>
complex_number<T> operator+ (const T n, const complex_number<T>& z){
	return complex_number<T>(z.get_reale() + n, z.get_immaginaria());
}

//Overload operatore *: altro * complesso
template <typename T>
complex_number<T> operator* (const T n, const complex_number<T>& z){
	return complex_number<T>(z.get_reale() * n, z.get_immaginaria() * n);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const complex_number<T>& z){
		out << z.get_reale();
		if (z.get_immaginaria() >= 0){
			out << " + " << z.get_immaginaria() << "i";
		}
		else{
			out << " " << z.get_immaginaria() << "i";
		}
	return out;
}

int main()
{
	complex_number <double> z1(3.7, 5.2);
	complex_number <double> z2(0.0, - 2.2);
	double n = 2.0;
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "z1 = " << z1 << std::endl;
	std::cout << "z2 = " << z2 << std::endl;
	std::cout << "Parte reale di z1 = " << z1.get_reale() << std::endl;
	std::cout << "Parte immaginaria di z1 = " << z1.get_immaginaria() << std::endl;
	std::cout << "Parte reale di z2 = " << z2.get_reale() << std::endl;
	std::cout << "Parte immaginaria di z2 = " << z2.get_immaginaria() << std::endl;
	std::cout << "Coniugato di z1 = " << z1.coniugato() << std::endl;
	std::cout << "Coniugato di z2 = " << z2.coniugato() << std::endl;
	
	//Verifica del funzionamento degli overload delle operazioni
	complex_number <double> sommaCC = z1 + z2;
	std::cout << "Somma tra complessi: z1 + z2 = " << sommaCC << std::endl;
	
	complex_number <double> sommaCR = z1 + n;
	std::cout << "Somma tra complesso e altro: z1 + n = " << sommaCR << std::endl;
	
	complex_number <double> sommaRC = n + z2;
	std::cout << "Somma tra altro e complesso: n + z2 = " << sommaRC << std::endl;

	complex_number <double> prodottoCC = z1 * z2;
	std::cout << "Prodotto tra complessi: z1 * z2 = " << prodottoCC << std::endl;
	
	complex_number <double> prodottoCR = z1 * n;
	std::cout << "Prodotto tra complesso e altro: z1 * n = " << prodottoCR << std::endl;
	
	complex_number <double> prodottoRC = n * z2;
	std::cout << "Prodotto tra altro e complesso: n * z2 = " << prodottoRC << std::endl;
	
	complex_number <double> sommacompatta = z1 += z2;
	std::cout << "Operatore +=: " << sommacompatta << std::endl;
	
	complex_number <double> prodottocompatto = z1 *= z2;
	std::cout << "Operatore *=: " << prodottocompatto << std::endl;
	
	return 0;
}