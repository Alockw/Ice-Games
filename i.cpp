#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Videojuego {
private:
    string nombre;
    string plataforma;
    string desarrollador;

    int cantidadJugadores;
    int anoLanzamiento;

    set<string>categorias;

public:
    Videojuego(string nombre, int cantidadJugadores, const set<string>& categorias, string desarrollador, int anoLanzamiento, string plataforma) 
        : nombre(nombre), cantidadJugadores(cantidadJugadores), categorias(categorias), desarrollador(desarrollador), anoLanzamiento(anoLanzamiento), plataforma(plataforma) {}

    string getNombre() const 
    {
        return nombre;
    }
    string getDesarrollador() const 
    {
        return desarrollador;
    }
    string getPlataforma() const 
    {
        return plataforma;
    }

    int getCantidadJugadores() const 
    {
        return cantidadJugadores;
    }
    int getAnoLanzamiento() const 
    {
        return anoLanzamiento;
    }

    const set<string>& getCategorias() const 
    {
        return categorias;
    }

    void setNombre(const string& newNombre) 
    {
        nombre = newNombre;
    }
    void setPlataforma(const string& newPlataforma) {
        plataforma = newPlataforma;
    }
    void setDesarrollador(const string& newDesarrollador) 
    {
        desarrollador = newDesarrollador;
    }

    void setCantidadJugadores(int newCantidadJugadores) 
    {
        cantidadJugadores = newCantidadJugadores;
    }
    void setAnoLanzamiento(int newAnoLanzamiento) 
    {
        anoLanzamiento = newAnoLanzamiento;
    }

    void setCategorias(const set<string>& newCategorias) 
    {
        categorias = newCategorias;
    }
};
// Ejemplo de uso de la clase Videojuego
// int main() {
//     vector<string> categorias = {"Acción", "Aventura"};
//     Videojuego juego("Ejemplo", 1, categorias, "DesarrolladorX", 2022, "PC");

//     cout << "Nombre: " << juego.getNombre() << endl;
//     cout << "Cantidad de jugadores: " << juego.getCantidadJugadores() << endl;
//     cout << "Categorías: ";
//     for (const auto& categoria : juego.getCategorias()) {
//         cout << categoria << ", ";
//     }
//     cout << endl;
//     cout << "Desarrollador: " << juego.getDesarrollador() << endl;
//     cout << "Año de lanzamiento: " << juego.getAnoLanzamiento() << endl;
//     cout << "Plataforma: " << juego.getPlataforma() << endl;

//     return 0;
// }

// 4. Implementar un mecanismo que permita agregar en una lista los juegos favoritos de cada jugador.
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Jugador 
{
private:
    string nombre;
    vector <string> juegosFavoritos;

public:
    Jugador(const string& nombre) : nombre(nombre) {}

    void agregarJuegoFavorito(const string& juego) 
    {
        juegosFavoritos.push_back(juego);
    }

    const std::vector<std::string>& obtenerJuegosFavoritos() const 
    {
        return juegosFavoritos;
    }

    const std::string& obtenerNombre() const
    {
        return nombre;
    }
};

int main() {
    Jugador jugador1("Juan");
    Jugador jugador2("María");

    jugador1.agregarJuegoFavorito("The Legend of Zelda: Breath of the Wild");
    jugador1.agregarJuegoFavorito("Super Mario Odyssey");

    jugador2.agregarJuegoFavorito("Red Dead Redemption 2");
    jugador2.agregarJuegoFavorito("The Witcher 3: Wild Hunt");

    cout << "Juegos favoritos de " << jugador1.obtenerNombre() << ":\n";
    for (const auto& juego : jugador1.obtenerJuegosFavoritos()) 
    {
        cout << "- " << juego << endl;
    }

    cout << "\nJuegos favoritos de " << jugador2.obtenerNombre() << ":\n";
    for (const auto& juego : jugador2.obtenerJuegosFavoritos()) 
    {
        cout << "- " << juego << endl;
    }

    return 0;
}
