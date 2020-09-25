//	Videos.h

#include <iostream>
using namespace std;

class Videos {
	public:
		Videos();
		Videos(string nombre, string genero, int calificacion, int duracion, int ID);
		
		void setNombre(string nombre) {this->nombre = nombre;}
		void setGenero(string genero) {this->genero = genero;}
		void setCalificacion(int calificacion) {this->calificacion = calificacion;}
		void setDuracion(int duracion) {this->duracion = duracion;}
		void setID(int ID) {this->ID = ID;}
		
		string getNombre() {return nombre;}
		string getGenero() {return genero;}
		int getCalificacion() {return calificacion;}
		int getDuracion() {return duracion;}
		int getID() {return ID;}	
		
		virtual void muestra() = 0;
			
	protected:
		string nombre;
		string genero;
		int calificacion;
		int duracion;
		int ID;
};

Videos::Videos(){
	nombre = "-";
	genero = "-";
	calificacion = 0;
	duracion = 0;
	ID = 0;
}

Videos::Videos(string nombre, string genero, int calificacion, int duracion, int ID){
	this->nombre = nombre;
	this->genero = genero;
	this->calificacion = calificacion;
	this->duracion = duracion;
	this->ID = ID;
}
