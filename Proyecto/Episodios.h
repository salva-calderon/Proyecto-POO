//	Episodios.h

#include <iostream>
#include <string>
using namespace std;
#include "Videos.h"

class Episodios:public Videos {
	public:
		Episodios();
		Episodios(string nombre, string genero, int calificacion, int duracion, int ID, string nombreT, int episodio, int temporada);
		
		void setNombreT(string nombreT) {this->nombreT = nombreT;}
		void setEpisodio(int episodio) {this->episodio = episodio;}
		void setTemporada(int temporada) {this->temporada = temporada;}
		
		string getNombreT() {return nombreT;}
		int getEpisodio() {return episodio;}
		int getTemporada() {return temporada;}
		
		void muestra();
		
	private:
		string nombreT;
		int episodio;
		int temporada;
};

Episodios::Episodios(){
	nombreT = "-";
	episodio = 0;
	temporada = 0;
}

Episodios::Episodios(string nombre, string genero, int calificacion, int duracion, int ID, string nombreT, int episodio, int temporada):Videos(nombre, genero, calificacion, duracion, ID){
	this->nombreT = nombreT;
	this->episodio = episodio;
	this->temporada = temporada;
}

void Episodios::muestra(){
	string guion = "_", rempl = " ";
	int pos = nombre.find(guion);
	while(pos != -1){
		nombre.replace(pos, guion.size(), rempl);
		pos = nombre.find(guion, pos+rempl.size());
	}
	int pos_1 = nombreT.find(guion);
	while(pos_1 != -1){
		nombreT.replace(pos_1, guion.size(), rempl);
		pos_1 = nombreT.find(guion, pos_1+rempl.size());
	}
	int pos_2 = genero.find(guion);
	while(pos_2 != -1){
		genero.replace(pos_2, guion.size(), rempl);
		pos_2 = genero.find(guion, pos_2+rempl.size());
	}
	cout << "- Temporada: " << nombreT << endl;
	cout << "- Episodio: " << nombre << endl;
	cout << "- Genero: " << genero << endl;
	cout << "- Calificacion: " << calificacion << " estrellas" << endl;
	cout << "- Duracion: " << duracion << " minutos" << endl;
	cout << "- ID: " << ID << endl;
	cout << "- No. Temporada: " << temporada << endl;
	cout << "- No. Episodio: " << episodio << endl;
}
