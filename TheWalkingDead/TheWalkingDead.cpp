// TheWalkingDead.cpp 
//



/*
Llama a la funci�n srand(time(nullptr)) para asignar una semilla que genere
n�meros aleatorios seg�n el tiempo cada vez que se ejecuta el programa.
b. Declara un objeto player de tipo Player.
c. Declara un array est�tico zombies que alberga 10 objetos de tipo Zombie. Para evitar
el uso de literales m�gicos, es recomendable definir una constante que almacene el
n�mero de zombies en juego.
d. Declara una variable zombiesAreAlive de tipo bool que sirva para detectar si el jugador
ha acabado con todos los zombies.
e. Define un bucle do while con 2 condiciones: que el jugador siga vivo y que haya como
m�nimo un zombie en pie. El contenido de este bucle debe asignar false a
zombiesAreAlive y debe presentar un for que recorra el array de zombies 

y, seg�n si
cada zombie est� vivo o no, se llame a las funciones de ataque tanto del jugador como
del zombie y se asigne true a la variable zombiesAreAlive. Adem�s, es recomendable
mostrar para cada iteraci�n el contenido de los atributos de cada objeto en juego.
f. Seg�n el valor resultante de la variable zombiesAreAlive, se muestra por consola un
mensaje de si ha vencido el jugador o los zombies.
*/