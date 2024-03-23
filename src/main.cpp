#include <iomanip>
#include "../include/Cuenta.h"
#define DIM 10
#define WIDTH 12

using namespace std;

char menu() {
    char op;
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
    Cliente *C = nullptr;
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
        system("cls");
        cout<<left;
        cout<<setw(WIDTH)<<"ID"<<setw(WIDTH)<<"Nombre"<<setw(WIDTH)<<"Apellido"<<endl;
        for (int i = 0; i < contCliente; i++) {
            cout<<setw(WIDTH)<<lstClientes[i]->getIdCliente();
            cout<<setw(WIDTH)<<lstClientes[i]->getNombre();
            cout<<setw(WIDTH)<<lstClientes[i]->getApellido()<<endl;
        }
        cout<<endl;
    }
    else {
        cout<<"\nLista de clientes vacia.\n"<<endl;
    }
}

Cuenta *agregarCuenta(Cliente cliente) {
    int numeroCuenta;

    cout<<"Ingrese el numero de la cuenta: "; cin>>numeroCuenta;
    Cuenta *C = new Cuenta(numeroCuenta, cliente);

    return C;
}

Cuenta *buscarCuenta(Cuenta *lstCuentas[], int contCuenta, int numeroCuenta) {
    Cuenta *C = nullptr;
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
        system("cls");
        cout<<setw(WIDTH)<<"No."<<setw(WIDTH)<<"Nombre"<<setw(WIDTH)<<"Apellido"<<setw(WIDTH)<<"Saldo"<<endl;
        for (int i = 0; i < contCuenta; i++) {
            cout<<setw(WIDTH)<<lstCuentas[i]->getNumeroCuenta();
            cout<<setw(WIDTH)<<lstCuentas[i]->getCliente().getNombre();
            cout<<setw(WIDTH)<<lstCuentas[i]->getCliente().getApellido();
            cout<<setw(WIDTH)<<lstCuentas[i]->getSaldo()<<endl;
        }
        cout<<endl;
    }
    else {
        cout<<"\nLista de cuentas vacia.\n"<<endl;
    }
}

void verDetallesCuenta(Cuenta *cuenta) {
    cout<<"\nNo. cuenta: "<<cuenta->getNumeroCuenta()<<endl;
    cout<<"Cliente: "<<cuenta->getCliente().getNombre()<<" "<<cuenta->getCliente().getApellido()<<endl;
    cout<<"Saldo: "<<cuenta->getSaldo()<<endl;

    cout<<"\n--------- ABONOS ---------"<<endl;
    
    if (cuenta->getContadorAbonos() > 0) {
        cout<<setw(WIDTH)<<"Abono"<<setw(WIDTH)<<"Fecha"<<endl;

        Abono *const *lst = cuenta->getLstAbonos();

        for (int i = 0; i < cuenta->getContadorAbonos(); i++) {
            cout<<setw(WIDTH)<<lst[i]->getMontoAbono();
            lst[i]->getFechaAbono()->mostrarFecha();
            cout<<endl;
        }
    }
    else {
        cout<<"- Sin abonos realizados"<<endl;
    }

    cout<<"--------------------------\n"<<endl;
}

int main() {
    char op;
    Cliente *lstClientes[DIM];
    Cuenta *lstCuentas[DIM];
    int contCliente = 0, contCuenta = 0;

    do {
        system("cls");
        op = menu();
        switch (op) {
            case '1':
                /* AGREGAR CLIENTE A LA LISTA */
                {
                    system("cls");
                    if (contCliente < DIM) {
                        lstClientes[contCliente] = agregarCliente();
                        contCliente++;
                        cout<<"\nCliente agregado exitosamente!\n"<<endl;    
                    }
                    else {
                        cout<<"Lista de clientes llena.\n"<<endl;
                    }
                }
                break;
            case '2':
                /* AGREGAR CUENTA A LA LISTA */
                {
                    system("cls");
                    if (contCuenta < DIM) {
                        int idCliente;

                        cout<<"Ingrese el ID del cliente que abrira la cuenta: "; cin>>idCliente;
                        Cliente *cliente = buscarCliente(lstClientes, contCliente, idCliente);
                        if (cliente != nullptr) {
                            lstCuentas[contCuenta] = agregarCuenta(*cliente);
                            contCuenta++;
                            cout<<"\nCuenta agregada exitosamente!\n"<<endl;
                        }
                        else {
                            cout<<"\nID del cliente no existe. No se pudo agregar la cuenta.\n"<<endl;
                        }
                    }
                    else {
                        cout<<"Lista de cuentas llena.\n"<<endl;
                    }
                }
                break;
            case '3':
                /* HACER ABONO */
                {
                    system("cls");
                    int numeroCuenta;

                    cout<<"Ingrese el numero de la cuenta a la cual abonar: "; cin>>numeroCuenta;
                    Cuenta *cuenta = buscarCuenta(lstCuentas, contCuenta, numeroCuenta);
                    if (cuenta != nullptr) {
                        if (cuenta->getContadorAbonos() < DA) {
                            int dia, mes, anio;
                            float montoAbono;

                            cout<<endl;
                            cout<<"---- FECHA DEL ABONO ----"<<endl;
                            cout<<"Dia: "; cin>>dia;
                            cout<<"Mes: "; cin>>mes;
                            cout<<"Anio: "; cin>>anio;
                            cout<<"-------------------------"<<endl;
                            cout<<"Ingrese el monto del abono: "; cin>>montoAbono;

                            Fecha *fecha = new Fecha(dia, mes, anio);
                            Abono *A = new Abono(fecha, montoAbono);

                            if (cuenta->agregarAbono(A)) {
                                cout<<"\nAbono realizado exitosamente!\n"<<endl;
                            }
                            else {
                                cout<<"\nError, no se pudo agregar el abono.\n"<<endl;
                            }
                        }
                        else {
                            cout<<"\nEsta cuenta ya alcanzo su limite de abonos.\n"<<endl;
                        }
                    }
                    else {
                        cout<<"\nEl numero de la cuenta no existe.\n"<<endl;
                    }
                }
                break;
            case '4':
                /* MOSTRAR LISTA DE CLIENTES */
                {
                    mostrarListaClientes(lstClientes, contCliente);
                }
                break;
            case '5':
                /* MOSTRAR LISTA DE CUENTAS */
                {
                    mostrarListaCuentas(lstCuentas, contCuenta);
                }
                break;
            case '6':
                /* MOSTRAR DETALLES DE LA CUENTA */
                {
                    if (contCuenta > 0) {
                        system("cls");
                        int numeroCuenta;

                        cout<<"Ingrese el numero de la cuenta a mostrar: "; cin>>numeroCuenta;
                        Cuenta *cuenta = buscarCuenta(lstCuentas, contCuenta, numeroCuenta);

                        if (cuenta != nullptr) {
                            verDetallesCuenta(cuenta);
                        }
                        else {
                            cout<<"\nNumero de cuenta incorrecto o inexistente.\n"<<endl;
                        }
                    }
                    else {
                        cout<<"\nNo existen cuentas a mostrar.\n"<<endl;
                    }
                }
                break;
            case '7':
                /* SALIR */
                {
                    system("cls");
                    cout<<"Saliendo del programa...\n"<<endl;
                }
                break;
            default:
                {
                    cout<<"\nError, opcion no esta definida.\n"<<endl;
                }
                break;
        }
        system("pause");
    } while (op != '7');

    return 0;
}