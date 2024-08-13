
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//*sopapa

void merge(vector<double> &list, int left, int mid, int right){
    //crear lista de lado izquierdo
    vector<double> leftList;
    for (int i = left; i <= mid; i++){
        //insertar elementos en la lista izquierda
        leftList.push_back(list[i]);
    }

    //crear lsta derecho
    vector<double> rightList;
    for (int j = mid+1; j <= right; j++){
        rightList.push_back(list[j]);
    }

    //crear inidce auxiliar igual a left
    int auxIndex = left;
    //creamos dos indices auxiliares uno para cada lista
    int leftIndex = 0;
    int rightIndex = 0;

    //iteramos mientras haya elementos por comparar en ambas listsa
    while ((leftIndex < leftList.size()) && (rightIndex < rightList.size())){
        //comparamos el valor en indice izquierdo 
        if (leftList[leftIndex] > rightList[rightIndex]){
            list[auxIndex] = leftList[leftIndex];

            //incrementar indice izquierdo
            leftIndex++;
        } else{
            list[auxIndex] = rightList[rightIndex];
            rightIndex++;

        }
        auxIndex++;
    }

    //comparar izq con der
    while (leftIndex < leftList.size()){
        list[auxIndex] = leftList[leftIndex];
        leftIndex++;
        auxIndex++;
    }
    while (rightIndex < rightList.size()){
        list[auxIndex] = rightList[rightIndex];
        rightIndex++;
        auxIndex++;
    }
}


void mergeSort(vector<double> &list, int left, int right){
    //caso base, condicion de control cuando la lista tenga un solo elemento
    if (left < right){
        int mid = left+(right-left)/2;
        //ordenar el lado izquierdo de la lista
        mergeSort(list, left, mid);
        //ordenar lado derecho de la lista
        mergeSort(list, mid+1, right);
        //proceso de comparacion entre las listas para ordenar la sublista
        merge(list, left, mid, right);
    }

}

int main()
{
    cout << "Ingrese el número de valores a ordenar: " ;
    int n;
    cin >> n;
    vector<double> lista(n);
    cout << "Ingrese " << n << " valores (reales o enteros), uno por línea:" << endl;

    for (int i = 0; i < n; i++){
        cin >> lista[i];
    }
    cout << endl;

    mergeSort(lista,0,n-1);

    cout << "Resultado: " << endl;
    cout << "Valores ordenados de mayor a menor: " << endl;
    for (int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }

    cout << endl;
    
    return 0;
}