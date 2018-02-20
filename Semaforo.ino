int tiempo = 1000; //variable para controlar la velocidad de encendido y apagado de los LED's
int boton = 0; //Variable para guardar el estado del boton

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT); // Salida del led verde de los coches
  pinMode(9, OUTPUT); // Salida del led amarillo de los coches
  pinMode(10, OUTPUT); // Salida del led rojo de los coches
  pinMode(11, OUTPUT); // Salida del led verde de los peatones
  pinMode(12, OUTPUT); // Salida del led rojo de los peatones
  pinMode(7, INPUT); //Entrada del boton
}

void parpadeo(int pin){ //método para hacer parpadear un LED (especificado en la variable pin).
  for(int i = 0; i < 3; i++){ //ciclo para hacer que el LED parpadee 3 veces
    digitalWrite(pin, LOW); //Apaga el LED pin
    delay(tiempo/3);  //realiza una pausa
    digitalWrite(pin, HIGH); //Enciende el LED pin    
    delay(tiempo/3);  //realiza una pausa
  }
}

void controlaBoton(){ //método que realiza la acción del boton al ser presionado.
    digitalWrite(8, LOW); //apaga el LED verde de los coches
    digitalWrite(9, LOW); //apaga el LED amarillo de los coches
    digitalWrite(10, HIGH); //enciende el LED rojo de los coches
    digitalWrite(11, HIGH); //enciende el LED verde de los peatones
    digitalWrite(12, LOW); //apaga el LED rojo de los peatones
    delay(tiempo); //realiza una pausa
    parpadeo(11); //llamada al método de parpadeo
}

// the loop function runs over and over again forever
void loop() {
    tiempo = analogRead(A0); //Se lee el valor del potenciometro y obtiene la velocidad del semáforo
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton();  //se manda a llamar al método controlaBoton().
    }
    digitalWrite(10, LOW); //Después de evaluar el IF, 
    digitalWrite(11, LOW); //apaga los pines 10 y 11 (LED verde de peatones y LED rojo de coches)
    digitalWrite(8, HIGH); //Enciende el pin 8 (LED verde de los coches)
    digitalWrite(12, HIGH); //Al mismo tiempo, el pin 12 se enciende (el LED rojo de los peatones)
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    delay(tiempo*2); //se hace una pausa para mantener los LED's encendidos.
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    tiempo = analogRead(A0); //Se lee el valor del potenciometro y obtiene la velocidad del semáforo
    digitalWrite(8, LOW); //Apaga el pin 8 (LED verde de los coches)
    parpadeo(8); //Se manda a llamar el método parpadeo() sobre el pin 8 (LED verde de los coches).
    digitalWrite(8, LOW); //Apaga el pin 8 (LED verde de los coches)
    digitalWrite(9, HIGH); //Enciende el pin 9 (LED amarillo de los coches)
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    delay(tiempo); //se hace una pausa para mantener los LED's encendidos.
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    tiempo = analogRead(A0); //Se lee el valor del potenciometro y obtiene la velocidad del semáforo
    digitalWrite(12, LOW);//Apaga el pin 12 (LED rojo de los peatones)
    digitalWrite(11, HIGH); //Enciende el pin 11 (LED verde de los peatones)
    digitalWrite(9, LOW); //Apaga el pin 9 (LED amarillo de los coches)
    digitalWrite(10, HIGH); //Enciene el pin 10 (LED rojo de los coches)
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    delay(tiempo); //se hace una pausa para mantener los LED's encendidos.
    boton = digitalRead(7); //Se lee el estado del boton
    if (boton == HIGH){ //Si el botón ha sido presionado:
      controlaBoton(); //se manda a llamar al método controlaBoton().
    }
    tiempo = analogRead(A0); //Se lee el estado del boton.
    digitalWrite(11, LOW); //Apaga el pin 11 (LED verde de los peatones)
    parpadeo(11); //Se manda a llamar el método parpadeo() sobre el pin 11 (LED verde de los peatones).
}
