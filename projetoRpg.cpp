#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
// #include<raylib.h>
// opengl 
//sfml
// #include <SFML/Graphics.hpp>
using namespace std;

class Player {
public:
    int vida = 100;
    int ataque = 10;
    int defesa = 5;
    int magia = 0;
    int xp = 0;
    string mochila[5];
    
    void sobeNivel() {
        int escolha;
        cout << "Subiu de nível!!" << endl << "Qual atributo deseja upar?" << endl;
        cout << "1- Ataque - " << ataque << endl;
        cout << "2- Defesa - " << defesa << endl;
        cout << "3- Magia(cura) - " << magia << endl;
        cin >> escolha;
        switch (escolha) {
            case 1:
                ataque += 1;
                break;
            case 2:
                defesa += 1;
                break;
            case 3:
                magia += 1;
                break;
            default:
                break;
        }
    }

    void magiaCura() {
        if (vida < 100) {
            vida += 15 + magia;
            if (vida > 100) {
                vida = 100;
            }
        } else {
            cout << "Sua vida está cheia!" << endl;
        }
    }

    void adicionarItem(const string& item) {
        for (int i = 0; i < 5; i++) {
            if (mochila[i].empty()) {
                mochila[i] = item;
                cout << "Item '" << item << "' adicionado na mochila." << endl;
                return;
            }
        }
        cout << "Mochila cheia! Não é possível adicionar mais itens." << endl;
    }

    void usarItem() {
        cout << "Itens na mochila: " << endl;
        for (int i = 0; i < 5; i++) {
            if (!mochila[i].empty()) {
                cout << i + 1 << "- " << mochila[i] << endl;
            }
        }
        int escolha;
        cout << "Item para usar: ";
        cin >> escolha;

        if (escolha > 0 && escolha <= 5 && !mochila[escolha - 1].empty()) {
            string itemUsado = mochila[escolha - 1];
            cout << "Usando: " << itemUsado << endl;
            if (itemUsado == "estus") {
                vida += 20;
                if (vida > 100) vida = 100;
                cout << "Vida atual: " << vida << endl;
            }
            mochila[escolha - 1] = "";
        } else {
            cout << "Item não encontrado." << endl;
        }
    }
};

class Inimigo {
public:
    int vida = 50;
    int ataque = 40;
    int defesa = 5;

   int atacar(Player &player) {
        unsigned seed = time(0);
        srand(seed);
        int danoInimigo = (rand()  % 20) - player.defesa; // Dano aleatório do inimigo
        if (danoInimigo < 0) danoInimigo = 0; // O dano não pode ser negativo
        player.vida -= danoInimigo; 
        // cout << "Inimigo atacou, causando " << danoInimigo << " de dano!" << endl;
        return danoInimigo;
    }
};

int main() {
    Player player;
    Inimigo inimigo;

    // Adicionar alguns itens iniciais na mochila
    player.adicionarItem("estus");
    player.adicionarItem("escudo");

    int escolha;

    do {
        if (inimigo.vida < 1) {
            char opcao;
            cout << "Você venceu!!" << endl << "Deseja continuar? [s/n]";
            cin >> opcao;
            system("cls");
            if (opcao == 's' || opcao == 'S') {
                inimigo.vida = (rand() % 50) + 50; // Reiniciar a vida do inimigo
                if(player.ataque < inimigo.defesa){
                inimigo.defesa = (rand() % 20) + 5; // Definição de defesa aleatória
                }else{
                    inimigo.defesa = (rand() % 5) + 5; // Definição de defesa aleatória
                }
                player.xp += 50; 
            } else {
                return 0;
            }
        }

        if (player.xp >= 100) {
            player.sobeNivel();
            player.xp = 0;
        }
        
        system("cls");

        cout << "Vida do inimigo: " << inimigo.vida << endl;
        cout << "Defesa do inimigo: " << inimigo.defesa << endl << endl;
        cout << "Vida do jogador: " << player.vida << endl;
        cout << "Ataque do jogador: " << player.ataque << endl;
        cout << "Defesa do jogador: " << player.defesa << endl;
        cout << "XP do jogador: " << player.xp << endl << endl;
        cout << "O que deseja fazer? \n1- Atacar\n2- Curar\n3- Usar item\n4- Fugir\n";
        cin >> escolha;

        int dano = player.ataque - inimigo.defesa;
        if (dano < 0) dano = 0; // O dano não pode ser negativo
        int danoInimigo;

        switch (escolha) {
            case 1:
                inimigo.vida -= dano;
                danoInimigo = inimigo.atacar(player);
                break;
            case 2:
                player.magiaCura();
                break;
            case 3:
                player.usarItem();
                break;
            case 4:
                return 0;
            default:
                break;
        }

    } while (player.vida > 0);

    if (player.vida <= 0) {
        cout << "Você perdeu!!" << endl;
        return 0;
    }
}
