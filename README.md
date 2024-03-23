# Ejercicio
Elaborar un programa que permita imprimir el menu que se presenta a continuación y programar la funcionalidad de cada opción.

MENU DE OPCIONES
1. Agregar cliente a la lista
2. Agregar cuenta a la lista.
3. Hacer abonos
4. Mostrar lista de clientes
5. Mostrar lista de cuentas
6. Mostrar detalles de la cuenta
7. Salir

## Opción 1
El programa debe solicitar el código, nombre y apellido del cliente, para crear un objeto de tipo de cliente y almacenarlo en un arreglo de tipo cliente. (Usted decide la capacidad máxima del arreglo, por lo cual, cuando este este lleno, el programa notificará que no se pueden almacenar mas objetos porque la lista esta llena). Las capturas deben hacerse de uno en uno, es decir cuando selecciona la opcion 1 captura los datos de un cliente y regresa al menu principal.

## Opción 2
Solicitará el código del cliente el cual sera buscado en el arreglo de clientes, y si se encuentra solicitará el numero de cuenta, para crear un objeto de tipo cuenta, el cual será almacenado en un arreglo de tipo cuenta (Usted decide la capacidad). Caso contrario mostrará un mensaje indicando que no se encontró el cliente y que por ese motivo no puede agregar la cuenta.

## Opción 3
Solicitará el numero de cuenta, el cual deberá ser buscado en el arreglo de cuentas, si se encuentra solicitará el monto y la fecha del abono el cual será registrado en la cuenta (por cada abono debe incrementarse el saldo de la cuenta). En caso que la cuenta no se encuentre debe notificar que no existe.

## Opción 4 y 5
Muestra la lista de clientes y cuentas respectivamente.

## Opción 6
Solicita el número de cuenta, el cual es buscado en el arreglo de cuentas, una vez es encontrado muestra los detalles de la cuenta (incluyendo los abonos), caso contrario notifica que no existe la cuenta

## Modelado de clases

<img width="1199" alt="Diagrama" src="https://github.com/JeffreyArgueta/EVALUACION01_PII/assets/163624985/650ea8c9-9559-42a9-89bc-8fc7f4e0f07e">
