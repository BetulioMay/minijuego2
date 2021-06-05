/*
    @author Cesar A. Mayora
 */

#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include "raylib.h"
#include <string>

using namespace std;

const float WIDTH = 800.0;
const float HEIGHT = 800.0;

int main(int argc, char* argv[]){

    if (argc < 2){
        cerr << "Usage: <executable> <n part>" << "\n";
        exit(-1);
    }
    
    int N = atoi(argv[1]);
    
    Particula base(WIDTH / 2.0, HEIGHT - 20.0, 5.0, 0.0, RADIO * 2.0f);
    ConjuntoParticulas ovnis(N);
    ConjuntoParticulas proyectiles;
    
    InitWindow(WIDTH, HEIGHT, "El juego toca pelotas");
    
    SetTargetFPS(60);
    
    // Game variables
    int time = 0;
    int ticks = 0;
    string s;
    bool gameOver = false;
    bool win = false;
    bool ovni_killed;
    
    while (!WindowShouldClose()){
        
        // Update

        if (!gameOver) {
            // Motions
            ovnis.Mover(WIDTH, HEIGHT);
            ovnis.Rebotar(WIDTH, HEIGHT);

            proyectiles.Mover(WIDTH, HEIGHT);

            // Keyboard controls
            if (IsKeyDown(KEY_LEFT)) {
                base.MoverGrid('L', WIDTH, HEIGHT);
            } else if (IsKeyDown(KEY_RIGHT)) {
                base.MoverGrid('R', WIDTH, HEIGHT);
            }

            if (IsKeyPressed(KEY_SPACE)) {
                proyectiles.AgregaParticula(Particula(base.GetX(), base.GetY(), 0.0f, -5.0f, RADIO / 2.0f));
            }

            // Check for possible collisions
            for (int i = ovnis.GetUtiles() - 1; i >= 0 && !gameOver; --i) {

                gameOver = (base.Colision(ovnis.ObtieneParticula(i))) ? true : false;

                ovni_killed = false; // flag para salir del bucle cuando se ha "matado" un ovni y evitar errores de assert
                for (int j = proyectiles.GetUtiles() - 1; j >= 0 && !gameOver && !ovni_killed; --j) {
                    if (proyectiles.ObtieneParticula(j).Colision(ovnis.ObtieneParticula(i))){

                        ovnis.BorraParticula(i);
                        proyectiles.BorraParticula(j);

                        gameOver = win = (ovnis.GetUtiles() < 1) ? true : false;
                        ovni_killed = true;
                    }
                }
            }
            
            // Comprobamos que los proyectiles se "van de la pantalla"
            // Solo necesitamos comprobar el primer proyectil ya que en cada tick
            // solo presionamos una vez, el primero en ser lanzado sera el primero en
            // "salirse"
            if (proyectiles.GetUtiles() > 0) {
                Particula p;
                p = proyectiles.ObtieneParticula(0);
                if (p.GetY() <= p.GetRadio()) {
                    proyectiles.BorraParticula(0);
                }
            }
        
            // Time control
            time += (ticks < 59) ? 0 : 1;
            ticks = (ticks + 1) % 60;
        }
        
        // Draw
        
        BeginDrawing();
        ClearBackground(BLACK);
        
        if (gameOver) {
            if (win) {
                s = "Has ganado!\tTiempo total -> " + to_string(time) + "\nPulsa ESC para salir";
                DrawText(s.c_str(), WIDTH / 4.0, HEIGHT / 2.0, 30, GREEN);
            } else {
                s = "Has perdido!\tTiempo total -> " + to_string(time) + "\nPulsa ESC para salir";
                DrawText(s.c_str(), WIDTH / 4.0, HEIGHT / 2.0, 30, GREEN);
            }
            
        } else {
            
            s = "Particulas -> " + to_string(ovnis.GetUtiles()) + "\tCap -> " +
                to_string(ovnis.GetCapacidad()) + "\tTiempo -> " + to_string(time);
            
            pintarParticula(base, BLUE);
            pintarConjunto(ovnis, GREEN);
            pintarConjunto(proyectiles, RED);

            DrawText("Pulse ESC to exit", 10, 10, 20, YELLOW);
            DrawText(s.c_str(), 10, 30, 20, YELLOW);
        }

        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
