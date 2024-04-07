#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm> // Para std::sort y std::find_if
#include <sstream> // Se agrega para usar std::stringstream
using namespace std;

// Clase para representar un videojuego
class Videojuego {
public:
    string nombre;
    string plataforma;
    string desarrollador;
    int cantidadJugadores;
    int anoLanzamiento;
    vector<string> categorias;

    Videojuego(string nombre, vector<string> categorias, string desarrollador, int cantidadJugadores, int anoLanzamiento, string plataforma)
        : nombre(nombre), categorias(categorias), desarrollador(desarrollador), cantidadJugadores(cantidadJugadores), anoLanzamiento(anoLanzamiento), plataforma(plataforma) {}
};

// Función para comparar dos videojuegos por su año de lanzamiento
bool compararPorAnoLanzamiento(const Videojuego& juego1, const Videojuego& juego2) {
    return juego1.anoLanzamiento < juego2.anoLanzamiento;
}

// Clase para gestionar la lista de videojuegos
class GestionVideojuegos {
private:
    vector<Videojuego> videojuegos;

public:
    void agregarVideojuego(Videojuego juego) {
        videojuegos.push_back(juego);
    }

    void mostrarVideojuegosPorTituloCategoria() {
        // Ordenar los videojuegos por título de categoría
        sort(videojuegos.begin(), videojuegos.end(), [](const Videojuego& a, const Videojuego& b) {
            return a.nombre < b.nombre;
        });

        for (const auto& juego : videojuegos) {
            cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << endl;
        }
    }

    void mostrarVideojuegosPorAnoLanzamiento() {
        // Ordenar los videojuegos por año de lanzamiento
        sort(videojuegos.begin(), videojuegos.end(), compararPorAnoLanzamiento);

        for (const auto& juego : videojuegos) {
            cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << ", Año de lanzamiento: " << juego.anoLanzamiento << endl;
        }
    }

    void mostrarVideojuegosPorCategoria() {
        map<string, vector<Videojuego>> categoriasMap;

        // Agrupar videojuegos por categoría
        for (const auto& juego : videojuegos) {
            for (const auto& categoria : juego.categorias) {
                categoriasMap[categoria].push_back(juego);
            }
        }

        // Mostrar videojuegos por categoría
        if (categoriasMap.empty()) {
            cout << "No hay videojuegos registrados por categoría." << endl;
        } else {
            for (const auto& pair : categoriasMap) {
                cout << "\nCategoría: " << pair.first << endl;
                for (const auto& juego : pair.second) {
                    cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << endl;
                }
            }
        }
        cout << "\nPresione Enter para continuar...";
        cin.ignore(); // Limpiar el buffer del teclado
        cin.get(); // Esperar a que el usuario presione Enter
    }
};

// Funciones para cada opción del menú
void gestionVideojuegos(GestionVideojuegos& gestion) {
    cout << "\n\tGestion de Videojuegos" << endl;
    
    string nombre, desarrollador, plataforma;
    vector<string> categorias;
    int cantidadJugadores, anoLanzamiento;

    cout << "Ingrese el nombre del juego: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese las categorias del juego (separadas por coma): ";
    string categoriasInput;
    getline(cin, categoriasInput);
    stringstream ss(categoriasInput);
    string categoria;
    while (getline(ss, categoria, ',')) {
        categorias.push_back(categoria);
    }

    cout << "Ingrese el desarrollador del juego: ";
    getline(cin, desarrollador);

    cout << "Ingrese la cantidad de jugadores del juego: ";
    cin >> cantidadJugadores;

    cout << "Ingrese el año de lanzamiento del juego: ";
    cin >> anoLanzamiento;

    cout << "Ingrese la plataforma del juego: ";
    cin.ignore();
    getline(cin, plataforma);

    Videojuego nuevoJuego(nombre, categorias, desarrollador, cantidadJugadores, anoLanzamiento, plataforma);
    gestion.agregarVideojuego(nuevoJuego);
}

void gestionJugadores() {
    cout << "\n\tGestion de Jugadores" << endl;

    int cantidadTotalJugadores;
    cout << "Ingrese la cantidad total de jugadores para el juego: ";
    cin >> cantidadTotalJugadores;
    cout << "Se han registrado exitosamente " << cantidadTotalJugadores << " jugadores." << endl;
}

void jugar() {
    cout << "\n\tJugar" << endl;
    // Aquí va la lógica para jugar
}

// Función para mostrar el menú principal
void menuPrincipal(const string& nombreJugador, GestionVideojuegos& gestion) {
    int opcion;
    bool repetir = true;

    do {
        system("cls"); // Limpia la consola

        cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. Gestion de Videojuegos" << endl;
        cout << "\t2. Gestion de Jugadores" << endl;
        cout << "\t3. Mostrar Videojuegos por Título de Categoría" << endl;
        cout << "\t4. Mostrar Videojuegos por Año de Lanzamiento" << endl;
        cout << "\t5. Mostrar Videojuegos por Categoría" << endl;
        cout << "\t6. Jugar" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\t¡Bienvenido, " << nombreJugador << "!" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestionVideojuegos(gestion);
            break;
        case 2:
            gestionJugadores();
            break;
        case 3:
            gestion.mostrarVideojuegosPorTituloCategoria();
            break;
        case 4:
            gestion.mostrarVideojuegosPorAnoLanzamiento();
            break;
        case 5:
            gestion.mostrarVideojuegosPorCategoria();
            break;
        case 6:
            jugar();
            break;
        case 0:
            repetir = false;
            break;
        default:
            cout << "\nOpción no válida. Por favor, seleccione una opción válida." << endl;
            cout << "\nPresione Enter para continuar...";
            cin.ignore(); // Limpiar el buffer del teclado
            cin.get(); // Esperar a que el usuario presione Enter
            break;
        }
    } while (repetir);
}

int main() {
    string nombreJugador;
    cout << "Bienvenido al sistema de gestion de videojuegos." << endl;
    cout << "Por favor, ingrese su nombre: ";
    getline(cin, nombreJugador);

    GestionVideojuegos gestion;

    // Videojuegos predeterminados
    gestion.agregarVideojuego(Videojuego("The Witcher 3: Wild Hunt", {"RPG", "Aventura"}, "CD Projekt Red", 1, 2015, "PC"));
    gestion.agregarVideojuego(Videojuego("The Legend of Zelda: Breath of the Wild", {"Aventura", "Accion"}, "Nintendo EPD", 1, 2017, "Nintendo Switch"));
    gestion.agregarVideojuego(Videojuego("Grand Theft Auto V", {"Accion", "Mundo abierto"}, "Rockstar North", 1, 2013, "PlayStation 4"));
    gestion.agregarVideojuego(Videojuego("Overwatch", {"Shooter", "Multijugador"}, "Blizzard Entertainment", 2, 2016, "Xbox One"));
    gestion.agregarVideojuego(Videojuego("Minecraft", {"Sandbox", "Aventura"}, "Mojang Studios", 4, 2011, "PC"));

    menuPrincipal(nombreJugador, gestion);
    return 0;
}
