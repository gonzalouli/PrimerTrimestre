#include <iostream>
#include <fstream>

struct ficha{
	char nombre[20];
	int edad;
};

using namespace std;

int main(){

	struct ficha fichapersona;
	int n;

	ofstream mificha;

	mificha.open("DatosDeFicha.dat",ios::out | ios::binary);

	if(!mificha)
		cout << "Error al crear el archivo";
	else{

		for(n=1;n<=2;n++){
			cout << "Introduce tu nombre: ";
			cin >> fichapersona.nombre ;
			cout << "\nEscriba la edad: ";
			cin >> fichapersona.edad;

			mificha.write((char*) &fichapersona, sizeof(ficha));
			
				
			
		}
	}


	char cadena[180];

	ifstream lectura;

	lectura.open("DatosDeFicha.dat",ios::binary);

	if(!lectura)
		cout << "Error al crear el archivo";
	else{
		while(!lectura.eof()){
			lectura >> cadena;
			cout << cadena;
		}
	}
///para meter cadenas usa getline();
	lectura.close();

	return 0;







return 0;
}