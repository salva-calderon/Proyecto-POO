//	Series.h

#include <iostream>
using namespace std;

class Series {
	public:
		Series();
		Series(int ID, string nombreS);
		
		void setID(int ID) {this->ID = ID;}
		void setNombreS(string nombreS) {this->nombreS = nombreS;}
		
		int getID() {return ID;}
		string getNombreS() {return nombreS;}
		
		void muestra();
	
	private:
		string nombreS;
		int ID;
};

Series::Series(){
	nombreS = "-";
	ID = 0;
}

Series::Series(int ID, string nombreS){
	this->ID = ID;
	this->nombreS = nombreS;
}

void Series::muestra(){
	string guion = "_", rempl = " ";
	int pos = nombreS.find(guion);
	while(pos != -1){
		nombreS.replace(pos, guion.size(), rempl);
		pos = nombreS.find(guion, pos+rempl.size());
	}
	cout << "- Serie: " << nombreS << endl;
	cout << "- ID: " << ID << endl;
}
