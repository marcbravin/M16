// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
using namespace std;

//Variables de uso

int picas[13];
int diamantes[13];
int corazones[13];
int treboles[13];
bool gameOver = false;
int eleccion = 0;

//Variables Jugador 1

string player1 = "Jugador";
int pointsPlayer1 = 0;
bool surrender1 = false;
bool winnerP1 = false;
bool loserP1 = false;

//Variables Jugador 2 

string player2 = "Crupier";
int pointsPlayer2 = 0;
bool surrender2 = false;
bool winnerP2 = false;
bool loserP2 = false;

//Funciones//Inicializa cualquier array con sus 12 posiciones a 1 de esta forma, indicamos que todas las cartas están disponibles si una posición está a 0, esa carta ya está repartida y no se repite
void inicializaArray(int(&pArray)[13]) {    
    for (int i = 0; i < 13; i++) {
pArray[i] = 1;
    }
}
//Comprueba aleatoriamente si ha de dar picas o diamantes
//y busca una carta al azar. Hasta que no encuentre una posición
// a 1, no asigna esa carta, cuyo valor es el indiceCarta + 1
void chooseCards(int& totalPoints, string player) {    bool choosed = false;
int indiceCarta = 0;
string tipoPalo;
while (!choosed) {
    //Elije una carta del 1 al 12        
    indiceCarta = rand() % 13;        
    //Comprueba las Copas        
    int tipoCarta = rand() % 4;        
    if (tipoCarta == 0) {
    if (picas[indiceCarta] == 1) {
        //devuelve la carta                
        picas[indiceCarta] = 0;                
        choosed = true;
        tipoPalo = "picas";
    }
    //Comprueba los diamantes        
    }        
    else if (tipoCarta == 1) {
    if (diamantes[indiceCarta] == 1) {
        //devuelve la tarjeta                
        diamantes[indiceCarta] = 0;                
        choosed = true;
        tipoPalo = "diamantes";
    }
}
        else if (tipoCarta == 2) {
            if (corazones[indiceCarta] == 1) {
                //devuelve la tarjeta                
                corazones[indiceCarta] = 0;                
                choosed = true;
                tipoPalo = "corazones";
            }
        }
        else if (tipoCarta == 3) {
            if (treboles[indiceCarta] == 1) {
                //devuelve la tarjeta                
                treboles[indiceCarta] = 0;                
                choosed = true;
                tipoPalo = "treboles";
            }
        }
    }
    //SI ES UN AS, PREGUNTAR SI ES UN 1 O UN 11    
    if (indiceCarta == 0) {    
        //LOGICA DEL CROUPIERE        
        if (player == "crupier") {            
            if (totalPoints <= 10) {
                //ELIGE UN 11;                
                totalPoints += 11;            }
            else {
                totalPoints += 1;
            }
            cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
        }
        else {
            //LÓGICA DEL JUGADOR            
            do {                
                //PREGUNTAR SI QUEREMOS UN 1 O UN 11                
                cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y de momento tiene un total de " << totalPoints << endl;                
                cout << "Quieres que cuente como un 1 o como un 11?" << endl;
                //TENDREMOS QUE ASEGURAR QUE EL USUARIO HA ELEGIDO UN 1 O UN 11. SI NO, TIENE QUE VOLVER A PREGUNTAR                
                cin >> eleccion;                
                if (eleccion == 1) {
                totalPoints += 1;
                }
                else if (eleccion == 11) {
                    totalPoints += 11;
                }
                else {
                    cout << "Numero incorrecto vuelve a introducir un 1 o un 11 " << endl;
                }
            } while (eleccion != 1 && eleccion != 11);
        }
    }
    //SI ES UNA FIGURA(INDICE>9) LA CARTA VALE 10 SIEMPRE    
    else if (indiceCarta > 9) {        
        totalPoints += 10;
    }
    //SI LA CARTA ES MAYOR QUE 1 y MENOR QUE 10    
    else {        
        totalPoints += indiceCarta + 1;
    }
    if (indiceCarta == 10) {
        cout << "El jugador " << player << " ha sacado una J de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
    }
    else if (indiceCarta == 11) {
        cout << "El jugador " << player << " ha sacado una Q de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
    }
    else if (indiceCarta == 12) {
        cout << "El jugador " << player << " ha sacado una K de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
    }
    else if (indiceCarta == 0) {
        cout << "El jugador " << player << " tiene un total de " << totalPoints << endl;
    }
    else {
        cout << "El jugador " << player << " ha sacado un " << indiceCarta + 1 << " de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
    }
   }
   bool checkPoints(int& points, bool& winner, bool& loser) {
       if (points == 21) {
           winner = true;
           return true;
       }
       else if (points > 21) {
           loser = true;
           return true;
       }
       return false;
   }
   bool checkWhoWins(int points1, int points2, bool& winner2) {
       if (points2 > points1) {
           winner2 = true;
           return true;
       }
       else {
           return false;
       }
   }
   int main()
   {
       inicializaArray(picas);
       inicializaArray(diamantes);
       inicializaArray(treboles);
       inicializaArray(corazones);
       srand(time(NULL));
       //primer reparto de cartas    
       chooseCards(pointsPlayer1, player1);    
       chooseCards(pointsPlayer1, player1);
       //Puede pasar que ganemos o perdamos nada más comenzar    
       surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);    
       chooseCards(pointsPlayer2, player2);
       while (!surrender1) {
           int choice = 0;
           //Comienza el juego con el jugador 1        
           while (choice != 1 && choice != 2) {            
               cout << "Tienes " << pointsPlayer1 << ".Quieres pedir carta?" << endl;
           cout << "1.- Si" << endl;
           cout << "2.- No" << endl;
           cin >> choice;
           if (choice != 1 && choice != 2) {
               cout << "Por favor, elije una opción válida." << endl;
           }
       }
       if (choice == 1) {
           chooseCards(pointsPlayer1, player1);
           surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
           //comprueba si se ha pasado o ha ganado la partida        
           }        
       else {
           //Si no quiere carta, es turno de la banca            
           surrender1 = true;        }
       }
       //Termina el turno del jugador 1. Hay que comprobar si ha ganado (winnerP1) o perdido ya (loserP1), o si la banca tiene que tirar    
       if (winnerP1 && winnerP2) {        
           //EMPATAN        
           cout << player1 << " y " << player2 << " empatan" << endl;    }
       else if (winnerP1) {
           cout << player1 << " gana y " << player2 << " pierde" << endl;
       }
       else if (loserP1) {
           cout << player1 << " pierde y " << player2 << " gana" << endl;
       }
       else {
           //turno de la banca        
           while (!surrender2) {            
               chooseCards(pointsPlayer2, player2);
           surrender2 = checkPoints(pointsPlayer2, winnerP2, loserP2);
           if (!surrender2) {
               //Comprueba si la banca ya gana por puntos                
               surrender2 = checkWhoWins(pointsPlayer1, pointsPlayer2, winnerP2);            }
           }
           if (winnerP2 && winnerP1) {
               //EMPATAN            
               cout << player2 << " y " << player1 << " empatan" << endl;        }
           else if (winnerP2) {
               cout << player2 << " gana y " << player1 << " pierde" << endl;
           }
           else if (loserP2) {
               cout << player2 << " pierde y " << player1 << " gana" << endl;
           }
           }
       }