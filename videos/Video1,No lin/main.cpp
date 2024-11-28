#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Función para determinar si Alice puede alcanzar a la Reina Roja
string can_meet(int n, int a, int b, const string& s) {
    // Coordenadas iniciales de Alice
    int x = 0, y = 0;

    // Simular múltiples ciclos del patrón de movimientos
    for (int cycle = 0; cycle < 20; ++cycle) { // Máximo 20 ciclos son suficientes
        for (char move : s) {
            if (move == 'N') y++;
            else if (move == 'E') x++;
            else if (move == 'S') y--;
            else if (move == 'W') x--;

            // Si Alice alcanza las coordenadas de la Reina Roja
            if (x == a && y == b) {
                return "YES";
            }
        }
    }

    // Si después de 20 ciclos no llega, no es posible alcanzarla
    return "NO";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        cout << can_meet(n, a, b, s) << endl;
    }

    return 0;
}
