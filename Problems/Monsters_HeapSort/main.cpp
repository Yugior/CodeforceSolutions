#include <iostream>
#include <vector>
using namespace std;

// Estructura para almacenar salud e índice de un monstruo
struct Monstruo {
    int salud;  // Salud actual del monstruo
    int indice; // Índice original del monstruo
};

// Función para "apilar" (heapify) el vector
void heapify(vector<Monstruo>& arr, int n, int i) {
    int largest = i;        // Inicializar el nodo como el mayor
    int left = 2 * i + 1;   // Hijo izquierdo
    int right = 2 * i + 2;  // Hijo derecho

    // Comparar el hijo izquierdo con el mayor
    if (left < n && (arr[left].salud > arr[largest].salud || 
                    (arr[left].salud == arr[largest].salud && arr[left].indice < arr[largest].indice))) {
        largest = left;
    }

    // Comparar el hijo derecho con el mayor
    if (right < n && (arr[right].salud > arr[largest].salud || 
                     (arr[right].salud == arr[largest].salud && arr[right].indice < arr[largest].indice))) {
        largest = right;
    }

    // Si el mayor no es el nodo actual, intercambiar y continuar heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Función para ordenar el vector usando Heap Sort
void heapSort(vector<Monstruo>& arr) {
    int n = arr.size();

    // Construir el heap (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Mover el nodo raíz al final
        heapify(arr, i, 0);   // Aplicar heapify al heap reducido
    }
}

// Función para resolver cada caso de prueba
void resolverCaso() {
    int n, k;
    cin >> n >> k;

    // Leer la información de los monstruos
    vector<Monstruo> monstruos(n);
    for (int i = 0; i < n; i++) {
        cin >> monstruos[i].salud;
        monstruos[i].indice = i + 1; // Índices 1-based
    }

    // Ordenar los monstruos usando Heap Sort (innecesario para max-heap dinámico)
    heapSort(monstruos);

    vector<int> ordenMuerte;

    // Simular el proceso de eliminación
    while (!monstruos.empty()) {
        // El monstruo con mayor salud está al final del arreglo
        Monstruo& objetivo = monstruos.back();
        objetivo.salud -= k;

        // Si el monstruo muere, agregarlo al orden de muerte
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

    // Resolver cada caso de prueba
    while (t--) {
        resolverCaso();
    }

    return 0;
}
