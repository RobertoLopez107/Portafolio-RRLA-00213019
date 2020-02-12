#include <iostream>
using namespace std;

int main (void) {
int tamano, mitad1,modulo, mitad2;
float resp, num1, num2;

cout<<"Ingrese la cantidad de digitos a medir:"<<endl;
cin>>tamano;

int mediana[tamano];

for(int i=0; i<tamano; i++){
cout<<"Ingrese el digito "<< i+1 <<": "<<endl;
cin>>mediana[i];
}

modulo= tamano%2;

if(modulo==0){
	mitad1=tamano/2;
	mitad2=mitad1-1;
	num1=mediana[mitad1];
	num2=mediana[mitad2];
	resp= ((num1+num2)/2);
	cout<<"La mediana es: "<<resp<<endl;
}else{
   mitad1=tamano/2;
   cout<<"La mediana es: "<<mediana[mitad1]<<endl;	
}
return 0;
}