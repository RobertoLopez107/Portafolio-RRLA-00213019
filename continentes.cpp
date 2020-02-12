#include <iostream>
#include <string>

using namespace std;

int contmen, contmay;
bool conti = false;

struct continentes {
    string nombre, pais, capital;
    int habit;
    double prom;
};

continentes continuevos[25];

int poblatot(string busqueda) {
    int suma = 0;
    for (int i = 0; i < 25; i++) {
        if (busqueda == continuevos[i].nombre) {
            conti = true;
            for (int j = i; j < i + 5; j++) {
                suma += continuevos[j].habit;
            }
            i = 26;
        } else {
            i += 4;
        }
    }
    return suma;
}

void ingresardatos(string continente, int i, int o) {

    cout << "Informacion del continente : " << continente << endl;

    for (i; i < o; i++) {
        continuevos[i].nombre = continente;
        cout << "Ingresa el nombre del pais: " << endl;
        cin >> continuevos[i].pais;
        cout << endl << "Ingresa el nombre de la capital: " << endl;
        cin >> continuevos[i].capital;
        cout << endl << "ingresa el numeros de habitantes del pais: " << endl;
        cin >> continuevos[i].habit;
        cout << endl << "Ingresa el promedio de edad: " << endl;
        cin >> continuevos[i].prom;
        cout << endl;
    }
    contmen += 5;
    contmay += 5;
    //cout<<contmen<<contmay;
}

int main() {
    int cantidad = 0;
    double promedio = 0;
    string pais, capital, nombrecontinente;
    contmen = 0, contmay = 5;
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa el nombre del continente: " << endl;
        cin>>nombrecontinente;
        ingresardatos(nombrecontinente, contmen, contmay);
    }
    while (!conti) {
        cout << "Ingresa el nombre del continente del que deseas saber su poblacion: " << endl;
        cin>>nombrecontinente;
        cout << "La suma de la poblacion del continente " << nombrecontinente << " es  : " << poblatot(nombrecontinente) << endl;
    }
    for (int i = 0; i < 25; i++) {
        if (continuevos[i].habit > cantidad) {
            pais = continuevos[i].pais;
            cantidad = continuevos[i].habit;
            capital = continuevos[i].capital;
        }
        promedio += continuevos[i].prom;
    }
    cout << "El pais mas poblado es: " << pais << endl;
    cout << "Su capital es: " << capital << endl << endl;
    cout << "El promedio de edades mundial es: " << (promedio / 25) << endl;
}