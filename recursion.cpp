#include <iostream>
using namespace std;

int suma(int b){
    int n;
    cout << "Introduzca el numero hasta donde quiere llegar: " << endl;
    cin >> n;
	if(b==n){
		cout << "b=" << b << " caso base" << endl;
		return 1;
	}else{
		return  b + (n - 2);
	}


}int main(){

	int b=1;

		int r = suma(b);
		cout << "Resultado de la suma del numero:" << r << endl;


return 0;
}
