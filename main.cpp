#include <iostream>
#include "clases.h"
int main() {
    Menuu Principal;
    cout << "Bienvenido. ¿Qué opción quisieras emplear?" << endl;
    Principal.Mostrar();

    return 0;
}
//Posibles mejoras

/*
En la opcion 2 de filtros deseados,
  podríamos poner como sub opciones las opciones 3 y 4, porque parecen ser modificaciones de la original

Tambien, podemos ponerle clears() a la consola, para que no se llene de muchas cosas.

Cambiar el void de FiltroParcial() por un tipo de retorno Salida

La mas importante creo, por conveniencia, decidí quitarle a vector<Filtro*> Filtros el "*".
*/

//Cosas inesperadas

/*

Imprime 2 veces el print de archivos en Filtrar(), hay algo medio raro en el for.

*/

//Limitaciones

/*
Estaba pensando en hacer que sea funcional para todo tipo de strings (mayusculas o minusculas), empleando un for que vuelva cada string del vector archivos en una lowercase string. a su vez, una que vuelva lowercase el parametro que busca el usuario.

¿qué les parece?
*/