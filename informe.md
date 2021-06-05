# Informe. Segunda parte.

**Alumno: ** César Alberto Mayora Suárez

**DNI:** Y5430138J

### Clases Particula y ConjuntoParticulas

El desarrollo de la segunda parte para las clases 'Partícula' y 'ConjuntoPartículas' trataba la extensión de estas usando la sobrecarga de operadores aprendidas en clases de teoría. En general, no resultó en ningún problema para ambas clases, en los operadores '>>' y '<<' trataban del control de flujo de entrada y salida.

También añadimos un constructor nuevo para la clase *ConjuntoPartículas* usando la librería de C++ *<fstream>* para la manipulación de ficheros; en este caso solo usamos un fichero de lectura, por lo que usamos la flag ```ios:in``` para indicarle al compilador que lo queremos solo para lectura. El nombre del fichero se pasa como parámetro desde la línea de comandos al constructor como un tipo *C string*. 

En la lectura consideraremos el formato del fichero como válido, por tanto, podemos estar seguros que habrán tantas partículas como diga la primera línea del fichero, e.g. Si la primera línea dice 3, podemos estar seguros que el número de partículas del conjunto será 3. Es por esto que en la lectura itero tantas veces diga la primera línea, sin embargo, uso la condición en el bucle de la flag ```eof()``` para asegurarnos que llegamos al final del fichero. Las siguientes líneas del fichero son los datos de las partículas que se agregaran al conjunto mediante la sobrecarga del operador '>>'. Al finalizar, cerramos el fichero.

En esta extensión de las clases, me di cuenta que en algunas funciones existían *warnings* sobre funciones que no devolvían nada al finalizar ya sea por una posición mal definida. En la primera versión simplemente use un control condicional para validar la posición pero me daba cuenta habían funciones que podían recibir como parámetros vacíos. Por ejemplo, en la función *ObtienePartícula()* puede devolver un no devolver un objeto de la clase *Partícula*, por tanto, una función que hace uso de este método como *AgregaPartícula(p.ObtienePartícula(i))* puede correr el riesgo de recibir una partícula que no existe. Lo mejor que pude hacer es hacer uso de la función ```assert``` para corregir este problema, ya que como hemos visto puede resultar en un problema grave, es mejor finalizar la ejecución del programa si esto ocurre. La función ```assert``` de la librería *<assert>* de  C++  la podemos usar parra evitar este tipo de errores, es por esto que la uso también en los constructores, al ser públicos evitamos que el usuario introduzca por ejemplo una capacidad negativa. Este tipo de funciones resultan útiles a la hora de *debuggear* el programa pues en caso de error, la función saca por pantalla por qué se produjo el error.

Para esta parte dos, introduje dos nuevas funciones privadas a la clase *ConjuntoPartículas* que nos ayudarán y simplificarán la tarea de implementar los métodos de la clase:

- En primer lugar tenemos la función ```void dpCopia()```, que se entiende como *Deep Copy*. Esta función nos hará la tarea de hacer una copia de los datos miembros <u>no dinámicos</u> del Conjunto pasado por referencia constante. Esto evita el código repetido que tendríamos en el constructor de copia y en la sobrecarga del operador de asignación '='; nótese que hacen la misma tarea, copia los datos miembros de otro conjunto. Lo que si evita copiar es el vector dinámico *set*  ya que tendríamos un error de ejecución *double free*.
- En segundo lugar tenemos ```void MinMaxCoord()```, que nos hace la tarea de obtener las coordenadas de la partícula mas cercana al orígen y de la partícula más alejada. Esta función nos es de utilidad para implementar la función ```float Area()``` que nos devuelve el área del rectángulo descrito por estas partículas y que por característica propia de ellas, contendrán a todas las demás partículas del conjunto. Ésta función tiene el único objetivo de modularizar y mejorar la legibilidad del código.

Dicho lo anterior, no hubo ningún otro problema en la extensión de las clases, pasando todos los test y el Valgrind que gracias a las referencias de las transparencias de teoría no hubo dificultad en la sobrecarga de los operadores y en la lectura de ficheros.

### Minijuego. Ovnis 2.0

