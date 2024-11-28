#include <iostream>
#include <vector>
using namespace std;

// Estructura para almacenar salud y índice de un monstruo
struct Monstruo {
    int salud;
    int indice;
};

// Función para "apilar" (heapify) el vector
void heapify(vector<Monstruo>& arr, int n, int i) {
    int largest = i;        // Inicializar el nodo como el mayor
    int left = 2 * i + 1;   // Hijo izquierdo
    int right = 2 * i + 2;  // Hijo derecho

    // Si el hijo izquierdo es mayor que el nodo más grande actual
    if (left < n && (arr[left].salud > arr[largest].salud || 
                    (arr[left].salud == arr[largest].salud && arr[left].indice < arr[largest].indice))) {
        largest = left;
    }

    // Si el hijo derecho es mayor que el nodo más grande actual
    if (right < n && (arr[right].salud > arr[largest].salud || 
                     (arr[right].salud == arr[largest].salud && arr[right].indice < arr[largest].indice))) {
        largest = right;
    }

    // Si el mayor no es el nodo actual
    if (largest != i) {
        swap(arr[i], arr[largest]); // Intercambiamos
        heapify(arr, n, largest);  // Apilar recursivamente
    }
}

// Función para ordenar el vector usando Heap Sort
void heapSort(vector<Monstruo>& arr) {
    int n = arr.size();

    // Construir el heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Mover el nodo raíz al final
        heapify(arr, i, 0);   // Llamar a heapify en el heap reducido
    }
}

// Función para resolver cada caso
void resolverCaso() {
    int n, k;
    cin >> n >> k;

    vector<Monstruo> monstruos(n);
    for (int i = 0; i < n; i++) {
        cin >> monstruos[i].salud;
        monstruos[i].indice = i + 1; // Índice 1-based
    }

    // Ordenar usando Heap Sort
    heapSort(monstruos);

    vector<int> ordenMuerte;

    while (!monstruos.empty()) {
        // El monstruo con mayor salud está al final del array
        Monstruo& objetivo = monstruos.back();
        objetivo.salud -= k;

        if (objetivo.salud <= 0) {
            ordenMuerte.push_back(objetivo.indice);
            monstruos.pop_back(); // Eliminar el monstruo
        }

        // Reordenar el heap si fue modificado
        heapSort(monstruos);
    }

    // Imprimir el orden de muerte
    for (int idx : ordenMuerte) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        resolverCaso();
    }
    return 0;
}
