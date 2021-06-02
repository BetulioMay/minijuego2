# Informe. Primera Parte

**Alumno: ** César Alberto Mayora Suárez

**DNI:** 

### Clase ConjuntoParticulas

La primera parte del proyecto se quería implementar un clase dónde se manipularán varias partículas contenidas en lo que será un conjunto de partículas.

En la implementación de ésta clase se prentendía la creación de un conjunto de objetos de la clase Partícula, con su respectiva capacidad (capacidad) y número de partículas (size). 

En los métodos de la clase se trata de cubrir cualquier manipulación de estas partículas. En general no hubo ningún problema, aunque hubo algunas dificultades en especial con la gestión de memoria dinámica en el método privado "resizeConjunto" donde se redimensiona en conjunto.

Para los métodos de consulta o de modificación de del conjunto hago un checkeo de que la variable "posicion" esta correctamente definida dentro de los límites del conjunto, en caso contrario, no hace la operación. Aunque este checkeo es simple, he decidico hacer un función que haga esto mismo; sobre todo lo hago para no repetir código además que mejora la legibilidad del mismo. Esta función será privada ya que solo deberá su uso a otros métodos de la clase.

En la implementación de otros métodos como "reservaMemoria" y "liberaMemoria" se pasa como parámetro "Particula * &set", aunque es verdad que, como método de la clase, no es necesario pasar este parámetro, pero debido a que se también se manipulan conjuntos, como en la redimensión del conjunto, que no son del objeto en cuestión; se declara de esta manera para que sea más "general".

Finalmente, en el método *Mostrar()* tuve un poco de libertad para hacer un formato a mi gusto, debido a que este método lo hice antes de la publicación de las instrucciones de entrega que muestran implicitamente como sería el formato, simplemente muestro la capacidad y la cantidad de elementos utiles del conjunto y para cada partícula de conjunto llamo a su método *ToString()*.

En cada Test se podrá comprobar que *valgrind* no informa ningún error de fuga de memoria o mala gestión de la misma.

A *grosso modo* no hubo más dificultad de lo mencionado, pasando todos los test del fichero *pruebasConjunto.cpp*.

| TEST | COMPILA | EJECUTA | VALGRIND |
| ---- | ------- | ------- | -------- |
| t1   | SÍ      | SÍ      | BIEN     |
| t2   | SÍ      | SÍ      | BIEN     |
| t3   | SÍ      | SÍ      | BIEN     |
| t4   | SÍ      | SÍ      | BIEN     |
| t5   | SÍ      | SÍ      | BIEN     |

![](/home/cesar/Desktop/minijuego.jpg)

## Minijuego

Para la implementación del minijuego estudié los ejemplos dados por el profesorado en la página de PRADO, de manera que tenga una visión y guía breve y básica de las funciones de raylib como *InitWindow* o *DrawCircle*.

Para hacer el minijuego, se crea un fichero main con el nombre *capturaOvni.cpp* donde se implementará el *update* y el *draw* del minijuego mediante un bucle *while* que se detendrá cuando se presioné ESC o se cierre la ventana.

Se podrá ver en el fichero que creo dos variable *ticks* y *time* estas variables se usarán para medir el tiempo en segundos mientras se juega el minijuego. Debido a que el juego correrá a 60 FPS, pues *ticks* se incrementará en 1 en módulo 60, por tanto, *time* se incrementará en 1 cuando ticks sea igual a 0, así en el juego se contará en segundos el tiempo transcurrido.

Cuando termina el juego, es decir, cuando no hayan mas particulas se dejarán de actualizar los datos del conjunto y de la partícula base y se dibujará una pantalla en donde se mostrará el tiempo total que se ha jugado.

Para el minijuego pretendía crear un método *update()* para la clase ConjuntoPartícula y en método *main* en cada *tick* llamara el método, de manera que se modularice más el minijuego. Al igual que un método *draw()* que haga las mismas funciones que hay en el *main()* pero que de esta manera quede más modularizado.
Además que deja pie a que en el "canvas" se pinten mas cosas y no solo juego base, ya que el draw sería un método propio del ConjuntoPartículas, por lo tanto, si quisieramos agregar más objetos, estos tendrán sus propios métodos *update* y *draw* y podremos elegir cuales se actualizan o dibujan y cuales no.

Más allá de lo dicho no hubo problema en la implementación del minijuego. Durante el desarrollo del mismo hice un control de versiones del proyecto con *git*, aún asi hubo dificultades con esto (errores en la autentificación, errores al hacer push al remoto, etc.) y tuve que eliminar el repositorio y hacerlo de nuevo, es por esto que se puede ver que no hubieron muchos *"commits"*.
De igual manera, puede ver el minijuego en el repositorio de GitHub aquí -> https://github.com/BetulioMay/minijuego1

**Preguntas acerca de la implementación del juego:**

- La instalación de *raylib* me ha resultado: fácil.
- La programación de videojuego me ha resultado: fácil.
- Estoy conforme con el resultado final.
- Sería interesante guardar los datos como el tiempo transcurrido como un *score* del jugador. Se podría implementar una "base de datos" muy primitiva en un fichero de texto; y mediante la escritura de ficheros que provee C++ se podría actualizar el tiempo trancurrido si este es menor al que se lee en el fichero de texto. No me resultaría difícil implementarlo y se podría mejorar y desarrollar la idea.


