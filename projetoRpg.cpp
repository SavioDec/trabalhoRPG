#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <fstream>
#include "Personagem.hpp"
#include "Player.hpp"
#include "Inimigo.hpp"
#include "Bau.hpp"

using namespace std;


void limpaTela() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
}


void conjuraMagia(Player &player, Inimigo &inimigo)
{
    unsigned seed = time(0);
    srand(seed);
    int opcao;
    int dado = rand() % 20;
    cout << "mana: " << player.mana << endl;
    cout << "1 - Bola de fogo (10 mana)" << endl;
    cout << "2 - Cura (5 mana)" << endl;
    cout << "3 - Lanca de raio (35 mana)" << endl;
    cin >> opcao;

    if (opcao == 1)
    {
        cout << "dado rolou: " << dado << endl;
        if (player.mana > 9)
        {
            if (dado > 18)
            {
                int dano = player.magia + 15;
                if (dano < 0)
                    dano = 0; // O dano nao pode ser negativo
                cout << "DANO CRITICO!!!!\nBola de fogo foi conjurado! Causando: " << dano << " de dano" << endl;
                player.mana -= 10;
                inimigo.vida -= dano;
            }
            else if (dado < 3)
            {
                cout << "bola de fogo falhou!" << endl;
                player.mana -= 5;
            }
            else if (dado > 2)
            {
                int dano = player.magia;
                if (dano < 0)
                    dano = 0; // O dano nao pode ser negativo
                cout << "Bola de fogo foi conjurada! \nCausando: " << dano << " de dano" << endl;
                player.mana -= 10;
                inimigo.vida -= dano;
            }
        }
        else
        {
            cout << "Voce nao tem mana suficiente para conjurar a bola de fogo!" << endl;
        }
    }
    if (opcao == 2)
    {
        if (player.mana > 4)
        {
            if (dado > 18)
            {
                int cura = player.magia + 10;
                player.mana -= 5;
                player.vida += cura;
                if (player.vida > 100)
                    player.vida = 100;
                cout << "voce curou: " << cura << " de vida" << endl;
            }
            else if (dado > 5)
            {
                player.mana -= 5;
                int cura = player.magia;
                player.vida += cura;
                if (player.vida > 100)
                    player.vida = 100;
                cout << "voce curou: " << cura << " de vida" << endl;
            }
            else
            {
                cout << "cura falhou!" << endl;
                player.mana -= 5;
            }
        }
        else
        {
            cout << "Voce nao tem mana suficiente para curar!" << endl;
        }
    }
    if (opcao == 3)
    {
        cout << "dado rolou: " << dado << endl;
        if (player.mana > 34)
        {
            if (dado > 18)
            {
                int dano = player.magia + 25;
                if (dano < 0)
                    dano = 0; // O dano nao pode ser negativo
                cout << "Dano critico!!!!\nLanca de raio foi conjurada! Causando: " << dano << " de dano" << endl;
                player.mana -= 35;
                inimigo.vida -= dano;
            }
            else if (dado < 3)
            {
                cout << "Lanca de raio falhou!" << endl;
                player.mana -= 15;
            }
            else if (dado > 2)
            {
                int dano = player.magia + 10;
                if (dano < 0)
                    dano = 0; // O dano nao pode ser negativo
                cout << "Lanca de raio foi conjurada! \nCausando: " << dano << " de dano" << endl;
                player.mana -= 35;
                inimigo.vida -= dano;
            }
        }
        else
        {
            cout << "Voce nao tem mana suficiente para conjurar a lanca de raio!" << endl;
        }
    }
}

void CadastrarPlayer(){
    limpaTela();
    string userName;
    string data;
    string linha;

    fstream arquivo ;
    arquivo.open("Personagem.txt", ios::in);
     
    if(arquivo){
        while(getline(arquivo, linha)){
            cout<< linha << endl;
        }
    }else{
        arquivo.open("Personagem.txt", ios::out);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "Digite seu nome(Escolha um nome bem criativo): ";
        getline(cin, userName);

        cout<<"Data de hoje(DD/MM/AAAA) : ";
        getline(cin, data);

        arquivo<<"Nome do personagem : "<< userName << endl << "Data de Login : "<<data;
        cout<<"Personagem cadastrado com sucesso !!"<<endl;
        arquivo.close();
       
        arquivo.close();
    }
    cout<<"Boa aventura !"<<endl<<endl;

}



int main()
{
    Player player;
    Inimigo inimigo;
    unsigned seed = time(0);
    srand(seed);
    int opcao;
    int vitoria;
    Bau meuBau;
    int escolha;
    string userName;
    string data;



    CadastrarPlayer();

    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int dado = rand() % 100;
        if (inimigo.vida < 1)
        {
            cout << "Inimigo derrotado!!" << endl;
            inimigoAleatorio(player, inimigo);
            player.xp += 50;
        }
        player.sobeNivel();
        cout << "qual caminho deseja escolher? \n";
        cout << "1 - Norte \n";
        cout << "2 - Sul \n";
        cout << "3 - Leste \n";
        cout << "4 - Oeste \n";
        cout << "5 - sair \n";
        cin >> opcao;
        if(opcao == 5){
            return 0;
        }
        dado = rand() % 100;
        if (dado < 70)
        {
            vitoria++;
            limpaTela();
            cout << "Um inimigo apareceu!!!!!!" << endl<<endl;; 

            while (inimigo.vida > 0)
            {

                cout << "Vida do inimigo: " << inimigo.vida << endl;
                cout << "Defesa do inimigo: " << inimigo.defesa << endl << endl;
                cout << "Vida do jogador: " << player.vida << endl;
                cout << "Ataque do jogador: " << player.ataque << endl;
                cout << "Defesa do jogador: " << player.defesa << endl;
                cout << "Poder Magico do jogador: " << player.magia << endl;
                cout << "Mana do jogador: " << player.mana << endl;
                cout << "XP do jogador: " << player.xp << endl << endl;
                cout << "O que deseja fazer? \n1- Atacar\n2- Magia\n3- Usar item\n4- Mostrar equipamentos\n5- Fugir\n";
                cin >> escolha;

                switch (escolha)
                {
                case 1:
                    atacarInimigo(inimigo, player);
                    if (inimigo.vida > 0) inimigo.atacarPlayer(player);
                    break;
                case 2:
                    conjuraMagia(player, inimigo);
                    if (inimigo.vida > 0) inimigo.atacarPlayer(player);
                    break;
                case 3:
                    player.usarItem();
                    break;
                case 4:
                    player.mostraEquipamento();
                    break;
                case 5:
                    return 0;
                    break;
                case 2001:
                    player.vida += 100;
                    break;
                case 2002:
                    player.ataque += 100;
                    break;
                case 2003:
                    player.magia += 100;
                    break;
                case 2004:
                    player.manaMaxima += 100;
                    break;
                default:
                    break;
                }
                if (player.vida < 1)
                {
                    system("cls; clear");
                    cout << "Voce perdeu!!" << endl << endl;
                    system("pause");
                    return 0;
                }
            }
        }else if(dado > 30){
            //colocar o bau aqui
            meuBau.bau(player);
            meuBau.mostrarItem(player);
        }else{
            cout << "Nao achou nada" << endl;
        }
        if(vitoria > 49){
            limpaTela();
            cout << "Voce ganhou!!" << endl << endl;
            system("pause");
            return 0;
    }
    } while (opcao != 5);

    
}
