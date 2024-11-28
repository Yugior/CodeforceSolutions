#include <iostream>
#include <string>
using namespace std;

// Definimos la estructura de un nodo para la lista enlazada
struct Node {
    string name;    // Nombre de la víctima
    Node* next;     // Puntero al siguiente nodo
};

int main() {
    string victim1, victim2;
    cin >> victim1 >> victim2;
    
    // Crear los nodos para las víctimas iniciales
    Node* head = new Node{victim1, nullptr};   // Nodo de la primera víctima
    Node* second = new Node{victim2, nullptr}; // Nodo de la segunda víctima
    
    // Enlazar los nodos
    head->next = second;  // El primer nodo apunta al segundo

    // Imprimir las víctimas iniciales
    cout << head->name << " " << second->name << endl;
    
    int n;
    cin >> n;
    
    // Procesar cada día
    for (int i = 0; i < n; i++) {
        string killed, replacement;
        cin >> killed >> replacement;

        // Búsqueda de la víctima asesinada en la lista enlazada
        Node* temp = head;
        
        // La lista siempre tiene exactamente 2 elementos en todo momento
        // Por lo tanto, la búsqueda de la víctima asesinada toma O(1) tiempo
        while (temp != nullptr) {
            if (temp->name == killed) {
                // Reemplazamos la víctima asesinada por la nueva víctima
                temp->name = replacement;  // Reemplazo de nombre en el nodo actual
                break;
            }
            temp = temp->next;  // Avanzamos al siguiente nodo
        }

        // Imprimir las víctimas actuales después del reemplazo
        cout << head->name << " " << second->name << endl;
    }
    
    return 0;
}
