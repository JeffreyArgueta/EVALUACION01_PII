#include <iostream>
#include <iomanip>
#include "include/Cuenta.h"
#define DIM 10
#define WIDTH 12

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

Cliente *agregarCliente() {
    int id;
    string nombre, apellido;

    cout<<"Ingrese el ID del cliente: "; cin>>id;
    cout<<"Ingrese el nombre del cliente: "; cin>>nombre;
    cout<<"Ingrese el apellido del cliente: "; cin>>apellido;
    Cliente *C = new Cliente(id, nombre, apellido);

    return C;
}
Cliente *buscarCliente(Cliente *lstClientes[], int contCliente, int idCliente) {
    Cliente *C;
    int contInt = 0;
    bool encontrado = false;

    while (contInt < contCliente && !encontrado) {
        if (lstClientes[contInt]->getIdCliente() == idCliente) {
            C = lstClientes[contInt];
            encontrado = true;
        }
        else {
            contInt++;
        }
    }
    
    return C;
}
void mostrarListaClientes(Cliente *lstClientes[], int contCliente) {
    if (contCliente > 0) {
        cout<<left;
        cout<<setw(WIDTH)<<"ID"<<setw(WIDTH)<<"Nombre"<<setw(WIDTH)<<"Apellido"<<endl;
        for (int i = 0; i < contCliente; i++) {
            cout<<setw(WIDTH)<<lstClientes[i]->getIdCliente();
            cout<<setw(WIDTH)<<lstClientes[i]->getNombre();
            cout<<setw(WIDTH)<<lstClientes[i]->getApellido()<<endl;
        }
    }
    else {
        cout<<"Lista de clientes vacia."<<endl;
    }
}
Cuenta *agregarCuenta(Cliente cliente) {
    int numeroCuenta;

    cout<<"Ingrese el numero de la cuenta: "; cin>>numeroCuenta;
    Cuenta *C = new Cuenta(numeroCuenta, cliente);

    return C;
}
Cuenta *buscarCuenta(Cuenta *lstCuentas[], int contCuenta, int numeroCuenta) {
    Cuenta *C;
    int contInt = 0;
    bool encontrado = false;
    
    while (contInt < contCuenta && !encontrado) {
        if (lstCuentas[contInt]->getNumeroCuenta() == numeroCuenta) {
            C = lstCuentas[contInt];
            encontrado = true;
        }
        else {
            contInt++;
        }
    }
    
    return C;
}
void mostrarListaCuentas(Cuenta *lstCuentas[], int contCuenta) {
    if (contCuenta > 0) {
        cout<<setw(WIDTH)<<"No."<<setw(WIDTH)<<"Nombre"<<setw(WIDTH)<<"Apellido"<<setw(WIDTH)<<"Saldo"<<endl;
        for (int i = 0; i < contCuenta; i++) {
            cout<<setw(WIDTH)<<lstCuentas[i]->getNumeroCuenta();
            cout<<setw(WIDTH)<<lstCuentas[i]->getCliente().getNombre();
            cout<<setw(WIDTH)<<lstCuentas[i]->getCliente().getApellido();
            cout<<setw(WIDTH)<<lstCuentas[i]->getSaldo()<<endl;
        }
    }
    else {
        cout<<"Lista de cuentas vacia."<<endl;
    }
}
void verDetallesCuenta(Cuenta *cuenta) {
    cout<<"No. cuenta: "<<cuenta->getNumeroCuenta()<<endl;
    cout<<"Cliente: "<<cuenta->getCliente().getNombre()<<" "<<cuenta->getCliente().getApellido()<<endl;
    cout<<"Saldo: "<<cuenta->getSaldo()<<endl;

    if (cuenta->getContadorAbonos() > 0) {
        cout<<left;
        cout<<"\n"<<setw(WIDTH)<<"Fecha"<<setw(WIDTH)<<"Abono"<<endl;
        Abono **lst = cuenta->getLstAbonos();
        for (int i = 0; i < cuenta->getContadorAbonos(); i++) {
            cout<<setw(WIDTH); lst[i]->getFechaAbono().mostrarFecha();
            cout<<setw(WIDTH)<<lst[i]->getMontoAbono()<<endl;
        }
    }
    else {
        cout<<"\nNo tiene abonos realizados."<<endl;
    }
}

int main() {
    int op;
    Cuenta objCuenta = Cuenta(0,Cliente(0,"",""));
    Cliente *lstClientes[DIM];
    Cuenta *lstCuentas[DIM];
    int contCuenta = 0, contCliente = 0;
    do {
        system("cls");
        op = menu();
        switch (op) {
            case 1:
                /* AGREGAR CLIENTE A LA LISTA */
                {
                    if (contCliente < DIM) {
                        lstClientes[contCliente] = agregarCliente();
                        contCliente++;
                        cout<<"Cliente agregado exitosamente!"<<endl;    
                    }
                    else {
                        cout<<"Lista de clientes llena."<<endl;
                    }
                }
                break;
            case 2:
                /* AGREGAR CUENTA A LA LISTA */
                {
                    if (contCuenta < DIM) {
                        int idCliente;

                        cout<<"Ingrese el ID del cliente que abrira la cuenta: "; cin>>idCliente;
                        Cliente *cliente = buscarCliente(lstClientes, contCliente, idCliente);
                        if (cliente) {
                            lstCuentas[contCuenta] = agregarCuenta(*cliente);
                            contCuenta++;
                            cout<<"Cuente agregada exitosamente!"<<endl;
                        }
                        else {
                            cout<<"ID del cliente no existe. No se pudo agregar la cuenta."<<endl;
                        }
                    }
                    else {
                        cout<<"Lista de cuentas llena."<<endl;
                    }
                }
                break;
            case 3:
                /* HACER ABONO */
                {
                    int numeroCuenta;

                    cout<<"Ingrese el numero de la cuenta a la cual abonar: "; cin>>numeroCuenta;
                    Cuenta *cuenta = buscarCuenta(lstCuentas, contCuenta, numeroCuenta);
                    if (cuenta) {
                        int dia, mes, anio;
                        float montoAbono;

                        cout<<"---- FECHA DEL ABONO ----"<<endl;
                        cout<<"Dia: "; cin>>dia;
                        cout<<"Mes: "; cin>>mes;
                        cout<<"Anio: "; cin>>anio;
                        cout<<"-------------------------"<<endl;
                        Fecha fecha = Fecha(dia, mes, anio);
                        cout<<"Ingrese el monto del abono: "; cin>>montoAbono;
                        Abono *A = new Abono(fecha, montoAbono);
                        if (cuenta->agregarAbono(A)) {
                            cout<<"Abono realizado exitosamente!"<<endl;
                        }
                        else {
                            cout<<"Has alcanzado la cantidad maxima de abonos. No se pudo realizar el abono."<<endl;
                        }
                    }
                    else {
                        cout<<"El numero de la cuenta no existe."<<endl;
                    }
                }
                break;
            case 4:
                /* MOSTRAR LISTA DE CLIENTES */
                {
                    mostrarListaClientes(lstClientes, contCliente);
                }
                break;
            case 5:
                /* MOSTRAR LISTA DE CUENTAS */
                {
                    mostrarListaCuentas(lstCuentas, contCuenta);
                }
                break;
            case 6:
                /* MOSTRAR DETALLES DE LA CUENTA */
                {
                    int numeroCuenta;
                    cout<<"Ingrese el numero de la cuenta a mostrar: "; cin>>numeroCuenta;
                    Cuenta *cuenta = buscarCuenta(lstCuentas, contCuenta, numeroCuenta);
                    if (cuenta) {
                        verDetallesCuenta(cuenta);
                    }
                    else {
                        cout<<"El numero de la cuenta no existe."<<endl;
                    }
                }
                break;
            case 7:
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