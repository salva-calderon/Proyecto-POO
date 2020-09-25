//	Peliculas.h

#include <iostream>
using namespace std;

class Peliculas:public Videos {
	public:
		Peliculas();
		Peliculas(string nombre, string genero, int calificacion, int duracion, int ID);
		
		void muestra();
};

Peliculas::Peliculas(){
	
}

Peliculas::Peliculas(string nombre, string genero, int calificacion, int duracion, int ID):Videos(nombre, genero, calificacion, duracion, ID){
	
}

void Peliculas::muestra(){
	string guion = "_", rempl = " ";
	int pos = nombre.find(guion);
	while(pos != -1){
		nombre.replace(pos, guion.size(), rempl);
		pos = nombre.find(guion, pos+rempl.size());
	}
	cout << "--------------------------------" << endl;
	cout << "- Pelicula: " << nombre << endl;
	cout << "- Genero: " << genero << endl;
	cout << "- Calificacion: " << calificacion << " estrellas" << endl;
	cout << "- Duracion: " << duracion << " minutos" << endl;
	cout << "- ID: " << ID << endl;
}
