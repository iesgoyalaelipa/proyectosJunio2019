#####################################################
23/04/2019

Primera subida del proyecto en formato zip comprimido.

Contiene la estructura del proyecto en Nodejs con:
	Los módulos de Node a utilizar y dependencias: jQuery, Popper, Pug, Bootstrap, etc...
	Esqueletos de las vistas de:
		Sala de cine y asientos
		Login
		Principal con menú
		
	En desarrollo... 
		Creación de la BBDD
		Hacer el login funcional
	
	En adelante...
		Proceso de implementación de funcionalidad en código Nodejs una vez hecha la BBDD
		

#####################################################
07/05/2019

Segunda subida del proyecto en formato zip comprimido

Contiene la estructura del proyecto en Nodejs con:
	Nuevos módulos implementados de NPM libreria de Node, como el serve-favicon y MySQL
	Implementadas nuevas vistas dinámicas actualizadas
		Inicio
		Cartelera
		Menú
		
	Implementada 
		La BBDD con MySQL
		La conexión a BBDD - Login
	
	En desarrollo
		Implementación de la variable session para comprobar si está conectado y poder reservar asientos
		Implementación de la funcionalidad con hilos de la reserva de asientos
		Seguir puliendo las vistas

#####################################################
22/05/2019

Tercera subida del proyecto en formato zip/7z comprimido

Conntiene la estructura del proyecto Nodejs con:
	Nuevos módulos implementados: 
		express-session
		express-flash
		sessionStore
		
	Implementada la vista del registro
		Es funcional, registra en BBDD de forma cifrada la password
		
	Loguea correctamente y aparece en el menú la opción de Logout, la cual también es funcional
	
	En desarrollo
		Implementación de la selección de asientos para su reserva
		Parte del admin: Creación de salas e implementación de películas