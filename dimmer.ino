/*ISPC Materia TST cohorte 2022 Aula 1
Fecha de esta version dimmer 11-07-2022
Ejercicio programa para prueba en proteus simulacion
Caracteristicas tecnicas     */
/************************************************************************/
int numero = 0;         // variable para saber cuantas veces pulsaron el boton
int Sube_velocidad = 8; // pin entrada pulsador para subir la velocidad
int Baja_velocidad = 7; // pin entrada pulsador para bajar la velocidad
int Motor = 9;          // pin salida para manejar el motor por PWM
/************************************************************************/
void setup()
{
    Serial.begin(9600);                    // enciendo el puerto serie
    pinMode(Sube_velocidad, INPUT_PULLUP); // configuro el pin de entrada
    pinMode(Baja_velocidad, INPUT_PULLUP); // configuro el pin de entrada
    pinMode(Motor, OUTPUT);                // configuro el pin de salida
}
/************************************************************************/


/************************************************************************/
void loop()
{
    if (digitalRead(Sube_velocidad) == 0)
    {                               // si el boton esta presionado
        if (numero < 3)             // si el numero es menor a 3
        {                           // si es la primera vez que presiono el boton
            numero++;               // aumento el contador
            Serial.println("Boton sube presionado"); // muestro en el puerto serie que presiono el boton
            ajuste_velocidad();     // llamo a la funcion para ajustar la velocidad
        }
    }

    if (digitalRead(Baja_velocidad) == 0)
    {                               // si el boton esta presionado
        if (numero > 0)             // si el numero es mayor a 0
        {                           // si el contador es mayor a 0
            numero--;               // aumento el contador
            Serial.println("Boton baja presionado"); // imprimo el mensaje
            ajuste_velocidad();     // llamo a la funcion para ajustar la velocidad
        }
    }
    delay(800); // espero 800 ms para que no se repita el mensaje
}
/************************************************************************/


/************************************************************************/
void ajuste_velocidad()
{ // funcion para ajustar la velocidad

    switch (numero)
    {
    case 1: // si el contador es 1
        Serial.println("Velocidad baja");
        analogWrite(Motor, 85); // ajusto la velocidad al valor de 85 un 33.3%
        break;
    case 2: // si el contador es 2
        Serial.println("Velocidad media");
        analogWrite(Motor, 170); // ajusto la velocidad al valor de 170 66.6 %
        break;
    case 3: // si el contador es 3
        Serial.println("Velocidad alta");
        analogWrite(Motor, 255); // ajusto la velocidad al valor de 255 un 100%
        break;
    case 0: // si el contador es 0
        Serial.println("Apagado");
        analogWrite(Motor, 0);
        break;
    default:
        Serial.println("error");
        break;
    }
}
/************************************************************************/
