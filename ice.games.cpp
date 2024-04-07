#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "string"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm> // Para std::sort y std::find_if
#include <sstream>   // Se agrega para usar std::stringstream
using namespace std;
// Definición de la clase Snake
class Snake
{
public:
    int x, y;
    int dx, dy;
    char cuerpo;
};

// Definición de la clase Fruta
class Fruta
{
public:
    int x, y;
    char cuerpo = 254;
};

// Definición de la clase Juego
class Juego
{
private:
    int score, nivel, velocidad;
    Snake snake[100];
    Fruta fruta;
    int tam = 4;
    int c = 24, f = 79;
    bool gameover = false;
    clock_t tiempoInicio; // Variable para almacenar el tiempo de inicio del juego
    double tiempoJugado;  // Variable para almacenar el tiempo jugado
    void tablero();
    void genFruta();
    void genSnake();
    void loop();
    void tecla();
    void actualizar();
    void imprimir();
    void cfruta();
    void muerte();
    void puntos();
    void portada();
    void muerte2();
    int juegosJugadosSnake = 0; // Variable privada
public:
    void main();
    void incrementarJuegosJugadosSnake() { juegosJugadosSnake++; } // Método para incrementar juegosJugadosSnake
    int obtenerJuegosJugadosSnake() { return juegosJugadosSnake; } // Método para obtener el valor de juegosJugadosSnake
};

// Implementación de la función gotoxy
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Implementación de los métodos de la clase Juego
void Juego::muerte2()
{
    system("cls");
    int c = 24, f = 79, r;
    char key;
    char t = 178;
    for (int i = 0; i < f; i++)
    {
        gotoxy(i, 0);
        cout << t;
        gotoxy(i, c);
        cout << t;
    }
    for (int i = 0; i <= c; i++)
    {
        gotoxy(0, i);
        cout << t;
        gotoxy(f, i);
        cout << t;
    }

    string g4meover[] = {" ____                       ___", " / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ ",
                         "| | _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__|", "| |_| | (_| | | | | | | __/ |_| |\\ V / __/ | ",
                         " \\____|\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_|"};
    r = 2;
    for (int i = 0; i < 5; i++)
    {
        gotoxy(15, r);
        r++;
        cout << g4meover[i] << endl;
    }

    string g4meover2[] = {"   _________         _________", " /         \\       /         \\",
                          " / /~~~~~\\ \\     / /~~~~~\\ \\", " | |     | |     | |     | |", " | |     | |     | |     | |",
                          " | |     | |     | |     | |         /", " | |     | |     | |     | |       //", "(X X)    \\ \\_____/ /     \\ \\_____/ /",
                          " \\__/      \\         /       \\        /", " |         ~~~~~~~~~         ~~~~~~~~", " ^"};
    for (int i = 0; i < 11; i++)
    {
        gotoxy(20, r);
        cout << g4meover2[i] << endl;
        r++;
    }
    gotoxy(33, r);
    cout << "Score: " << score;
    r++;
    gotoxy(33, r);
    cout << "Level: " << nivel;
    gotoxy(8, 23);
    cout << "Presione ESC para salir o cualquier otra tecla para seguir jugando";
    key = getch();
    if (key == 27)
        exit(1);
}

void Juego::portada()
{
    system("cls");
    int c = 24, f = 79, r;
    char t = 178;
    for (int i = 0; i < f; i++)
    {
        gotoxy(i, 0);
        cout << t;
        gotoxy(i, c);
        cout << t;
    }
    for (int i = 0; i <= c; i++)
    {
        gotoxy(0, i);
        cout << t;
        gotoxy(f, i);
        cout << t;
    }
    string snkd[] = {"       ---_ ......._-_--.", "      (|\\ /      / /| \\ \\", "      / /     .' -=-'   `.",
                     "     / /    .'             )", "   _/ /   .'        _.)   /", " / o   o        _.-' / .'",
                     " \\          _.-'    / .'*|", "   \\______.-'//    .'.' \\*|", "    \\| \\ | //   .'.' _ |*|",
                     "     `   \\|// .'.'_ _ _|*|", "      . .// .'.' | _ _ \\*|", "      \\`-|\\_/ /    \\ _ _ \\*\\",
                     "                     \\ _ _ \\*", "                      \\ _ _ \\ ", "                       \\_"};

    r = 2;
    for (int i = 0; i < 14; i++)
    {
        gotoxy(20, r);
        r++;
        cout << snkd[i] << endl;
    }

    string snkl[] = {"                     __     ", "   _________ ____ _/ /_____", " / ___/ __ \\/ __ `/ //_/ _ \\",
                     " (__ ) / / / /_/ / ,< / __/", "/____/_/ /_/\\__,_/_/|_|\\___/"};
    for (int i = 0; i < 5; i++)
    {
        gotoxy(22, r);
        r++;
        cout << snkl[i] << endl;
    }
    gotoxy(23, 23);
    cout << "Precione ENTER para empezar";
    system("pause");
}

void Juego::puntos()
{
    gotoxy(f + 2, 2);
    cout << "Score: " << (score - 1) * 10;
    gotoxy(f + 2, 4);
    cout << "Level: " << nivel;
    gotoxy(f + 2, 6);
    cout << "Length: " << tam;
}

void Juego::tablero()
{
    char t = 178;
    for (int i = 1; i < f; i++)
    {
        gotoxy(i, 1);
        cout << t;
        gotoxy(i, c);
        cout << t;
    }
    for (int i = 1; i <= c; i++)
    {
        gotoxy(1, i);
        cout << t;
        gotoxy(f, i);
        cout << t;
    }
}
void Juego::genSnake()
{
    int i;
    snake[0].x = 30;
    snake[0].y = 10;
    snake[0].dx = 1;
    snake[0].dy = 0;
    snake[0].cuerpo = 157;

    for (i = 1; i < tam; i++)
    {
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;
        snake[i].cuerpo = 184;
    }

    for (i = 0; i < tam; i++)
    {
        gotoxy(snake[i].x, snake[i].y);
        cout << snake[i].cuerpo;
    }
}
void Juego::genFruta()
{
    fruta.x = 2 + (rand() % (f - 2));
    fruta.y = 2 + (rand() % (c - 2));
    gotoxy(fruta.x, fruta.y);
    cout << fruta.cuerpo;
}
void Juego::cfruta()
{
    if (snake[0].x == fruta.x && snake[0].y == fruta.y)
    {
        genFruta();
        tam += 1;
        snake[tam - 1].cuerpo = 184;
        score += 1;
        if (tam % 10 == 0)
        {
            nivel++;
            velocidad -= 20;
        }
    }
}
void Juego::muerte()
{
    if (snake[0].x == 1 || snake[0].x == f || snake[0].y == 1 || snake[0].y == c)
        gameover = true;

    for (int i = 1; i < tam && gameover == false; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            gameover = true;
        }
    }
}

void Juego::tecla()
{
    int i;
    (void)i;
    char key;

    if (!gameover)
    {
        if (kbhit() == 1)
        {
            key = getch();
        }
        if ((key == 72) && snake[0].dy != 1)
        {
            snake[0].dx = 0;
            snake[0].dy = -1;
        }
        if ((key == 80) && snake[0].dy != -1)
        {
            snake[0].dx = 0;
            snake[0].dy = 1;
        }
        if ((key == 75) && snake[0].dx != 1)
        {
            snake[0].dx = -1;
            snake[0].dy = 0;
        }
        if ((key == 77) && snake[0].dx != -1)
        {
            snake[0].dx = 1;
            snake[0].dy = 0;
        }
        // Detectar la tecla ESC
        if (key == 27) // 27 es el código ASCII para ESC
        {
            gameover = true; // Termina el juego
        }
    }
}
void Juego::actualizar()
{
    int i;
    gotoxy(snake[tam - 1].x, snake[tam - 1].y);
    cout << " ";

    for (i = tam - 1; i > 0; i--)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    snake[0].x += snake[0].dx;
    snake[0].y += snake[0].dy;
}

void Juego::imprimir()
{
    int i;
    for (i = tam - 1; i >= 0; i--)
    {
        gotoxy(snake[i].x, snake[i].y);
        cout << snake[i].cuerpo;
    }
}
void Juego::loop()
{
    tiempoInicio = clock(); // Iniciar el tiempo cuando comienza el juego

    while (!gameover)
    {
        cfruta();
        puntos();
        actualizar();
        imprimir();
        tecla();
        tecla();
        tecla();
        muerte();
        Sleep(velocidad);
    }

    // Calcular el tiempo jugado
    tiempoJugado = (double)(clock() - tiempoInicio) / CLOCKS_PER_SEC;
}
void Juego::main()
{
    system("color 0a");
    gameover = false;
    portada();
    system("cls");
    score = 1;
    velocidad = 110;
    tam = 4;
    nivel = 1;
    tablero();
    srand(time(NULL));
    genSnake();
    genFruta();
    loop();
    muerte2();
    // Eliminamos la recursión en main()
    // main();
}

// Definición de la clase Buscaminas
class Buscaminas
{
private:
    int nivel = 0;
    int vidas = 0;
    int intentos = 0;
    int fila = 0;
    int columna = 0;
    bool fin = false;
    int m[10][10];
    string mT[10][10];
    int juegosJugadosBuscaminas = 0; // Variable privada

public:
    void main();
    void incrementarJuegosJugadosBuscaminas() { juegosJugadosBuscaminas++; } // Método para incrementar juegosJugadosBuscaminas
    int obtenerJuegosJugadosBuscaminas() { return juegosJugadosBuscaminas; } // Método para obtener el valor de juegosJugadosBuscaminas
};

void Buscaminas::main()
{
    srand(time(NULL)); // Inicialización de la semilla para rand()

    int nivel = 0;
    int vidas = 0;
    int intentos = 0;
    int fila = 0;
    int columna = 0;
    bool fin = false;
INICIO:
    cout << endl;
    cout << "         Bienvenidos al Buscaminas" << endl;
    cout << endl;
    cout << "   Este juego consiste en poder seleccionar" << endl;
    cout << "   todos los bloques sin hacer explotar las minas." << endl;
    cout << endl;
NIVEL:
    cout << endl;
    cout << "   selecciona el nivel de juego" << endl;
    cout << endl;
    cout << "   Nivel             Vidas           Escribe" << endl;
    cout << endl;
    cout << "   Practica          1000            1" << endl;
    cout << "   Facil             8               2" << endl;
    cout << "   Medio             5               3" << endl;
    cout << "   Dificil           3               4" << endl;
    cout << "   Muy Dificil       1               5" << endl;
    cout << " Salir   6 " << endl;
    cout << endl;
    cout << "   Ingresa el tu Nivel: ";
    cin >> nivel;
    cout << endl;
    if (nivel == 6)
    {
        cout << "gracias por jugar " << endl;
        return;
    }
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
        cout << "Escribe un nivel válido entre 1 y 5" << endl;
        goto NIVEL;
        break;
    }

    int m[nivel][nivel];
    string mT[nivel][nivel];
    srand(time(NULL));

    // Lógica del juego
    while (fin == false)
    {
    FIL:
        cout << "   digite la fila entre 0 y " << nivel - 1 << " ";
        cin >> fila;
        cout << endl;
        if (fila < 0 || fila > nivel - 1)
        {
            cout << "   escribe un numero entre 0 y " << nivel - 1 << " " << endl;
            goto FIL;
        }
    COL:
        cout << "   digite la columna entre 0 y " << nivel - 1 << " ";
        cin >> columna;
        cout << endl;
        if (columna < 0 || columna > nivel - 1)
        {
            cout << "   escribe un numero entre 0 y " << nivel - 1 << " " << endl;
            goto COL;
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
            cout << endl;
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
            goto INICIO;
        }

        // Dentro del bucle principal del juego de Buscaminas
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'p' || key == 'P' || key == 'q' || key == 'Q')
            {
                fin = true; // Termina el juego
                break;      // Rompe el bucle principal
            }
            // Verificar si la tecla ESC fue presionada
            if (key == 27) // 27 es el código ASCII para ESC
            {
                cout << "Saliendo del juego de Buscaminas..." << endl;
                fin = true; // Termina el juego
                break;      // Rompe el bucle principal
            }
        }
    }
}
// Clase para representar un videojuego
class Videojuego
{
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
bool compararPorAnoLanzamiento(const Videojuego &juego1, const Videojuego &juego2)
{
    return juego1.anoLanzamiento < juego2.anoLanzamiento;
}

// Clase para gestionar la lista de videojuegos
class GestionVideojuegos
{
private:
    vector<Videojuego> videojuegos;

public:
    void agregarVideojuego(Videojuego juego)
    {
        videojuegos.push_back(juego);
    }

    void mostrarVideojuegosPorTituloCategoria()
    {
        // Ordenar los videojuegos por título de categoría
        sort(videojuegos.begin(), videojuegos.end(), [](const Videojuego &a, const Videojuego &b)
             { return a.nombre < b.nombre; });

        for (const auto &juego : videojuegos)
        {
            cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << endl;
        }
    }

    void mostrarVideojuegosPorAnoLanzamiento()
    {
        // Ordenar los videojuegos por año de lanzamiento
        sort(videojuegos.begin(), videojuegos.end(), compararPorAnoLanzamiento);

        for (const auto &juego : videojuegos)
        {
            cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << ", Año de lanzamiento: " << juego.anoLanzamiento << endl;
        }
    }

    void mostrarVideojuegosPorCategoria()
    {
        map<string, vector<Videojuego>> categoriasMap;

        // Agrupar videojuegos por categoría
        for (const auto &juego : videojuegos)
        {
            for (const auto &categoria : juego.categorias)
            {
                categoriasMap[categoria].push_back(juego);
            }
        }

        // Mostrar videojuegos por categoría
        if (categoriasMap.empty())
        {
            cout << "No hay videojuegos registrados por categoría." << endl;
        }
        else
        {
            for (const auto &pair : categoriasMap)
            {
                cout << "\nCategoría: " << pair.first << endl;
                for (const auto &juego : pair.second)
                {
                    cout << "Nombre: " << juego.nombre << ", Plataforma: " << juego.plataforma << ", Desarrollador: " << juego.desarrollador << endl;
                }
            }
        }
        cout << "\nPresione Enter para continuar...";
        cin.ignore(); // Limpiar el buffer del teclado
        cin.get();    // Esperar a que el usuario presione Enter
    }
};

// Funciones para cada opción del menú
void gestionVideojuegos(GestionVideojuegos &gestion)
{
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
    while (getline(ss, categoria, ','))
    {
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

void gestionJugadores()
{
    cout << "\n\tGestion de Jugadores" << endl;

    int cantidadTotalJugadores;
    cout << "Ingrese la cantidad total de jugadores para el juego: ";
    cin >> cantidadTotalJugadores;
    cout << "Se han registrado exitosamente " << cantidadTotalJugadores << " jugadores." << endl;
}

void jugar()
{
    cout << "\n\tJugar" << endl;
    Juego juego;
    Buscaminas buscaminas;
    int opcion;
    do
    {
        cout << "Bienvenido al menú de juegos" << endl;
        cout << "1. Jugar Snake" << endl;
        cout << "2. Jugar Buscaminas" << endl;
        cout << "3. Cuánto a jugado cada juego" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            juego.main();
            juego.incrementarJuegosJugadosSnake();
            break;
        case 2:
            buscaminas.main();
            buscaminas.incrementarJuegosJugadosBuscaminas();
            break;
        case 3:
            cout << "Juegos jugados en Snake: " << juego.obtenerJuegosJugadosSnake() << endl;
            cout << "Juegos jugados en Buscaminas: " << buscaminas.obtenerJuegosJugadosBuscaminas() << endl;
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }

    } while (opcion != 4);
}

// Función para mostrar el menú principal
void menuPrincipal(const string &nombreJugador, GestionVideojuegos &gestion)
{
    int opcion;
    bool repetir = true;

    do
    {
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

        switch (opcion)
        {
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
            cin.get();    // Esperar a que el usuario presione Enter
            break;
        }
    } while (repetir);
}

int main()
{
    srand(time(NULL)); // Inicialización de la semilla para rand()
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