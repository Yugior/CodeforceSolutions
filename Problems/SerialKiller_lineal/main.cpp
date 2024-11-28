#include <iostream>
#include <string>
using namespace std;

// Definimos la estructura de un nodo para la lista enlazada
struct Node {
    string name;    // Nombre de la víctima
    Node* next;     // Puntero al siguiente nodo
};

int main() {
    // Variables para las víctimas iniciales
    string victim1, victim2;
    cin >> victim1 >> victim2;

    // Crear los nodos para las víctimas iniciales
    Node* head = new Node{victim1, nullptr};    // Nodo para la primera víctima
    Node* second = new Node{victim2, nullptr}; // Nodo para la segunda víctima

    // Enlazar los nodos (la lista siempre tiene 2 nodos)
    head->next = second;

    // Imprimir las víctimas iniciales
    cout << head->name << " " << second->name << endl;

    // Leer el número de días
    int n;
    cin >> n;

    // Procesar cada día
    for (int i = 0; i < n; i++) {
        // Leer los nombres del asesinado y su reemplazo
        string killed, replacement;
        cin >> killed >> replacement;

        // Buscar en la lista la víctima asesinada
        Node* temp = head; // Empezar desde el primer nodo
        while (temp != nullptr) { // Buscar hasta encontrar el nodo correcto
            if (temp->name == killed) { 
                // Reemplazamos el nombre de la víctima asesinada por el nuevo
                temp->name = replacement; 
                break; // Salimos del bucle una vez hecho el reemplazo
            }
            temp = temp->next; // Avanzamos al siguiente nodo
        }

        // Imprimir las víctimas actuales después del reemplazo
        cout << head->name << " " << second->name << endl;
    }

    // Nota: No liberamos memoria de los nodos porque el programa termina aquí.
    return 0;
}
