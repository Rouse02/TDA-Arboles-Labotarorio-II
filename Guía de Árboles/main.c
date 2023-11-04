#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <time.h>

#define DIM 30

/*Estructuras*/

typedef struct nodoArbol{

    int dato;
    struct nodoArbol *Izquierda;
    struct nodoArbol *Derecha;

}nodoArbol;

typedef struct Persona {

        int legajo;
        char nombreYapellido[DIM];
        int edad;

}Persona;

typedef struct nodoArbolPersona {

    Persona informacionPersona;
    struct nodoArbolPersona *Izquierda;
    struct nodoArbolPersona *Derecha;

}nodoArbolPersona;

typedef struct nodoSimple {

    Persona informacionPersona;
    struct nodoSimple *ptrSiguiente;

}nodoSimple;

/*Prototipado*/
void menu();
void consignas();

void ejercicio1();

void ejercicio2();
nodoArbol *inicializarArbol();
nodoArbol *crearNodoArbol(int dato);
nodoArbol *insertarOrdenado(nodoArbol *ptrArbol, int dato);
int cantidadHojas(nodoArbol *ptrArbol);
int cantidadNodosGrado1(nodoArbol *ptrArbol);
int buscarDato(nodoArbol *ptrArbol, int dato);

void ejercicio3();
nodoArbolPersona *inicializarArbolPersona();
nodoArbolPersona *crearNodoArbolPersona(Persona unaPersona);
nodoArbolPersona *insertarPersona(nodoArbolPersona *ptrArbol, Persona unaPersona);
void mostrarPreOrden(nodoArbolPersona *ptrArbol);
void mostrarInOrden(nodoArbolPersona *ptrArbol);
void mostrarPosOrden(nodoArbolPersona *ptrArbol);
nodoArbolPersona *eliminarNodoPersona(nodoArbolPersona *ptrArbol, int legajoPersona);
nodoArbolPersona *encontrarMinimo(nodoArbolPersona *ptrArbol);
nodoArbolPersona *tomarNodoDeMayorValor(nodoArbolPersona *ptrArbol);
nodoArbolPersona *tomarNodoDeMenorValor (nodoArbolPersona *ptrArbol);
nodoArbolPersona *eliminarNodo(nodoArbolPersona *ptrArbol, int legajoPersona);
Persona cargarUnaPersona();
nodoArbolPersona *insertarPersonasHasta(nodoArbolPersona *ptrArbol);

void ejercicio4();
void mostrarPersona(Persona unaPersona);

void ejercicio5();
nodoSimple *inicializarLista();
nodoSimple *crearNodo(Persona unaPersona);
nodoSimple *buscarUltimo(nodoSimple *ptrLista);
nodoSimple *agregarAlFinal(nodoSimple *ptrLista, nodoSimple *nuevoNodo);
nodoSimple *copiarElArbolEnLista(nodoSimple *ptrLista, nodoArbolPersona *ptrArbol);
void mostrarLista(nodoSimple *ptrLista);

void ejercicio6();
nodoArbolPersona *buscarPersonaPorLegajo(nodoArbolPersona *ptrArbol, int legajo);

void ejercicio7();
nodoArbolPersona *buscarPersonaPorNombre(nodoArbolPersona *ptrArbol, char nombrePersona[]);

void ejercicio8();
int calcularAlturaDeArbol(nodoArbolPersona *ptrArbol);

void ejercicio9();
int calcularCantidadNodosArbol(nodoArbolPersona *ptrArbol);

void ejercicio10();
int calcularCantidadHojasDelArbol(nodoArbolPersona *ptrArbol);

void ejercicio11();
nodoArbolPersona *encontrarMin(nodoArbolPersona *ptrArbol);
nodoArbolPersona *borrarNodo(nodoArbolPersona *ptrArbol, int legajo);
/*--------------------------------------------------------------------------------------------------------*/
int main(){

menu();

}
/*--------------------------------------------------------------------------------------------------------*/
//Funciones

void menu() {
    srand(time(NULL));
    char eleccion = 's';
    int ejercicio;

    consignas();

    do {
    printf("Ingrese el Numero de ejercicio a dirigirse --> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");


    switch(ejercicio) {

    case 1:
        ejercicio1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio3();
        break;

    case 4:
        ejercicio4();
        break;

    case 5:
        ejercicio5();
        break;

    case 6:
        ejercicio6();
        break;

    case 7:
       ejercicio7();
        break;

    case 8:
        ejercicio8();
        break;

    case 9:
        ejercicio9();
        break;

    case 10:
        ejercicio10();
        break;

    case 11:
        ejercicio11();
        break;

    default:
        printf("Has ingresado un numero incorrecto, vuelve a intentarlo \n\n");
        break;
        }

        printf("\nPulse 's' para ingresar a otro ejercicio --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's');
}

void consignas() {
    printf("FUNCIONES DE ARBOL BINARIO\n\n");
    printf("1)Mostrar sin desarrollar codigo:\n\n");
    printf("a)El contenido de sus nodos segun cada recorrido: preorden, inorden y posorden\n\n");
    printf("b)Mostrar sin desarrollar código:\n\n");
    printf("2)Indicar niveles y altura\n\n");
    printf("FUNCIONES DE ARBOL BINARIO DE BUSQUEDA\n\n");
    printf("3)Hacer una funcion que permita ingresar nuevos nodos manteniendo el arbol ordenado (por legajo)\n\n");
    printf("4)Hacer tres funciones, una funcion que recorra el arbol y muestre su contenido en orden (verificar cual de los recorridos es conveniente: inorder, posorder o preorder). Modularizar\n\n");
    printf("5)Hacer una funcion que copie el contenido del arbol en una lista simplemente enlazada\n\n");
    printf("6)Hacer una funcion que busque un nodo por legajo y lo retorne\n\n");
    printf("7)Hacer una funcion que busque un nodo por nombre. Cuidado, el arbol esta ordenado por legajo\n\n");
    printf("8)Hacer una funcion que calcule la altura que tiene el arbol\n\n");
    printf("9)Hacer una funcion que calcule la cantidad de nodos del arbol\n\n");
    printf("10)Hacer una funcion que calcule la cantidad de hojas del arbol\n\n");
    printf("11)Hacer una funcion que borre un nodo de un arbol\n\n");
}
//Ejercicios
void ejercicio1() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 1 \n\n");
    printf("Ejercicio a) \n\n");

    printf("PreOrden: R-I-D: 8-3-1-6-4-7-10-14-13\n\n");
    printf("InOrden: I-R-D: 1-4-6-7-3-8\n\n");
    printf("PosOrden: I-D-R: 1-4-7-6-13-14-10-8\n\n");

    printf("Ejercicio b) \n\n");

    printf("Niveles: 3 \n\n");
    printf("Altura: 3 \n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void ejercicio2() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 2 \n\n");

    nodoArbol *ptrArbol = inicializarArbol(); //Declaración e inicialización del Árbol

    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    int datosDelArbol[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};

    for(int i = 0; i < 9; i++) ptrArbol = insertarOrdenado(ptrArbol, datosDelArbol[i]);

    printf("Pre Orden: ");
    preOrder(ptrArbol);
    printf("\n\n");

    printf("In Orden: ");
    inOrder(ptrArbol);
    printf("\n\n");

    printf("Pos Orden: ");
    posOrder(ptrArbol);
    printf("\n\n");

    printf("Ejercicio a) \n\n");

    int cantHojas = cantidadHojas(ptrArbol);

    printf("Cantidad de Hojas del Arbol: %i\n\n", cantHojas);

    printf("Ejercicio b) \n\n");

    int cantNodosGrado1 = cantidadNodosGrado1(ptrArbol);

    printf("Cantidad de Nodos de Grado 1: %i\n\n", cantNodosGrado1 );

    printf("Ejercicio c) \n\n");

    int resultadoBusqueda = buscarDato(ptrArbol, 0);

    if(resultadoBusqueda == 1) printf("El dato se encuentra en el Arbol \n\n");

    else printf("El dato no se encuentra en el Arbol \n\n");

    printf("Ejercicio d) \n\n");

    printf("Pre Orden: ");
    preOrder(ptrArbol);
    printf("\n\n");

    int altura = calcularAlturaDeArbol(ptrArbol);

    printf("La altura del arbol es = %i \n\n", altura);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoArbol *inicializarArbol() {
    return NULL;
}

nodoArbol *crearNodoArbol(int dato) {

    nodoArbol *nuevoNodo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevoNodo->dato = dato;
    nuevoNodo->Izquierda = NULL;
    nuevoNodo->Derecha = NULL;

    return nuevoNodo;
}

void preOrder(nodoArbol *ptrArbol){

    if(ptrArbol){ //Sí Árbol tiene datos...

    printf("%i ", ptrArbol->dato);//Muestra raíz antes de recorrer subárbol izq y der.
    preOrder(ptrArbol->Izquierda);
    preOrder(ptrArbol->Derecha);
    }
}

void inOrder(nodoArbol *ptrArbol){

    if(ptrArbol){

    inOrder(ptrArbol->Izquierda);
    printf("%i ",ptrArbol->dato);
    inOrder(ptrArbol->Derecha);
    }
}

void posOrder(nodoArbol *ptrArbol){

    if(ptrArbol){

    posOrder(ptrArbol->Izquierda);
    posOrder(ptrArbol->Derecha);
    printf("%i ",ptrArbol->dato);
    }
}
nodoArbol *insertarOrdenado(nodoArbol *ptrArbol, int dato) {

    if(ptrArbol == NULL) ptrArbol = crearNodoArbol(dato);

    else {

        if(dato > ptrArbol->dato) ptrArbol->Derecha = insertarOrdenado(ptrArbol->Derecha, dato);

        else ptrArbol->Izquierda = insertarOrdenado(ptrArbol->Izquierda, dato);
    }
    return ptrArbol;
}

int cantidadHojas(nodoArbol *ptrArbol) {

    int contador = 0;
    if(ptrArbol != NULL) {

        if((ptrArbol->Izquierda  == NULL)  && (ptrArbol->Derecha == NULL)) contador++;

        contador = contador + cantidadHojas(ptrArbol->Izquierda);
        contador = contador + cantidadHojas(ptrArbol->Derecha);
    }
    return contador;
}

int cantidadNodosGrado1(nodoArbol *ptrArbol) {

    int contador = 0;
    if(ptrArbol != NULL) {

        if((ptrArbol->Izquierda  != NULL)  && (ptrArbol->Derecha == NULL)) contador ++;

        else if((ptrArbol->Derecha  != NULL)  && (ptrArbol->Izquierda == NULL)) contador ++;

        contador  = contador + cantidadNodosGrado1(ptrArbol->Izquierda);
        contador  = contador + cantidadNodosGrado1(ptrArbol->Derecha);
    }
    return contador;
}

int buscarDato(nodoArbol *ptrArbol, int dato) {

    if(ptrArbol != NULL) {

        return (ptrArbol->dato == dato) || buscarDato(ptrArbol->Izquierda, dato) || buscarDato(ptrArbol->Derecha, dato);

    }else return 0;
}

void ejercicio3() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 3 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("Pre Orden: ");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoArbolPersona *inicializarArbolPersona() {
    return NULL;
}

nodoArbolPersona *crearNodoArbolPersona(Persona unaPersona) {

    nodoArbolPersona *nuevoNodo = (nodoArbolPersona *) malloc(sizeof(nodoArbolPersona));

    nuevoNodo->Izquierda= NULL;
    nuevoNodo->Derecha = NULL;
    nuevoNodo->informacionPersona = unaPersona;

    return nuevoNodo;
}

nodoArbolPersona *insertarPersona(nodoArbolPersona *ptrArbol, Persona unaPersona) {

    if(ptrArbol == NULL) ptrArbol = crearNodoArbolPersona(unaPersona);

    else{
        if(unaPersona.legajo > ptrArbol->informacionPersona.legajo) ptrArbol->Derecha = insertarPersona(ptrArbol->Derecha, unaPersona);
        else ptrArbol->Izquierda = insertarPersona(ptrArbol->Izquierda, unaPersona);
    }
    return ptrArbol;
}

void mostrarPersona(Persona unaPersona) {

    printf("Nombre y Apellido |%s| \n", unaPersona.nombreYapellido);
    printf("Nro de Legajo |%i| \n", unaPersona.legajo);
    printf("Edad |%i| \n\n", unaPersona.edad);
}

void mostrarPreOrden(nodoArbolPersona *ptrArbol) {

    if(ptrArbol != NULL) {

            mostrarPersona(ptrArbol->informacionPersona);
            mostrarPreOrden(ptrArbol->Izquierda);
            mostrarPreOrden(ptrArbol->Derecha);
    }
}

void mostrarInOrden(nodoArbolPersona *ptrArbol) {

    if(ptrArbol != NULL) {

            mostrarPreOrden(ptrArbol->Izquierda);
            mostrarPersona(ptrArbol->informacionPersona);
            mostrarPreOrden(ptrArbol->Derecha);
    }
}

void mostrarPosOrden(nodoArbolPersona *ptrArbol) {

    if(ptrArbol != NULL) {

            mostrarPreOrden(ptrArbol->Izquierda);
            mostrarPreOrden(ptrArbol->Derecha);
            mostrarPersona(ptrArbol->informacionPersona);
    }
}

nodoArbolPersona *encontrarMinimo(nodoArbolPersona *ptrArbol) {

    while (ptrArbol->Izquierda != NULL)  ptrArbol = ptrArbol->Izquierda;

    return ptrArbol;
}

nodoArbolPersona *eliminarNodo(nodoArbolPersona *ptrArbol, int legajoPersona) {

    if (ptrArbol == NULL) return NULL;

    if(legajoPersona < ptrArbol->informacionPersona.legajo) ptrArbol->Izquierda = eliminarNodo(ptrArbol->Izquierda, legajoPersona);

    else if(legajoPersona > ptrArbol->informacionPersona.legajo)  ptrArbol->Derecha = eliminarNodo(ptrArbol->Derecha, legajoPersona);

    else {

        if (ptrArbol->Izquierda == NULL) {

            nodoArbolPersona *nodoAux = ptrArbol->Derecha;
            free(ptrArbol);
            return nodoAux;
        }
        else if(ptrArbol->Derecha == NULL)
        {
            nodoArbolPersona * nodoAux = ptrArbol->Izquierda;
            free(ptrArbol);
            return nodoAux;
        }
        nodoArbolPersona *nodoAux = encontrarMinimo(ptrArbol->Derecha);///funcion complementaria...

        ptrArbol->informacionPersona.legajo = nodoAux->informacionPersona.legajo;

        ptrArbol->Derecha = eliminarNodo(ptrArbol->Derecha, nodoAux->informacionPersona.legajo);
    }
    return ptrArbol;
}

nodoArbolPersona *tomarNodoDeMayorValor(nodoArbolPersona *ptrArbol) {

    nodoArbolPersona* mayorValor = NULL;

    if (ptrArbol != NULL) {

        mayorValor = tomarNodoDeMayorValor(ptrArbol->Derecha);

        if(!mayorValor) mayorValor = ptrArbol;
        }
    return mayorValor;
}

nodoArbolPersona *tomarNodoDeMenorValor(nodoArbolPersona *ptrArbol) {

    nodoArbolPersona *menorValor = NULL;

    if(ptrArbol != NULL) {

        menorValor = tomarNodoDeMenorValor(ptrArbol->Derecha);

        if(!menorValor) menorValor = ptrArbol;
        }
    return menorValor;
}

nodoArbolPersona *eliminarNodoPersona(nodoArbolPersona *ptrArbol, int legajoPersona) {

    if(ptrArbol != NULL){

        if(ptrArbol->informacionPersona.legajo == legajoPersona) {//Si el dato del arbol, es igual al dato que queremos eliminar, estamos en el nodo del arbol que va a ser eliminado.

            if(ptrArbol->Izquierda != NULL) {

                nodoArbolPersona *basura = tomarNodoDeMayorValor(ptrArbol->Izquierda);//Guardo el nodo que quiero eliminar para utilizar free()

                ptrArbol->Derecha = eliminarNodoPersona(ptrArbol->Derecha, basura->informacionPersona.legajo);

                free(basura);

                }else {

                    if (ptrArbol->Derecha){

                        nodoArbolPersona *basura = tomarNodoDeMenorValor(ptrArbol->Derecha); //Guardo el nodo que quiero eliminar para utilizar free()

                        ptrArbol->Derecha = eliminarNodoPersona(ptrArbol->Derecha, basura->informacionPersona.legajo);

                        free(basura);

                        }else {
                            free(ptrArbol);
                            ptrArbol = NULL;
                    }
                }
            }
        else{

            if (legajoPersona > ptrArbol->informacionPersona.legajo) ptrArbol->Derecha = eliminarNodo(ptrArbol->Derecha, legajoPersona);

            else ptrArbol->Izquierda = eliminarNodo(ptrArbol->Izquierda, legajoPersona);

            }
        }
    return ptrArbol;
}

Persona cargarUnaPersona() {

    int nombreValido = 1;
    int legajoValido = 1;
    int edadValida = 1;
    Persona unaPersona;

    printf("Ingrese su Nombre y Apellido --> ");
    fflush(stdin);
    gets(unaPersona.nombreYapellido);
    printf("\n");

    // Verificación del numero de Legajo
    do {
        printf("Ingrese su Nro de Legajo --> ");
        fflush(stdin);

        if(scanf("%i", &unaPersona.legajo) == 0) {
            printf("El Nro de Legajo ingresado no es valido. Vuelva a intentarlo... \n\n");
            legajoValido = 0;
        }
        printf("\n");
    }while(legajoValido == 0);

    // Verificación de la Edad
    do {
        printf("Ingrese su Edad --> ");
        fflush(stdin);

        if(scanf("%i", &unaPersona.edad) == 1) {

            if(unaPersona.edad <= 0 && unaPersona.edad >= 100) {
                printf("Edad no válida. Debe estar en el rango de 1 a 100.\n");
                edadValida = 0;
            }
        }else {
            printf("La edad ingresada no es valida. Vuelva a intentarlo... \n\n");
            edadValida = 0;
        }
        printf("\n");
    }while(edadValida == 0);

    return unaPersona;
}

nodoArbolPersona *insertarPersonasHasta(nodoArbolPersona *ptrArbol) {

    char eleccion = 's';
    Persona unaPersona;

    do {
        unaPersona = cargarUnaPersona();

        ptrArbol = insertarPersona(ptrArbol, unaPersona);

        printf("Pulse 's' para cargar otra Persona --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's' || eleccion == 'S');

    return ptrArbol;
}

void ejercicio4() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 4 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    printf("El recorrido que utilice fue In Orden, ya que va hasta el dato mas pequenio y lo muestra, para luego recorrer el siguiente dato \n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void ejercicio5() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 5 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    nodoSimple *ptrLista = inicializarLista();
    printf("DEBUG: Lista en NULL %p\n\n", ptrLista);

    ptrLista = copiarElArbolEnLista(ptrLista, ptrArbol);
    printf("Mostrando Lista \n\n");
    mostrarLista(ptrLista);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoSimple *inicializarLista() {
    return NULL;
}

nodoSimple *crearNodo(Persona unaPersona) {

    nodoSimple *nuevoNodo = (nodoSimple *) malloc(sizeof(nodoSimple));

    nuevoNodo->ptrSiguiente = NULL;
    nuevoNodo->informacionPersona = unaPersona;

    return nuevoNodo;
}

nodoSimple *buscarUltimo(nodoSimple *ptrLista) {

    nodoSimple *ptrSeguidor = ptrLista;

    if(ptrLista != NULL) while(ptrSeguidor->ptrSiguiente != NULL) ptrSeguidor = ptrSeguidor->ptrSiguiente;

    return ptrSeguidor;
}

nodoSimple *agregarAlFinal(nodoSimple *ptrLista, nodoSimple *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        nodoSimple *ptrUltimoNodo = buscarUltimo(ptrLista);
        ptrUltimoNodo->ptrSiguiente = nuevoNodo;
    }
    return ptrLista;
}

nodoSimple *copiarElArbolEnLista(nodoSimple *ptrLista, nodoArbolPersona *ptrArbol) {

    if(ptrArbol != NULL) {
        ptrLista = copiarElArbolEnLista(ptrLista, ptrArbol->Izquierda);
        ptrLista = agregarAlFinal(ptrLista, crearNodo(ptrArbol->informacionPersona));
        ptrLista = copiarElArbolEnLista(ptrLista, ptrArbol->Derecha);
    }
        return ptrLista;
}

void mostrarLista(nodoSimple *ptrLista) {

    if(ptrLista != NULL) {
        mostrarPersona(ptrLista->informacionPersona);
        mostrarLista(ptrLista->ptrSiguiente);
    }
}

void ejercicio6() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 6 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    nodoArbolPersona *aux = buscarPersonaPorLegajo(ptrArbol, 1);

    if(aux != NULL) printf("El legajo se encuentra en el Arbol \n\n");
    else printf("El legajo no se encuentra en el Arbol \n\n");

    ptrArbol = eliminarNodoPersona(ptrArbol, 1);

    //Verificamos buscando en el arbol haber si eliminó el dato
    aux = buscarPersonaPorLegajo(ptrArbol, 1);

    if(aux != NULL) printf("El legajo se encuentra en el Arbol \n\n");
    else printf("El legajo no se encuentra en el Arbol \n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoArbolPersona *buscarPersonaPorLegajo(nodoArbolPersona *ptrArbol, int legajo) {

    nodoArbolPersona *auxArbol = NULL;

    if(ptrArbol != NULL) {

        if(ptrArbol->informacionPersona.legajo == legajo) auxArbol = ptrArbol;

        else {
            if(legajo < ptrArbol->informacionPersona.legajo) auxArbol = buscarPersonaPorLegajo(ptrArbol->Izquierda, legajo);

            else auxArbol = buscarPersonaPorLegajo(ptrArbol->Derecha, legajo);
        }
    }
    return auxArbol;
}


void ejercicio7() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 7 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    nodoArbolPersona *flagEncontrarNombre = buscarPersonaPorNombre(ptrArbol, "Rocio Ortiz");

    if(flagEncontrarNombre != NULL) printf("Se encuentra ese nombre registrado \n\n");

    else printf("No se encuentra ese nombre registrado \n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoArbolPersona *buscarPersonaPorNombre(nodoArbolPersona *ptrArbol, char nombrePersona[]) {

    //Lo inicializo en NULL, dando por centado que no lo encontró
    nodoArbolPersona *nodoAux = NULL;

    if(ptrArbol != NULL){

        if(strcmp(ptrArbol->informacionPersona.nombreYapellido, nombrePersona) == 0) nodoAux = ptrArbol;

        else {

            if(strcmp(ptrArbol->informacionPersona.nombreYapellido, nombrePersona) == 0) nodoAux = buscarPersonaPorNombre(ptrArbol->Izquierda, nombrePersona);

            else nodoAux = buscarPersonaPorNombre(ptrArbol->Derecha, nombrePersona);
        }
    }
    return nodoAux;
}

void ejercicio8() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 8 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    int altura = calcularAlturaDeArbol(ptrArbol);
    printf("La altura del arbol es: %i \n\n", altura);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularAlturaDeArbol(nodoArbolPersona *ptrArbol) {

    int contadorIzq = 0;
    int contadorDer = 0;
    int nivel = 0;

    if(ptrArbol != NULL) {
        contadorIzq = calcularAlturaDeArbol(ptrArbol->Izquierda);
        contadorIzq++;
        contadorDer = calcularAlturaDeArbol(ptrArbol->Derecha);
        contadorDer++;

        if(contadorDer > contadorIzq) nivel = contadorDer;
        else nivel = contadorIzq;
    }
    return nivel;
}

void ejercicio9() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 9 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    int cantidadNodos = calcularCantidadNodosArbol(ptrArbol);

    printf("Nodos del Arbol: %i \n\n", cantidadNodos);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularCantidadNodosArbol(nodoArbolPersona *ptrArbol) {

    int nodosIzquierda = 0;
    int nodosDerecha = 0;

    if(ptrArbol  == NULL) return nodosDerecha + nodosIzquierda;

    else {
        nodosIzquierda = calcularCantidadNodosArbol(ptrArbol->Izquierda);
        nodosDerecha = calcularCantidadNodosArbol(ptrArbol->Derecha);

        return nodosIzquierda + nodosDerecha + 1;
    }
}

void ejercicio10() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 10 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    int cantidadNodos = calcularCantidadNodosArbol(ptrArbol);

    printf("Nodos del Arbol: %i \n\n", cantidadNodos);

    int cantidadHojas = calcularCantidadHojasDelArbol(ptrArbol);

    printf("Hojas del Arbol: %i \n\n", cantidadHojas);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularCantidadHojasDelArbol(nodoArbolPersona *ptrArbol) {

    int contadorHojas = 0;

    if(ptrArbol) {

        if((ptrArbol->Izquierda) == NULL && (ptrArbol->Derecha == NULL)) contadorHojas++;

        contadorHojas = contadorHojas + calcularCantidadHojasDelArbol(ptrArbol->Izquierda);
        contadorHojas = contadorHojas + calcularCantidadHojasDelArbol(ptrArbol->Derecha);
    }
    return contadorHojas;
}

void ejercicio11() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 11 \n\n");

    nodoArbolPersona *ptrArbol = inicializarArbolPersona();
    printf("DEBUG: Arbol en NULL %p\n\n", ptrArbol);

    ptrArbol = insertarPersonasHasta(ptrArbol);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    int cantidadNodos = calcularCantidadNodosArbol(ptrArbol);

    printf("Nodos del Arbol: %i \n\n", cantidadNodos);

    int cantidadHojas = calcularCantidadHojasDelArbol(ptrArbol);

    printf("Hojas del Arbol: %i \n\n", cantidadHojas);

    ptrArbol = borrarNodo(ptrArbol, 1);

    printf("In Orden \n");
    mostrarInOrden(ptrArbol);
    printf("\n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}


nodoArbolPersona *encontrarMin(nodoArbolPersona *ptrArbol) {

    while (ptrArbol->Izquierda != NULL)  ptrArbol = ptrArbol->Izquierda;

    return ptrArbol;
}

nodoArbolPersona *borrarNodo(nodoArbolPersona *ptrArbol, int legajo) {

    if(ptrArbol == NULL) return NULL;

    ///Buscar el nodo que se desea eliminar en el subárbol izquierdo o derecho
    if(legajo < ptrArbol->informacionPersona.legajo) ptrArbol->Izquierda = eliminarNodo(ptrArbol->Izquierda, legajo);

    else if(legajo > ptrArbol->informacionPersona.legajo)  ptrArbol->Derecha = eliminarNodo(ptrArbol->Derecha, legajo);

    else{
        ///El nodo a eliminar ha sido encontrado (NO FUE NI MENOR NI MAYOR)

        ///Caso 1: Nodo sin hijos o un solo hijo (los mas sencillos)
        if (ptrArbol->Izquierda == NULL){

            nodoArbolPersona *nodoAuxiliar = ptrArbol->Derecha;
            free(ptrArbol);
            return nodoAuxiliar;
        }

        else if (ptrArbol->Derecha == NULL){

            nodoArbolPersona *nodoAuxiliar = ptrArbol->Izquierda;
            free(ptrArbol);
            return nodoAuxiliar;
        }

        ///Caso 2: Nodo con dos hijos
        ///Encontrar el sucesor inmediato (nodo más a la izquierda en el subárbol derecho)
        nodoArbolPersona *nodoAuxiliar = encontrarMin(ptrArbol->Derecha);///Función complementaria...

        ///Copiar el valor del sucesor inmediato al nodo actual
        ptrArbol->informacionPersona.legajo = nodoAuxiliar->informacionPersona.legajo;

        ///Eliminar el sucesor inmediato
        ptrArbol->Derecha = eliminarNodo(ptrArbol->Derecha, nodoAuxiliar->informacionPersona.legajo);
    }
    return ptrArbol;
}



