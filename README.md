# Algoritmos y Estructuras de Datos
# Segundo Parcial A˜no 2024 Mayo 2024

## Conteo y ordenamiento de palabras

  Una forma simple de comprimir un archivo de texto es reemplazar cada
palabra por un c´odigo binario que la represente. Por ejemplo, la palabra casa
se reemplaza por el binario 1001 que ocupa 4 bit en lugar de 4 bytes. Para
que la compresi´on sea efectiva, se debe reemplazar la palabra m´as repetida por
un c´odigo m´ınimo, y as´ı en forma creciente en el tama˜no de c´odigo hasta la
palabra menos repetida. Para ello es necesario contar cuantas veces se repite
cada palabra en el texto.

  La primera parte de la tarea consiste en contar cuantas veces se repite cada
palabra. Para ello deber´a leer un archivo de texto de al menos 1000 palabras
con al menos 200 palabras distintas e identificar cuales son las palabras que lo
forman y cuantas veces est´an repetidas cada una de ellas. El archivo es de libre
elecci´on.

  Para contar las palabras deber´a disponer de un nodo para cada palabra
distinta del archivo que sea simult´aneamente un nodo de lista y un nodo de
´arbol binario de b´usqueda (abb), es decir, que contenga tres punteros, uno al
siguiente nodo de la lista y dos para el abb, generando una estructura combinada
de lista con abb. Adem´as, el nodo tendr´a como valor a la palabra y al contador
de repeticiones que esta tenga. El criterio de b´usqueda del abb es alfab´etico
para poder buscar cada palabra le´ıda desde el archivo. Si la palabra no existe,
se crea el nodo respectivo y se agrega en el abb y se enlaza en la lista de
palabras al comienzo de esta. Si la palabra ya existe, se suma uno a la cantidad
de repeticiones que esta tiene. Al finalizar la carga, generar e imprimir un lista
de palabras ordenadas alfab´eticamente haciendo un recorrido inorden del abb.
Preservar esta lista para un uso posterior.

  La segunda parte es del ordenamiento de las palabras y sus repeticiones.
Luego de construido el abb, deber´a reordenar los nodos de la lista por la cantidad de repeticiones en forma decreciente utilizando el algoritmo de selecci´on y
generar un listado de las palabras ordenado de esta manera.

  Para realizar el ordenamiento tendr´a que utilizar swaps de los datos de los
nodos de la lista original sin cambiar los punteros que enlazan estos y para ello
deber´a usar accesos posicionales sobre los nodos de la lista. En otras palabras,
para el ordenamiento, utilizar swap(i,j) sobre los elementos de la lista, donde i
1
y j son las posiciones del nodo i-´esimo y j-´esimo de la lista intercambiando los
datos de los nodos i y j, similar a como si fuera usando un arreglo.
Para que el acceso al i-´esimo valor de la lista no sea secuencial, deber´a
construir un ´arbol posicional binario semi-completo cuyas hojas sean punteros
a los nodos de la lista. Este ´arbol no contiene los datos de las palabras, solo
permite acceder en orden logar´ıtmico a la j-´esima posici´on de la lista y trabaja
de la siguiente forma:

  Para acceder a la posici´on k, deber´a restar 1 a k y transformarlo es su
equivalente n´umero binario. Ej: si quiero ir a la posici´on 13, debo usar el
binario de 12, 1100.

el 0 y el 1 del n´umero binario indican si debo tomar la rama izquierda (0)
o derecha (1) del ´arbol, leyendo el binario de izquierda a derecha.

  En el caso de 1100, la navegaci´on es, partiendo de la ra´ız del ´arbol posicional,
derecha, derecha, izquierda, izquierda.

  Es decir que las posiciones 1 a n de los elementos de la lista se deben mapear
de 0 a n-1 en el ´arbol posicional. La altura del ´arbol posicional deber´a corresponderse con la menor potencia de 2 que sea mayor al n´umero de palabras. Ej:
Si tengo 300 palabras, el binario deber´a ser de 9 d´ıgitos, ya que 2 a la 8 es 256
y 2 a la 9 es 512.

  Como tercera parte, debido a que el ordenamiento por n´umero de repeticiones altera el orden alfab´etico de cada palabra, deber´a volver a ordenar alfab´eticamente la lista de nodos, en esta ocasi´on por medio del algoritmo Quick-sort,
siguiendo las mismas restricciones del caso anterior, es decir, accediendo a la
lista utilizando el ´arbol posicional e intercambiando los contenidos de los nodos,
sin cambiar el enlace de los punteros. En cada ordenamiento (selecci´on y quicksort) haga un conteo de la cantidad de comparaciones que ambos algoritmos
realizan para poder validar el orden de complejidad de ambos.
Como prueba de correctitud del ordenamiento, deber´a controlar que el resultado de este ordenamiento debe coincidir con el listado generado en la primera
parte del proyecto, es decir ambos resultados deben tener la misma cantidad de
palabras y estas figurar en el mismo orden.

## Tip
  Considere un tipo de nodo de datos que solo tenga la palabra y la repetici´on
y otro tipo de nodo para el ´arbol y la lista que en lugar de los datos tenga un
puntero al nodo de datos. Esto a los fines de facilitar el swap de los datos, ya
que solo intercambia punteros en lugar de datos.

  Utilice los algoritmos dados en clase, modificandolos para implementar la
soluci´on.
Bonus
Se considerar´a como bonus en la evaluaci´on que en lugar del abb se utilice
un AVL balanceado
