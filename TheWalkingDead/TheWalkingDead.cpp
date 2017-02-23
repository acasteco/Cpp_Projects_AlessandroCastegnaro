// TheWalkingDead.cpp 
//



/*
Llama a la función srand(time(nullptr)) para asignar una semilla que genere
números aleatorios según el tiempo cada vez que se ejecuta el programa.
b. Declara un objeto player de tipo Player.
c. Declara un array estático zombies que alberga 10 objetos de tipo Zombie. Para evitar
el uso de literales mágicos, es recomendable definir una constante que almacene el
número de zombies en juego.
d. Declara una variable zombiesAreAlive de tipo bool que sirva para detectar si el jugador
ha acabado con todos los zombies.
e. Define un bucle do while con 2 condiciones: que el jugador siga vivo y que haya como
mínimo un zombie en pie. El contenido de este bucle debe asignar false a
zombiesAreAlive y debe presentar un for que recorra el array de zombies 

y, según si
cada zombie está vivo o no, se llame a las funciones de ataque tanto del jugador como
del zombie y se asigne true a la variable zombiesAreAlive. Además, es recomendable
mostrar para cada iteración el contenido de los atributos de cada objeto en juego.
f. Según el valor resultante de la variable zombiesAreAlive, se muestra por consola un
mensaje de si ha vencido el jugador o los zombies.
*/