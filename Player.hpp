#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include "Personagem.hpp"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:

    
    Classes personagem = personagens();
    int vidaMax = personagem.vidaMax;
    int manaMaxima = personagem.manaMaxima;
    int mana = personagem.manaMaxima;
    int vida = personagem.vidaMax;
    int defesa = personagem.defesa;
    int ataque = personagem.ataque;
    int magia = personagem.magia;
    int xp = 0;
    array<string, 5> mochila;
    array<string, 5> equipamentos;

    void sobeNivel()
    {
        if (xp >= 100)
        {

            int escolha;
            cout << "Subiu de nivel!!" << endl;
            cout << "Qual atributo deseja upar?" << endl;
            cout << "1- Ataque - " << ataque << endl;
            cout << "2- defesa - " << defesa << endl;
            cout << "3- Magia - " << magia << endl;
            cout << "4- Mana maxima - " << manaMaxima << endl;
            cin >> escolha;
            switch (escolha)
            {
            case 1:
                ataque += 1;
                break;
            case 2:
                defesa += 1;
                break;
            case 3:
                magia += 1;
                break;
            case 4:
                manaMaxima += 5;
                break;
            default:
                break;
            }
            xp = 0;
        }
    }

    void adicionarItem(const string &item)
    {
        for (int i = 0; i < 5; i++)
        {
            if (mochila[i].empty())
            {
                mochila[i] = item;
                cout << "Item '" << item << "' adicionado na mochila." << endl;
                return;
            }
        }
        cout << "Mochila cheia! Nao é possivel adicionar mais itens." << endl;
        for (int i = 0; i < 5; i++)
        {
            if (equipamentos[i].empty())
            {
                equipamentos[i] = item;
                cout << "Item '" << item << "' adicionado nos equipamentos." << endl;
                return;
            }
        }
        cout << "equipamento cheio! Nao é possivel adicionar mais itens." << endl;
    }
    void adicionarEquipamento(const string &item)
    {
        for (int i = 0; i < 5; i++)
        {
            if (equipamentos[i].empty())
            {
                equipamentos[i] = item;
                cout << "Item '" << item << "' adicionado nos equipamentos." << endl;
                return;
            }
        }
        cout << "equipamento cheio! Nao é possivel adicionar mais itens." << endl;
    }

    void mostraEquipamento(){
        cout << "equipamentos: " << endl;
        for (int i = 0; i < 5; i++)
        {
                cout << i + 1 << "- " << equipamentos[i] << endl;
        }
    }

    void usarItem()
    {
        cout << "Itens na mochila: " << endl;
        for (int i = 0; i < 5; i++)
        {
            if (!mochila[i].empty())
            {
                cout << i + 1 << "- " << mochila[i] << endl;
            }
        }
        
        int escolha;
        cout << "6- sair" << endl;
        cout << "Item para usar: ";
        cin >> escolha;

        if (escolha > 0 && escolha <= 5 && !mochila[escolha - 1].empty())
        {
            string itemUsado = mochila[escolha - 1];
            cout << "Usando: " << itemUsado << endl;
            if (itemUsado == "Pocao de cura")
            {
                vida += 30;
                if (vida > vidaMax)
                    vida = vidaMax;
                cout << "Vida atual: " << vida << endl;
            }
            if (itemUsado == "Pocao de mana")
            {
                mana += 30;
                if (mana > manaMaxima)
                    mana = manaMaxima;
                cout << "Mana atual: " << mana << endl;
            }
            mochila[escolha - 1] = "";
        }
        else
        {
            cout << "Item nao encontrado." << endl;
        }
    }
};



#endif
