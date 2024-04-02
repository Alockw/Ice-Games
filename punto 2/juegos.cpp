#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
class Buscaminas
{
private:
    static int juegosJugados; // Variable estática para contar los juegos jugados
    int nivel = 0;
    int vidas = 0;
    int intentos = 0;
    int fila = 0;
    int columna = 0;
    bool fin = false;
    int m[10][10];     // Asegúrate de que el tamaño sea suficiente para todos los niveles
    string mT[10][10]; // Asegúrate de que el tamaño sea suficiente para todos los niveles

public:
    int getNivel() const { return nivel; }
    int getVidas() const { return vidas; }
    int getIntentos() const { return intentos; }
    int getFila() const { return fila; }
    int getColumna() const { return columna; }
    bool getFin() const { return fin; }
    Buscaminas() {
        juegosJugados++; // Incrementa el contador cada vez que se crea una instancia de la clase
    }
    void mostrarContador() {
        cout << "Has jugado " << juegosJugados << " veces." << endl;
    }

    void nivelBuscaMinas()
    {
        cout << "   selecciona el nivel de juego" << endl;
        cout << endl;
        cout << "   Nivel             Vidas           Escribe" << endl;
        cout << endl;
        cout << "   Practica          1000            1" << endl;
        cout << "   Facil             8               2" << endl;
        cout << "   Medio             5               3" << endl;
        cout << "   Dificil           3               4" << endl;
        cout << "   Muy Dificil       1               5" << endl;
        cout << endl;
        cout << "   Ingresa el tu Nivel: ";
        cin >> nivel;
        cout << endl;
        switch (nivel)
        {
        case 1:
            nivel = 10;
            vidas = 1000;
            fin = false;
            intentos = 0;
            system("cls");
            break;
        case 2:
            nivel = 8;
            vidas = 8;
            fin = false;
            intentos = 0;
            system("cls");
            break;
        case 3:
            nivel = 6;
            vidas = 5;
            fin = false;
            intentos = 0;
            system("cls");
            break;
        case 4:
            nivel = 6;
            vidas = 3;
            fin = false;
            intentos = 0;
            system("cls");
            break;
        case 5:
            nivel = 5;
            vidas = 1;
            fin = false;
            intentos = 0;
            system("cls");
            break;
        default:
            system("cls");
            cout << "   escribe un nivel valido entre 1 y 5" << endl;
            nivelBuscaMinas(); // Llama a la función recursivamente en lugar de usar goto
            break;
        }
        srand(static_cast<unsigned int>(time(NULL))); // Inicializa la semilla solo una vez
    }

    void matrisLogica()
    {
        for (int i = 0; i < nivel; i++)
        {
            for (int j = 0; j < nivel; j++)
            {
                m[i][j] = rand() % (2 - 0) + (i * 100) + (j * 10);
            }
        }
    }

    void matrisVisible()
    {
        for (int i = 0; i < nivel; i++)
        {
            for (int j = 0; j < nivel; j++)
            {
                mT[i][j] = "#";
            }
        }
    }

    void imprimirMatris()
    {
        cout << "                 Buscaminas" << vidas << endl;
        cout << "     Intentos:" << intentos << "      Vidas: " << vidas - 1 << endl;
        for (int i = 0; i < nivel; i++)
        {
            cout << endl;
            for (int j = 0; j < nivel; j++)
            {
                cout << "   " << mT[i][j];
            }
            cout << endl;
        }
    }

    void logicaBuscaminas()
    {
        while (fin == false)
        {
            cout << "   digite la fila entre 0 y " << nivel - 1 << " ";
            cin >> fila;
            cout << endl;
            if (fila < 0 || fila > nivel - 1)
            {
                cout << "   escribe un numero entre 0 y " << nivel - 1 << " " << endl;
                continue; // Usa continue en lugar de goto
            }
            cout << "   digite la columna entre 0 y " << nivel - 1 << " ";
            cin >> columna;
            cout << endl;
            if (columna < 0 || columna > nivel - 1)
            {
                cout << "   escribe un numero entre 0 y " << nivel - 1 << " " << endl;
                continue; // Usa continue en lugar de goto
            }
            intentos++;
            if (m[fila][columna] % 2 == 0)
            {
                mT[fila][columna] = " ";
            }
            if (m[fila][columna] % 2 == 1)
            {
                mT[fila][columna] = "*";
                vidas--;
                if (vidas == 0)
                {
                    fin = true;
                }
            }
            system("cls");
            if (fin == false)
            {
                imprimirMatris();
            }
            if (fin == true)
            {
                cout << "                 Buscaminas" << vidas << endl;
                cout << "     Intentos:" << intentos << "      Vidas: " << vidas << endl;
                cout << endl;
                cout << "                     GAME OVER" << endl;
                cout << "                     Has perdido" << endl;
                cout << endl;
                Sleep(2000);
                system("cls");
                cout << "Intentalo nuevamente" << endl;
                Sleep(1000);
                system("cls");
                nivelBuscaMinas(); // Reinicia el juego
            }
        }
    }
};

int main()
{
    Buscaminas juego;
    juego.nivelBuscaMinas();
    juego.matrisLogica();
    juego.matrisVisible();
    juego.imprimirMatris();
    juego.logicaBuscaminas();
    return 0;
}