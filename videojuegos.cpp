#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Videojuego
{
private:
    string nombre;
    string plataforma;
    string desarrollador;

    int cantidadJugadores;
    int anoLanzamiento;

    set<string> categorias;

public:
    Videojuego(string nombre, int cantidadJugadores, const set<string> &categorias, string desarrollador, int anoLanzamiento, string plataforma)
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

    const set<string> &getCategorias() const
    {
        return categorias;
    }

    void setNombre(const string &newNombre)
    {
        nombre = newNombre;
    }
    void setPlataforma(const string &newPlataforma)
    {
        plataforma = newPlataforma;
    }
    void setDesarrollador(const string &newDesarrollador)
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

    void setCategorias(const set<string> &newCategorias)
    {
        categorias = newCategorias;
    }
};