#include <iostream>
#include <cmath>

using namespace std;


float determinante(float x1, float y1, float x2, float y2) {
    return x1 * y2 - y1 * x2;
}

// se verificar relación entre dos líneas
int relacionLineas(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    float dx1 = x2 - x1;
    float dy1 = y2 - y1;
    float dx2 = x4 - x3;
    float dy2 = y4 - y3;

    float det = determinante(dx1, dy1, dx2, dy2);

    if (det == 0) {
        return 0; // Líneas paralelas
    } else {
        // se verificar si se cruzan
        float t = determinante(x3 - x1, y3 - y1, dx2, dy2) / det;
        float s = determinante(x3 - x1, y3 - y1, dx1, dy1) / det;

        if (t >= 0 && t <= 1 && s >= 0 && s <= 1) {
            return 1; // Se cruzan
        } else {
            return -1; // No se cruzan
        }
    }
}

// Verificamos si líneas son perpendiculares
int relacionLineas(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool esPerpendicular) {
    float dx1 = x2 - x1;
    float dy1 = y2 - y1;
    float dx2 = x4 - x3;
    float dy2 = y4 - y3;

    float dotProduct = dx1 * dx2 + dy1 * dy2;

    if (dotProduct == 0) {
        return 1; // Líneas perpendiculares
    } else if (determinante(dx1, dy1, dx2, dy2) == 0) {
        return 0; // Líneas paralelas
    } else {
        return -1; // Se cruzan pero no son perpendiculares
    }
}


float calcularAngulo(float x1, float y1, float x2, float y2,
                     float x3, float y3, float x4, float y4,
                     bool enGrados = false) {
    float dx1 = x2 - x1;
    float dy1 = y2 - y1;
    float dx2 = x4 - x3;
    float dy2 = y4 - y3;

    float dotProduct = dx1 * dx2 + dy1 * dy2;
    float mag1 = sqrt(dx1 * dx1 + dy1 * dy1);
    float mag2 = sqrt(dx2 * dx2 + dy2 * dy2);

    float angulo = acos(dotProduct / (mag1 * mag2));

    if (enGrados) {
        angulo = angulo * (180.0 / M_PI);
    }

    return angulo;
}

// Función para realizar un proceso cualquiera
void doSomething() {
    cout << "I do something" << endl;
    static int contadorLlamadas = 0; // Variable estática para contar las llamadas
    contadorLlamadas++;
    cout << "La funcion DoSomething se ha llamado en un total de " << contadorLlamadas << " veces" << endl;
}

// Función que devuelve la cantidad de veces que se llamó a doSomething
int obtenerCantidadLlamadas() {
    extern int contadorLlamadas; // Accede a la variable estática en doSomething
    return contadorLlamadas;
}

int contadorLlamadas = 0;

int main() {
    int opcion;
    float x1, y1, x2, y2, x3, y3, x4, y4;

    do {
        cout << "Ingrese que funcion asignada desea ejecutar" << endl;
        cout << "1. Funcion que dados 2 pares de coordenadas, correspondientes al inicio y fin de dos lineas. Devuelve 1 si las lineas se cruzan, 0 si son paralelas y -1 si no se cruzan ni son paralelas." << endl;
        cout << "2. Sobrecargar de la funcion anterior para que devuelva 1 si las lineas son perpendiculares, 0 si son paralelas y -1 si se cruzan." << endl;
        cout << "3. Funcion que devuelve el valor de un angulo en el punto de cruce de dos lineas, por defecto el angulo lo da en radianes, pero puede cambiarse a grados." << endl;
        cout << "4. Dos funciones, una que realiza un proceso cualquiera, y otra que devuelve la cantidad de veces que se llamo a la primera funcion." << endl;
        cout << "0. Salir" << endl;
        cout << "opcion seleccionada: ";
        cin >> opcion;


        if (opcion == 1 || opcion == 2 || opcion == 3) {
            cout << "\nIngrese las coordenadas de las dos lineas:" << endl;
            cout << "\nCada numero separado por espacio, por ejemplo: 1 1" << endl;
            cout << "Linea 1 - Punto A (x1, y1): ";
            cin >> x1 >> y1;
            cout << "Linea 1 - Punto B (x2, y2): ";
            cin >> x2 >> y2;
            cout << "Linea 2 - Punto C (x3, y3): ";
            cin >> x3 >> y3;
            cout << "Linea 2 - Punto D (x4, y4): ";
            cin >> x4 >> y4;
        }

        switch (opcion) {
            case 1: {
                int resultado = relacionLineas(x1, y1, x2, y2, x3, y3, x4, y4);
                cout << resultado << endl;
                break;
            }
            case 2: {
                int resultado = relacionLineas(x1, y1, x2, y2, x3, y3, x4, y4, true);
                cout << resultado << endl;
                break;
            }
            case 3: {
                float anguloRadianes = calcularAngulo(x1, y1, x2, y2, x3, y3, x4, y4);
                float anguloGrados = calcularAngulo(x1, y1, x2, y2, x3, y3, x4, y4, true);
                cout << "Angulo en radianes: " << anguloRadianes << endl;
                cout << "Angulo convertido a grados: " << anguloGrados << endl;
                break;
            }
                case 4: {
                
                doSomething(); // Realiza un proceso cualquiera
                break;
            }
            case 0:
                cout << "Cerrando programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);

    return 0;
}
