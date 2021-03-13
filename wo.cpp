#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int menu() {
    int contenedor;
    int dato;
    system("cls");
    cout<<"<<------------>>"<<endl<<endl;
    cout<<"1. Nombre del trabajador "<<endl;
    cout<<"2. Datos de trabajadores"<<endl;
    cout<<"3. Modificar datos"<<endl;
    cout<<"4. Eliminar registro"<<endl;
    cout<<"5. salir"<<endl;
    cout<<"opcion ";
    cin>>contenedor;
    return contenedor;
}

void agregar(ofstream &es) {
	system("cls");
	string dato;
	string tra;
	string puesto;
	es.open("datos.dat", ios::out | ios::app);
	cout<<"nombre ";
	cin>>dato;
	cout<<"codigo ";
	cin>>dato;
	cout<<"Sueldo";
	cin>>tra;
	cout<<"puesto ";
	cin>>puesto;
	es<<dato<<"  "<<tra<<"  "<<puesto<<"\n";
	es.close();
}

void verRegistros(ifstream &Lec) {
	system("cls");
	string dato;
	string puesto;
	string tra;
	Lec.open("datos.dat", ios::in);
	if(Lec.is_open()){
	  cout<<"------Datos Guardados------"<<endl<<endl;
	  Lec>>dato;
	  while(!Lec.eof()) {
	    Lec>>tra;
	    Lec>>puesto;
	    cout<<"Nombre--------:"<<dato<<endl;
	    cout<<"Codigo--------:"<<tra<<endl;
	    cout<<"Puesto--------:"<<puesto<<endl;
	    cout<<"------------------"<<endl;
	    Lec>>dato;
	}
	Lec.close();
	}else 
	     cout<<"Error"<<endl;
	system("pause");
	
}

void modificar(ifstream  &Lec){
	system("cls");
	string dato;
	string tra;
	string puesto;
	
	string datoaucontenedor;
	string traaucontenedor;
	Lec.open("datos.dat", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Nombre ";
		cin>>datoaucontenedor;
		Lec>>traaucontenedor;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>dato;
			if(dato == datoaucontenedor){
				cout<<"Nuevo Nombre ";
				cin>>datoaucontenedor;
				aux<<datoaucontenedor<<"  "<<puesto<<" "<<tra<<"\n";
				
			}else{
			   
			}
		    Lec>>puesto;
		    
		}
		Lec.close();
		aux.close();
	}else
	     cout<<"Error"<<endl;
	remove("datos.dat");
	rename("auxiliar.txt", "datos.dat");
	
}

void eliminar(ifstream  &Lec){
    system("cls");
	string dato;
	string tra;
	string puesto;
	string datoaucontenedor;
	string traaucontenedor;
	Lec.open("datos.dat", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Nombre";
		cin>>datoaucontenedor;
		Lec>>traaucontenedor;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>dato;
			if(dato == datoaucontenedor){
				cout<<"Eliminado";
				Sleep(1500);
				aux<<datoaucontenedor<<"  "<<puesto<<" "<<tra<<"\n";

			}else{
			    aux<<dato<<"  "<<puesto<<" "<<tra<<"\n";
			}
		    Lec>>puesto;

		}
		Lec.close();
		aux.close();
	}else
	     cout<<"Error"<<endl;
	remove("datos.dat");
	rename("auxiliar.txt", "datos.dat");
}

int main () {
    ofstream Esc;
    ifstream Lec;
    int op;
    do{ 
       system("cls");
       op = menu();
	   switch(op){
	   	    case 1:
	   	    	    agregar(Esc);
	   	    break;	  
			case 2:
 			        verRegistros(Lec);
			break; 
			case 3:
			        modificar(Lec);
			break;
			case 4:
					eliminar(Lec);
            break;
	   }	
	}while(op != 5);
	return 0;
}
