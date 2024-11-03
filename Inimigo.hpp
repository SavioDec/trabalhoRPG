#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include "Player.hpp"

using namespace std;


class Inimigo
{
public:
    int vida = 50;
    int ataque = 10;
    int defesa = 5;

    int atacarPlayer(Player &player)
    {
        unsigned seed = time(0);
        srand(seed);

        int danoInimigo = (rand() % 20) - player.defesa; // Dano aleatório do inimigo
        if (danoInimigo < 5)
            danoInimigo = 5; // O dano nao pode ser negativo
        player.vida -= danoInimigo;
        cout << "Inimigo atacou, causando " << danoInimigo << " de dano!" << endl;
        return danoInimigo;
    }
};

void inimigoAleatorio(Player &player, Inimigo &inimigo)
{
    unsigned seed = time(0);
    srand(seed);

    inimigo.vida = (rand() % 60) + 50; // Reiniciar a vida do inimigo
    if (player.ataque < inimigo.defesa)
    {
        inimigo.defesa = (rand() % 20) + 5; // Definição de defesa aleatória
    }
    else
    {
        inimigo.defesa = (rand() % 5) + 5; // Definição de defesa aleatória
    }
}



void atacarInimigo(Inimigo &inimigo, Player &player)
{
    system("cls; clear");
    unsigned seed = time(0);
    srand(seed);
    int dado = rand() % 20;
    int dano = player.ataque - inimigo.defesa;
    if (dano < 0)
        dano = 0; // O dano nao pode ser negativo
    if (dado > 18)
    {
        cout << "dano critico!! causado: " << dano << endl;
        dano = (player.ataque + 10) - inimigo.defesa;
    }
    else if (dado > 10)
    {
        cout << "dano causado: " << dano << endl;
        dano = (player.ataque + 5) - inimigo.defesa;
    }
    else if (dado > 5)
    {
        cout << "dano causado: " << dano << endl;
        dano = player.ataque - inimigo.defesa;
    }
    else
    {
        cout << "inimigo desviou!!" << endl;
        dano = 0;
    }

    inimigo.vida -= dano;
}

