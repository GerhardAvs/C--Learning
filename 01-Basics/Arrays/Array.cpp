#include <iostream> //Entrada y salida en C++
#include <stdlib.h>//nos comunicamos con el Sistema Operativo para reiniciar la pantalla
#include <iomanip>

using namespace std;

int main(){
    float Prom;
    	int a[10][3] = {{87,97,70}, //[fila][columna] 0,0 = 1, 0,1 = 2, 0,2 = 3
	                	{68,87,90}, //contiguos en ram, un mismo tipo de dato
	                	{94,100,90},
	                	{100,81,82},
	                	{83,65,85},
	                	{78,87,65},
	                	{85,75,83},
	                	{91,94,100},
	                	{76,72,84},
	                	{87,93,73}};
	                	
	   cout<< "\t\t\t\tParcial 1 \t\tParcial 2 \t\tParcial 3\t\tPromedio\n"<<endl;
	   	for(int i = 0; i < 10; i++) {
	   	    Prom = 0;
	   	    cout << "Estudiante "<< i + 1<<"\t";
    		for(int j = 0; j<3; j++) {
    			cout <<"   "<< a[i][j] << "\t\t\t";
    			Prom = (Prom + a[i][j]);
    		}
    		    Prom = Prom/3.0;
    		    cout<<"  "<< setprecision(3) <<Prom<< endl;
    	}
}
