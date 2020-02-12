#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct actividad{
    string titulo;
    string hora;
    int duracion;
};
typedef struct actividad Actividades;

struct AgregarAct{
    queue <Actividad> colaActividad;
};
typedef struct AgregarAct agregar

Actividad cant;

void agregarActividad();
void verActividad();
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
            case 2: verActividad(); break;
            case 3: borrarActividad(); break;
            case 4: borrarTodo(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregarActividad(){
    actividad Actividades;
    // Solicitar datos del trabajo
    actividad Actividades;
    cout << "Digite el titulo de la actividad: "; getline(cin, actividad.titulo);
    cout << "Digite la hora: "; getline(cin, actividad.hora);
    cout << "Duracion: "; cin >> actividad.duracion; cin.ignore();
    // Agregar a la cola
    epson380.colaImpresion.push(unTrabajo);
    // Modificar contadores
    epson380.trabajosRealizados++;
    epson380.paginasUtilizadas += unTrabajo.paginas;
}

void consultar(){
    cout << "Trabajos actuales en cola: " << epson380.colaImpresion.size() << endl;
    cout << "Trabajos totales: " << epson380.trabajosRealizados << endl;
    cout << "Total paginas utilizadas: " << epson380.paginasUtilizadas << endl;
}

void imprimir(){
    while(!epson380.colaImpresion.empty()){
        // Ver el documento que esta en el frente de la cola
        Trabajo docListoImprimirse = epson380.colaImpresion.front();
        cout << "Imprimiendo el archivo " << docListoImprimirse.documento;
        cout << " consta de " << docListoImprimirse.paginas << " paginas";
        cout << ". Tiempo: " << docListoImprimirse.tiempo << " seg" << endl;

        // Sacarlo para que se pueda imprimir el siguiente
        epson380.colaImpresion.pop();
    }
    cout << "Cola de impresion vacia!" << endl;
}
