#include <iostream>
#include "include/Cuenta.h"

using namespace std;

int menu() {
    int op;
    cout<<"1. Agregar cliente a la lista"<<endl;
    cout<<"2. Agregar cuenta a la lista"<<endl;
    cout<<"3. Hacer abonos"<<endl;
    cout<<"4. Mostrar lista de clientes"<<endl;
    cout<<"5. Mostrar lista de cuentas"<<endl;
    cout<<"6. Mostrar detalles de la cuenta"<<endl;
    cout<<"7. Salir"<<endl;
    cout<<"\nDigitar opcion: "; cin>>op;
    return op;
}

int main() {
    int op;
    do {
        system("cls");
        op = menu();
        switch (op) {
            case '1':
                /* AGREGAR CLIENTE A LA LISTA */
                break;
            case '2':
                /* AGREGAR CUENTA A LA LISTA */
                break;
            case '3':
                /* HACER ABONO */
                break;
            case '4':
                /* MOSTRAR LISTA DE CLIENTES */
                break;
            case '5':
                /* MOSTRAR LISTA DE CUENTAS */
                break;
            case '6':
                /* MOSTRAR DETALLES DE LA CUENTA */
                break;
            case '7':
                /* SALIR */
                cout<<"Saliendo del programa"<<endl;
                break;
            default:
                cout<<"Error, opcion no esta definida"<<endl;
                break;
        }
        system("pause");
    } while (op != 7);
    return 0;
}