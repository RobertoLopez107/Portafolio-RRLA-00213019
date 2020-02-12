#include <iostream>
#include <stack>

using namespace std;

void pila(){
    stack <int> s;
    
    int e=0,r=0;
    
    cout<<"Si desea ingresar un valor a la pila digite 1 o 0 para finalizar: "<<endl;
    cin>>r;
    
    while(r==1){
        cout<<"Ingrese el valor a almacenar: "<<endl;
        cin>>e;
        
        s.push(e);
        
        cout<<"Si desea almacenar otro valor ingrese 1, o 0 para finalizar: "<<endl;
        cin>>r;
    
    }

    if(r==0){
        
        if(s.empty()){
        
            cout<<"La pila esta vacia"<<endl;
            
        }
        else{
            
            cout << "El tamaño de la Pila es de: " << s.size() << endl;
            
            int a=0;
	
            while(!s.empty()){
                
                a=s.top();
                s.pop();
                    
                    if(s.empty())
                    cout<<"El valor del fondo es: "<<a;
                    }
    
        }
    }
}

int main()
{
	
    
    pila();
	
	
}