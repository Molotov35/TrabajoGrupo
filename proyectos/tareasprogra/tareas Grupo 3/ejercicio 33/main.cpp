#include <iostream>

using namespace std;
int main (){

    int a, b, c;

    cout <<"Primer lado: "; cin >>a;
    cout <<"Segundo lado: "; cin>> b;
    cout <<"Tercer lado: "; cin >>c;


    if (a== b && a ==c)
        cout << "\n Es un triangulo Equilatero"<<endl;
    else if (a==b|| a==c||b==c)
        cout <<" \n Es un triagulo Isoseles"<<endl;
    else
        cout <<"\n Es un triangulo Escaleno"<<endl;
    return 0;
}
