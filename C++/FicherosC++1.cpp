#include <iostream>
#include <fstream> ///libreria ficheros

using namespace std;

int main(){

	ofstream txt;


	txt.open("pruebaficheros.txt",ios::out);

	if(!txt)
		cout << "El fichero no existe";
	else
		cout << "El fichero se ha abierto correctamente\n";	


	cout << "Nombre: ";
	 char nombre[20];
	 cin >> nombre;
	 txt << nombre << endl;

	
	cout << "Apellidos:";
	char apellidos[30];
	 	 
	 cin >> apellidos;
	 txt << apellidos << endl;

	txt.close();
	cout << "Pulse INTRO para finalizar...";
	cin.get();


///Problema: No funciona si pongo espacios...

	



	
return 0;

}