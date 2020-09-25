// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

#include "Series.h"
#include "Episodios.h"
#include "Peliculas.h"

void crearcuenta(){ 
  string sUsuario, sPassword, _sPassword;

  ofstream archivo;
  archivo.open("cuentas.txt", ios::app);

  cout << "\n< Creacion de cuenta >" << endl;
  cout << endl;
  cout << "Usuario: ";
  cin >> sUsuario;
  cout << "Password: ";
  cin >> sPassword;
  cout << "Confirmar password: ";
  cin >> _sPassword;

  while(sPassword != _sPassword){
    cout << "\nPassword no concuerda con la original" << endl;
    cout << "Ingrese nuevamente la password: " << flush;
    cin >> _sPassword;
  }

  archivo << "\n" << sUsuario << " " << sPassword;

  archivo.close();
}

int verificarcuenta(){
	int contador;
	string sUsuario, sPassword, _sUsuario, _sPassword;
	ifstream archivo;
	archivo.open("cuentas.txt");
	
	cout << "\nUsuario: ";
	cin >> sUsuario;
	cout << "Password: ";
	cin >> sPassword;

	while(archivo >> _sUsuario >> _sPassword){
		if(sUsuario == _sUsuario && sPassword == _sPassword){
      		contador++;
    	}
  	}
  	return contador;
}

int menuInicial(){
	int _iOpcion;
	cout << "1. Iniciar Sesion" << endl;
	cout << "2. Crear cuenta" << endl;
	cout << "Introduzca su opcion: ";
	cin >> _iOpcion;
	while (_iOpcion != 1 && _iOpcion != 2){
    cout << "\nSe ha ingresado una opcion inexistente." << endl;
    cout << "1. Iniciar Sesion" << endl;
	cout << "2. Crear cuenta" << endl;
	cout << "Introduzca su opcion: ";
	cin >> _iOpcion;
	}
	
	return _iOpcion;
}

void cargaDatosSeries(Series *listaSeries[], int &cantSeries) {
    
    string nombreS;
    int ID;
    
    ifstream archivo;
    archivo.open("datosSeries.txt");
    cantSeries = 0;
    
    while (archivo >> ID >> nombreS) {
        listaSeries[cantSeries++] = new Series(ID, nombreS);
    }
    
    archivo.close();
}

void muestraSeries(Series *listaSeries[], int cantSeries) {
	cout << "\n\t < Catalogo de Series >\n" << endl;
    for (int i = 0; i < cantSeries; i++) {
    	cout << "--------------------------------" << endl;
        listaSeries[i]->muestra();
    }
}

void cargaVideos(Videos *listaVideos[], int &cantVideos) {
    
    string nombre, genero, nombreT;
    int ID, duracion, calificacion, episodio, temporada;
    char tipo;
    
    ifstream archivo;
    archivo.open("datosVideos.txt");
    
    while (archivo >> tipo) {
    	if(tipo == 'p'){
    		archivo >> ID >> nombre >> genero >> duracion >> calificacion;
    		listaVideos[cantVideos++] = new Peliculas(nombre, genero, calificacion, duracion, ID);
		}
		else{
			archivo >> ID >> nombre >> genero >> duracion >> calificacion >> nombreT >> episodio >> temporada;
			listaVideos[cantVideos++] = new Episodios(nombre, genero, calificacion, duracion, ID, nombreT, episodio, temporada);
		}
    }
    
    archivo.close();
}

void muestraPeliculas(Videos *listaVideos[], int cantVideos) {
	cout << "\n\t\t\t < Catalogo de Peliculas >\n" << endl;
    for (int i = 0; i < cantVideos; i++) {
    	if(typeid(*listaVideos[i]) == typeid(Peliculas)){
        	listaVideos[i]->muestra();
		}
    }
}

void muestraVideosCalificacion(Videos *listaVideos[], int cantVideos){
	int iOpcion;
	cout << "\nIngrese calificacion de 1 a 5" << endl;
	cout << "Calificacion: " << flush;
	cin >> iOpcion;
	
	cout << "\n\t< Peliculas con " << iOpcion << " de calificacion >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Peliculas)){
			if(listaVideos[i]->getCalificacion() == iOpcion){
				listaVideos[i]->muestra();
			}
		}	
	}
	
	cout << "\n\t< Episodios con " << iOpcion << " de calificacion >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Episodios)){
			if(listaVideos[i]->getCalificacion() == iOpcion){
				cout << "--------------------------------" << endl;
				listaVideos[i]->muestra();
			}
		}	
	}	
}

void muestraVideosGenero(Videos *listaVideos[], int cantVideos){
	int iOpcion;
	string sGenero;
	cout << "\nIngrese el numero de uno de los siguientes generos:\n" << endl;
	cout << "1. Misterio" << endl;
	cout << "2. Ciencia ficcion" << endl;
	cout << "3. Accion" << endl;
	cout << "4. Musical" << endl;
	cout << "5. Animacion" << endl;
	cout << "6. Comedia" << endl;
	cout << "Numero: " << flush;
	cin >> iOpcion;
	
	if(iOpcion == 1)
		sGenero = "Misterio";
	else if(iOpcion == 2)
		sGenero = "Ciencia_ficcion";
	else if(iOpcion == 3)
		sGenero = "Accion";
	else if(iOpcion == 4)
		sGenero = "Musical";
	else if(iOpcion == 5)
		sGenero = "Animacion";
	else if(iOpcion == 6)
		sGenero = "Comedia";
		
	cout << "\n\t< Peliculas de " << sGenero << " >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Peliculas)){
			if(listaVideos[i]->getGenero() == sGenero){
				listaVideos[i]->muestra();
			}
		}	
	}
	
	cout << "\n\t< Episodios de " << sGenero << " >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Episodios)){
			if(listaVideos[i]->getGenero() == sGenero){
				cout << "--------------------------------" << endl;
				listaVideos[i]->muestra();
			}
		}
	}	
}

void muestraEpisodiosTemporada(Videos *listaVideos[], Series *listaSeries[], int cantVideos, int cantSeries){
	int iOpcion, contador = 1;
	Episodios *listaEpisodios;
	cout << "\n\t< Catalogo de Series >\n" << endl;
	for (int i = 0; i < cantSeries; i++) {
		cout << "--------------------------------" << endl;
    	cout << i+1 << ". " << flush;
        listaSeries[i]->muestra();
    }
    cout << "\nSelecciona una serie" << endl;
    cout << "Opcion: " << flush;
    cin >> iOpcion;
    
    while (iOpcion != 1 && iOpcion != 2 && iOpcion != 3 && iOpcion != 4){
    	cout << "\nSe ha ingresado una opcion inexistente." << endl;
	    cout << "\nSelecciona una serie" << endl;
	    cout << "Opcion: " << flush;
	    cin >> iOpcion;
	}

    cout << endl;
	string guion = "_", rempl = " ";
	cout << "\n\t< Episodios de una serie >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Episodios)){
			listaEpisodios = (Episodios *)listaVideos[i];
			string nombre = listaEpisodios->getNombreT();
			int pos = nombre.find(guion);
			while(pos != -1){
				nombre.replace(pos, guion.size(), rempl);
				pos = nombre.find(guion, pos+rempl.size());
			}
			if(nombre == listaSeries[iOpcion-1]->getNombreS()){
				cout << "--------------------------------" << endl;
				listaEpisodios->muestra();
			}
		}
	}
}

void muestraPeliculasCalificacion(Videos *listaVideos[], int cantVideos){

	int iOpcion;
	cout << "\nIngrese calificacion de 1 a 5" << endl;
	cout << "Calificacion: " << flush;
	cin >> iOpcion;
	
	cout << "\n\t< Peliculas con " << iOpcion << " de calificacion >\n" << endl;
	for(int i=0; i<cantVideos; i++){
		if(typeid(*listaVideos[i]) == typeid(Peliculas)){
			if(listaVideos[i]->getCalificacion() == iOpcion){
				listaVideos[i]->muestra();
			}
		}
	}
}

int menuOpciones(){
	int iOpcion;
	
	cout << "\n\t Menu\n" << endl;
	cout << "1. Cargar archivo de datos" << endl;
	cout << "2. Mostrar la lista de peliculas" << endl;
	cout << "3. Mostrar la lista de series" << endl;
	cout << "4. Mostrar los videos en general con una cierta calificacion" << endl;
	cout << "5. Mostrar los videos en general de un cierto genero" << endl;
	cout << "6. Mostrar los episodios de una determinada serie con sus calificaciones" << endl;
	cout << "7. Mostrar las peliculas con cierta calificacion" << endl;
	cout << "0. Salir" << endl;
	cout << "\nOpcion: " << flush;
	cin >> iOpcion;
  
  return iOpcion; 
}

int regreso(){
	int iOpcion;
	cout << "\nDesea regresar al menu principal" << endl;
	cout << "1. Regresar" << endl;
	cout << "2. Salir" << endl;
	cout << "\nOpcion: " << flush;
	cin >> iOpcion;
		
	while (iOpcion != 1 && iOpcion != 2){
	    cout << "Se ha ingresado una opcion inexistente." << endl;
	    cout << "1. Regresar" << endl;
		cout << "2. Salir" << endl;
		cout << "\nOpcion: " << flush;
		cin >> iOpcion;
	}
	
	if(iOpcion == 2)
		iOpcion = 0;
	
	return iOpcion;
}

int main(){
	int iOpcion, _iOpcion, contador = 0;
	
	cout << "  __^__                                                  __^__ " << endl;
	cout << " ( ___ )------------------------------------------------( ___ ) "<< endl; 
	cout << "  | / |                                                  | / | " << endl;
	cout << "  | / |         Bienvenido a la web de peliculas         | / | " << endl;
	cout << "  |___|                                                  |___| " << endl;
	cout << " (_____)------------------------------------------------(_____) " << endl;
	
	cout << endl;
  	_iOpcion = menuInicial();
	
	do{
		if(_iOpcion == 1)
			contador = verificarcuenta();
		else{
			crearcuenta();
			contador++;
		}
		if(contador == 0){
			cout << "No existe esta cuenta o uno de los datos ingresados es incorrecto.\n" << endl;
			_iOpcion = menuInicial();
		}
	}while(contador == 0);
	
	do{
		iOpcion = menuOpciones();
		
		switch(iOpcion){
			case 0:
				cout << "\nEsperamos haya disfrutado de la experiencia de nuestra plataforma, nos vemos pronto" << endl;
				break;
				
			case 1:
				Series *listaSeries[10];
				int cantSeries;
				
				Videos *listaVideos[100];
				int cantVideos;
				
				cargaDatosSeries(listaSeries, cantSeries);
				cargaVideos(listaVideos, cantVideos);
				cout << "\nSe han cargado los datos" << endl;
				break;
			case 2:
				muestraPeliculas(listaVideos, cantVideos);
				iOpcion = regreso();
				break;
			case 3:
				muestraSeries(listaSeries, cantSeries);
				iOpcion = regreso();
				break;
			case 4:
				muestraVideosCalificacion(listaVideos, cantVideos);
				iOpcion = regreso();
				break;
			case 5:
				muestraVideosGenero(listaVideos, cantVideos);
				iOpcion = regreso();
				break;
			case 6:
				muestraEpisodiosTemporada(listaVideos, listaSeries, cantVideos, cantSeries);
				iOpcion = regreso(); 
				break;
			case 7:
				muestraPeliculasCalificacion(listaVideos, cantVideos);
				iOpcion = regreso();
				break;
			default:
        		cout << "Se ha ingresado una opcion inexistente." << endl;
        		break;
		}
	}while(iOpcion != 0);
	
	return 0;
}
