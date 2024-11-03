#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

using namespace std;

#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

struct Classes
{
    int vida = 100;
    int vidaMax = 100;
    int ataque = 10;
    int defesa = 5;
    int magia = 15;
    int manaMaxima = 50;
};

void HistoriaPerson(){
    //historia dos personagens

    cout << "uma historia qualquer" << endl;
    #ifdef _WIN32
            system("pause");
        #else
        cout << "...Presione Enter para continuar...";
            int c = getchar();
        #endif
};

//function para escolha da classe do jogado
Classes personagens()
{

    Classes classe;
    int person;
    HistoriaPerson();
    cout << "Escolha sua classe: " << endl;
    cout << "1- Mago (Poder Magico: 35 ; Mana: 120 ; vida: 100 ; defesa: 5 ; ataque: 10; )" << endl;
    cout << "2- Guerreiro (Poder Magico: 10 ; Mana: 50 ; vida: 100 ; defesa: 15 ; ataque: 20 )" << endl;
    cout << "3- Ladino (Poder Magico: 10 ; Mana: 50 ; vida: 100 ;defesa: 7 ; ataque: 30 )" << endl;
    cout << "4- Paladino (Poder Magico: 25 ; Mana: 70 ; vida : 100 ; defesa: 10 ; ataque: 15 )" << endl;
    cout << "5- Barbaro (Poder Magico: 0 ; Mana: 0 ; vida: 150 ; defesa: 5 ; ataque: 45 )" << endl;
    cin >> person;
    
    
    switch (person)
    {
    case 1:
    {
        //Mago
        classe.vidaMax = 100;
        classe.magia = 35;
        classe.manaMaxima = 120;
        classe.defesa = 5;
        classe.ataque = 10;
        return classe;
        break;
    }
    case 2:
    {
        //Guerreiro
        classe.vidaMax = 100;
        classe.magia = 10;
        classe.manaMaxima = 50;
        classe.defesa = 15;
        classe.ataque = 20;
        return classe;
        break;
    }
    case 3:
    {
        // LADINO
        classe.vidaMax = 100;
        classe.magia = 10;
        classe.manaMaxima = 70;
        classe.defesa = 7;
        classe.ataque = 30;
        return classe;
        break;
    }
    case 4:
    {
        //PALADINO 
        classe.vidaMax = 100;
        classe.magia = 25;
        classe.manaMaxima = 90;
        classe.defesa = 10;
        classe.ataque = 15;
        return classe;
        break;
    }
    case 5:
    {
        //Barbaro
        classe.vidaMax = 150;
        classe.magia = 0;
        classe.manaMaxima = 0;
        classe.defesa = 5;
        classe.ataque = 45;
        return classe;
        break;
    }
    case 2808:
    {
        //Modo desenvolvedor 
        classe.magia = 200;
        classe.manaMaxima = 1000;
        classe.defesa = 500;
        classe.ataque = 350;
        return classe;
        break;
    }
    default:
        break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return classe;
};

#endif
