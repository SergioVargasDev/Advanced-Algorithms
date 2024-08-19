// A01173896 Sofia Schneider Jimenez
// A00837196 Sergio Tomas Vargas Villarreal

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


void cambioDinamico(int cambio, const vector<int>& denominaciones, vector<int>& res){
    // recibe la cantidad de dinero que se debe devolver como cambio, y el  vector
    // de las diferentes denominaciones de monedas, va a retornar un vector 
    // en este vector habrá la cantidad minima de cada moneda que se debe dar cambio

    int N = denominaciones.size(); // número total de denomincaciones disponibles
    vector<int> dp(cambio +1, INT_MAX); //aqui se va a almacenar el numero minimo de monedas
    // inicializado con int_max es una macro que indica el limite máximo al cual puede almacenar un entero
    // inicialmente pues no se ha encontrado una solución

    vector<int> utilizadas(cambio +1,-1); //vector que se va usar para saber
    //qué denominación de moneda se utilizó [para obtener l minimo numero de monedas para cada cantidad

    dp[0] = 0; //caso base. 0 monedas devuelven cambio de 0

    for (int i =1; i<= cambio; i++){ //recorre todas las posibles cantidades de cambio desde 1 hasta cambio
        for(int j = 0; j <N; j++){ // recorre todas las denominaciones de monedas para buscar la
        //menor combinacion de monedas que sume a la cantidad de i

            if (denominaciones[j] <= i && dp[i-denominaciones[j]] != INT_MAX){ //si la denomincacion es menor o igual a la cantidad de cambio actual

                if (dp[i] > dp [i-denominaciones[j]]+1){ // verificar si usando la moneda en [j]
                    // se puede reducir el numero total de monedas necesarias para tener i

                    dp[i]= dp[i - denominaciones[j]] +1; // si se encuentra una mejor solución
                    // actualizamos el nuevo valor minimo de monedas necesario
                    utilizadas[i] = j; //la denominación j fue usada para llegar a esa solucion
                }
            }
        }
    }


    int total = cambio; //ir checando la cantidad de cambio que resta mientras calcula

    while (total > 0 && utilizadas[total] != -1){ // reconstruir la cantidad de monedas de cada denominacion
        res[utilizadas[total]]++; //incrementa el contador de monedas utilizadas de la denominacion correspondiente
        total -= denominaciones[utilizadas[total]]; //resta el valor de la denominación usada del total cambio restante

    }
}

// Función para calcular el cambio utilizando el algoritmo avaro
void cambioAvaro(int cambio, const vector<int>& denominaciones, vector<int>& res) {
    int n = denominaciones.size();  // Obtiene el número de denominaciones de monedas

    // Itera sobre las monedas comenzando desde la de mayor denominación
    for (int i = n - 1; i >= 0 && cambio > 0; --i) {
        // Mientras la moneda actual puede ser usada para el cambio
        while (denominaciones[i] <= cambio) {
            res[i]++;  // Incrementa la cantidad de la moneda utilizada
            cambio -= denominaciones[i];  // Reduce el valor del cambio pendiente
        }
    }
}

int main(){
    //recibe numero entero N

    int N;
    cout << "Ingrese el número de denominaciones de monedas: " ;
    cin >> N;

    vector<int> denominaciones(N);
    cout << "Ingrese las denominaciones de las monedas, una por línea: " << endl;
    for (int i = 0; i <N ;i++){
        cin >> denominaciones[i];
    }

    sort(denominaciones.begin(),denominaciones.end());

    int p;
    cout << "Ingrese el precio del producto: " ;
    cin >> p;

    int q;
    cout << "Ingrese la cantidad pagada: ";
    cin >> q;

    int cambio = q - p;

    if (q < p){
        cout << "\n\nFalta dinero para pagar ese producto\n\n" << endl;
        return 0;
    }

    if (cambio == 0){
        cout << "\n\nNo hay cambio por dar\n\n" << endl;
        return 0;
    }

    // Vectores para almacenar el resultado del cambio utilizando programación dinámica y algoritmo avaro
    vector<int> resultadoDinamico(N, 0);
    vector<int> resultadoAvaro(N, 0);

    // Calcula el cambio utilizando programación dinámica
    cambioDinamico(cambio, denominaciones, resultadoDinamico);

    // Calcula el cambio utilizando el algoritmo avaro
    cambioAvaro(cambio, denominaciones, resultadoAvaro);

    cout << "\n\nUtilizando programación dinámica" << endl;
        for (int i = N - 1; i >= 0; --i) {
        cout << resultadoDinamico[i] << " moneda(s) de " << denominaciones[i] <<  endl;
    }
    cout << endl;

    cout << "\n\nUtilizando algoritmo avaro" << endl;
        for (int i = N - 1; i >= 0; --i) {
        cout << resultadoAvaro[i] << " moneda(s) de " << denominaciones[i] <<  endl;
    }
    cout << endl;

    return 0;

}

//* hola

