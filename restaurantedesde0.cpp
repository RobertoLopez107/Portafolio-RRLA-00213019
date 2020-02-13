#include <iostream>
#include <string>
using namespace std;

struct Pedido{
    string apellido;
    int mesa;
    int hamburguesa;
    int papas;
    int soda;
    int tiempo;
};

// Tipo de dato que contendran los nodos de la Cola
typedef Pedido T;
const T noValido = {{" "},-1,-1,-1,-1,-1};

// Registros: nodo y Cola
struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};


struct Cola{
    Nodo* frente;
    Nodo* final;
};


struct hamburgueseria{
    Cola colaPedidos;
    int hamburguesashechas;
};
hamburgueseria burguerking;



// Implementacion de funciones
void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;

    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;

    q->final = unNodo;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);

    int contador = 0;
    // Transfiriendo desde q hasta colaTemporal
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}







void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);

    // Transfiriendo desde burguerking.colaPedidos hasta colaTemporal
    while(!empty(&burguerking.colaPedidos)){
        Pedido unPedido = dequeue(&burguerking.colaPedidos);
        enqueue(&colaTemporal, unPedido);

        cout << "Info del pedido: " << unPedido.apellido << ", ";
        cout << "hamburguesa: " << unPedido.hamburguesa << ", ";
        cout << "papas: " << unPedido.papas << ", ";
        cout << "soda: " << unPedido.soda << "\n\n";
    }
    // Transfiriendo desde colaTemporal hasta burguerking.colaPedidos
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&burguerking.colaPedidos, elemento);
    }
}

void servir(){
    Pedido pedidoDespachado = dequeue(&burguerking.colaPedidos);
    cout << "Familia " << pedidoDespachado.apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.mesa << endl;
}

void consultar(){
    cout << "Pedidos en espera: " << size(&burguerking.colaPedidos) << endl;
    cout << "Total hamburguesas hechos: " << burguerking.hamburguesashechas << endl;
}

// Funciones ---------------------------------------
void agregar(){
    // Solicitar datos del pedido
    Pedido unPedido;
    cout << "Digite su apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Cantidad de hamburguesas de hamburguesa: "; cin >> unPedido.hamburguesa; cin.ignore();
    cout << "Cantidad de papas: "; cin >> unPedido.papas; cin.ignore();
    cout << "Cantidad de soda: "; cin >> unPedido.soda; cin.ignore();
    unPedido.tiempo = (unPedido.hamburguesa+unPedido.papas+unPedido.soda) * 90;

    // Agregar a la cola
    enqueue(&burguerking.colaPedidos, unPedido);
    // Modificar contadohamburguesa
    burguerking.hamburguesashechas += (unPedido.hamburguesa+unPedido.papas+unPedido.soda);
}

int main(){
    initialize(&burguerking.colaPedidos);
    burguerking.hamburguesashechas = 0;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();

        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

