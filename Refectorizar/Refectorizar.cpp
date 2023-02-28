#include <iostream>

using namespace std;

//variables de combate
int damage;

//Variables del enemigo1 
bool enemyIsAlive1 = true;
int enemyHP1 = 200;
int enemyDamage1;
int attack1;
string enemyname1 = "Zombie";

//Variables del enemigo2
bool enemyIsAlive2 = true;
int enemyHP2 = 500;
int enemyDamage2;
int attack2;
string enemyname2 = "Vampiro";

//Variables del heroe
string heroName;
int heroHP = 200;
bool heroIsAlive = true;
int tipoAtaque = 0;
int heroDamage;

//Ataques del heroe
int daga = 400;
int golpe = 300;
int milagros = 600;
int limit = 7;
int ataque;

void gameStart() {
    cout << "¿Cual es el nombre del heroe?\n";
    cin >> heroName;
    cout << "\nEl nombre del heroe es: " << heroName << "\n";
    cout << "Los enemigos " << enemyname1 << " y " << enemyname2 << " acaban de aparecer\n";
}

int chooseEnemy() {
    tipoAtaque = 0;

    cout << "A que enemigo quieres atacar?\n";
    cout << "zombie - 1\n";
    cout << "vampiro - 2\n";
    cin >> tipoAtaque;

    while (tipoAtaque != 1 && tipoAtaque != 2)

        if (tipoAtaque == 1 || tipoAtaque == 2) {
            cout << " Atacas al enemigo " << tipoAtaque << "\n";
            return tipoAtaque;
        }
        else if (tipoAtaque != 1 && tipoAtaque != 2) {
            cout << "Has fallado\n";
            cout << "Vuelve a intentarlo\n";
            cout << "zombie - 1\n";
            cout << "vampiro - 2\n";
            cin >> tipoAtaque;
        }
}

void attackChose(int& enemyHP) {
    if (ataque == 1) {
        enemyHP = enemyHP - daga;
    }
    else if (ataque == 2) {
        enemyHP = enemyHP - golpe;
    }
    else if (ataque == 3) {
        if (limit != 0) {
            enemyHP = enemyHP - milagros;
            limit -= 7;
        }
        else {
            cout << "No tienes milagros\n";
        }
    }
    else
    {
        "Has fallado";
    }
}

bool checkEnemyStatus(bool& enemyIsAlive, int& enemyHP, string& enemyname) {
    if (enemyHP <= 0) {
        enemyHP = 0;
        enemyIsAlive = false;
        cout << "Has matado a " << enemyname << "\n";
    }
    else {
        return true;
    }
}

void chooseAtaque() {

    cout << "Que ataque quieres:\n";
    cout << "daga - 1\n";
    cout << "golpe - 2\n";
    cout << "milagros - 3\n" "Quedan " << limit << " ataques restantes\n";
    cin >> ataque;

    if (enemyIsAlive1) {
        if (tipoAtaque == 1) {
            attackChose(enemyHP1);
            enemyIsAlive1 = checkEnemyStatus(enemyIsAlive1, enemyHP1, enemyname1);
        }
    }
    else {
        cout << "\n" << enemyname1 << " ya esta muerto\n";
    }

    if (enemyIsAlive2) {
        if (tipoAtaque == 2) {
            attackChose(enemyHP2);
            enemyIsAlive2 = checkEnemyStatus(enemyIsAlive2, enemyHP2, enemyname2);
        }
    }
    else {
        cout << "\n" << enemyname2 << " ya esta muerto\n";
    }

    cout << "\nA " << enemyname1 << " le quedan " << enemyHP1 << " puntos de vida\n";
    cout << "\nA " << enemyname2 << " le quedan " << enemyHP2 << " puntos de vida\n";
}

void enemyAttack() {

    enemyDamage1 = rand() % 99;
    enemyDamage2 = rand() % 99;

    if (enemyIsAlive1 && enemyIsAlive2) {
        damage = enemyDamage1 + enemyDamage2;
        heroHP = heroHP - damage;
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "\nLos enemigos te han hecho " << damage << " te quedan " << heroHP << " puntos de vida\n";
    }
    else if (enemyIsAlive1 && enemyIsAlive2 == false) {
        heroHP = heroHP - enemyDamage1;
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "\n" << enemyname1 << " te ha hecho " << enemyDamage1 << " te quedan " << heroHP << " puntos de vida\n";
    }
    else if (enemyIsAlive1 == false && enemyIsAlive2) {
        heroHP = heroHP - enemyDamage2;
        if (heroHP <= 0) {
            heroHP = 0;
        }
        cout << "\n" << enemyname2 << " te ha hecho " << enemyDamage2 << " te quedan " << heroHP << " puntos de vida\n";
    }
    else if (enemyIsAlive1 == false && enemyIsAlive2 == false) {
        cout << "Has ganado\n";
    }
}

bool checkHeroStatus() {
    if (heroHP <= 0) {
        cout << "\nEl enemigo te ha matado\n";
        return false;
    }
    else
    {
        return true;
    }
}

int main() {
    srand(time(NULL));
    gameStart();

    while ((enemyIsAlive1 || enemyIsAlive2) && heroIsAlive) {
        //ELEGIMOS AL ENEMIGO 
        chooseEnemy();
        //ESCOGEMOS EL ATAQUE 
        chooseAtaque();
        //ATACAN LOS ENEMIGOS Y COMPROBAMOS SI ESTAN VIVOS
        enemyAttack();
        // EL HEROE ESTA VIVO
        heroIsAlive = checkHeroStatus();
    }
}