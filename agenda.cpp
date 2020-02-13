#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct actividad{
    string titulo;
    string hora;
    int duracion;
    int trabajosRealizados;
    int unTrabajo;
};
typedef struct actividad;

struct AgregarAct{
    queue <actividad> colaActividad;
    int actividadesRealizadas;
};
typedef struct AgregarAct;

AgregarAct agregar;

void agregarActividad();
void consultar();
void borrarActividad();
void borrarTodo();

int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar una actividad\n";
        cout << "2) Ver actividades\n";
        cout << "3) Borrar una actividad\n";
        cout << "4) Borrar todas las actividad\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();

        switch(opcion){
            case 1: agregarActividad(); break;
            case 2: consultar(); break;
            case 3: borrarActividad(); break;
            case 4: borrarTodo(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregarActividad(){
    AgregarAct agregar;
    actividad Actividad;
    agregar.actividadesRealizadas = 0;
    cout << "Digite el titulo de la actividad: "; getline(cin, Actividad.titulo);
    cout << "Digite la hora: "; getline(cin, Actividad.hora);
    cout << "Duracion: "; cin >> Actividad.duracion; cin.ignore();
    // Agregar a la cola
    agregar.colaActividad.push(Actividad);
    agregar.actividadesRealizadas ++;
   
}

void consultar(){
    actividad Actividades;
    AgregarAct agregar;
    cout << "Actividades actuales en agenda en cola: " << agregar.colaActividad.size() << endl;
    cout << "Trabajos totales " << agregar.actividadesRealizadas << endl;
}

void borrarActividad(){
    actividad Actividades;
    string aux;

    cout << "Ingrese el nombre que desea eliminar";
    cin >> aux;
    if(Actividades.titulo == aux){
        Actividades.titulo.pop_back();
    }
}

void borrarTodo(){
    actividad Actividades;
    for(int i = 0; i < Actividades.titulo[i]; i++)
    Actividades.titulo[i] = NULL;
}