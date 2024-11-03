#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include "Player.hpp"

using namespace std;

class Bau
{
public:
    string nome;
    int flag = 0;
    void bau(Player &player)
    {

        int item = rand() % 5;

        if (item == 0)
        {
            flag = 1;
            nome = "Espada";
            player.ataque += 10;
            player.adicionarEquipamento("Espada");
        }
        else if (item == 1)
        {
            flag = 0;
            nome = "Pocao de cura";
            player.adicionarItem("Pocao de cura");
        }
        else if (item == 2)
        {
            flag = 1;
            nome = "Escudo";
            player.defesa += 4;
            player.adicionarEquipamento("Escudo");
        }
        else if (item == 3)
        {
            flag = 1;
            nome = "Anel Magico";
            player.magia += 5;
            player.manaMaxima += 10;
            player.adicionarEquipamento("Anel Magico");
        }
        else if (item == 4)
        {
            flag = 0;
            nome = "Pocao de mana";
            player.adicionarItem("Pocao de mana");
        }
        else
        {
            flag = 1;
            nome = "Armadura";
            player.defesa += 5;
            player.adicionarEquipamento("armadura");
        }
    }

    void mostrarItem(Player &player)
    {
        if(flag == 1){
            cout << "Voce encontrou um(a) " << nome << "!" << endl;
            cout << "Novo dano: " << player.ataque << endl;
            cout << "nova defesa: " << player.defesa << endl;
            cout << "Novo poder magico: " << player.magia << endl;
            cout << "Nova mana maxima: " << player.manaMaxima << endl;
        }else if(flag == 0){
            cout << "Voce encontrou um(a) " << nome << "!" << endl;
        }
        
    }
};