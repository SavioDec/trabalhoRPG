#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>

using namespace std;

class Player
{
public:
    int vida = 100;
    int ataque = 10;
    int defesa = 5;
    int magia = 15;
    int manaMaxima = 50;
    int xp = 0;
    int mana = manaMaxima;
    array<string, 5> mochila;

    void sobeNivel()
    {
        int escolha;
        cout << "Subiu de nível!!" << endl
             << "Qual atributo deseja upar?" << endl;
        cout << "1- Ataque - " << ataque << endl;
        cout << "2- Defesa - " << defesa << endl;
        cout << "3- Magia - " << magia << endl;
        cout << "4- mana - " << manaMaxima << endl;
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
    }

    // void magiaAtaque() {
    //     if (vida < 100) {
    //         vida += 15 + magia;
    //         if (vida > 100) {
    //             vida = 100;
    //         }
    //     } else {
    //         cout << "Sua vida está cheia!" << endl;
    //     }
    // }

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
        cout << "Mochila cheia! Não é possível adicionar mais itens." << endl;
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
        cout << "Item para usar: ";
        cin >> escolha;

        if (escolha > 0 && escolha <= 5 && !mochila[escolha - 1].empty())
        {
            string itemUsado = mochila[escolha - 1];
            cout << "Usando: " << itemUsado << endl;
            if (itemUsado == "Pocao de cura")
            {
                vida += 20;
                if (vida > 100)
                    vida = 100;
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
            cout << "Item não encontrado." << endl;
        }
    }
};

class Inimigo
{
public:
    int vida = 50;
    int ataque = 10;
    int defesa = 5;

    int atacar(Player &player)
    {
        unsigned seed = time(0);
        srand(seed);
        int danoInimigo = (rand() % 20) - player.defesa; // Dano aleatório do inimigo
        if (danoInimigo < 5)
            danoInimigo = 5; // O dano não pode ser negativo
        player.vida -= danoInimigo;
        cout << "Inimigo atacou, causando " << danoInimigo << " de dano!" << endl;
        return danoInimigo;
    }
};

void inimigoAleatorio(Player &player, Inimigo &inimigo)
{
    unsigned seed = time(0);
    srand(seed);
    inimigo.vida = (rand() % 50) + 50; // Reiniciar a vida do inimigo
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
    unsigned seed = time(0);
    srand(seed);
    int dano = player.ataque - inimigo.defesa;
    if (dano < 0) dano = 0; // O dano não pode ser negativo
       

    inimigo.vida -= dano;
}

void atacarPlayer(Inimigo &inimigo, Player &player)
{
    int danoInimigo;
    danoInimigo = inimigo.atacar(player);
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
        if (player.mana > 10)
        {
            if (dado > 18)
            {
                int dano = player.magia + 15;
                if (dano < 0) dano = 0; // O dano não pode ser negativo
                cout << "Dano critico!!!!\nBola de fogo foi conjurado! Causando: " << dano << " de dano" << endl;
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
                if (dano < 0) dano = 0; // O dano não pode ser negativo
                cout << "Bola de fogo foi conjurada! \nCausando: " << dano << " de dano" << endl;
                player.mana -= 10;
                inimigo.vida -= dano;
            }
        }else{
            cout << "Você não tem mana suficiente para conjurar a bola de fogo!" << endl;
        }
    }
    if (opcao == 2)
    {
        if (player.mana > 5){
            if(dado > 18){
                int cura = player.magia + 10;
                player.mana -= 5;
                player.vida += cura;
                if (player.vida > 100) player.vida = 100;
                cout << "voce curou: "<< cura << " de vida" << endl;

            }
            else if(dado > 5){
                player.mana -= 5;
                int cura = player.magia;
                player.vida += cura;
                if (player.vida > 100) player.vida = 100;
                cout << "voce curou: "<< cura << " de vida" << endl;

            }else{
                cout << "cura falhou!" << endl;
                player.mana -= 5;
            }
        }else{
            cout << "Você não tem mana suficiente para curar!" << endl;
        }
    }
    if (opcao == 3)
    {
        cout << "dado rolou: " << dado << endl;
        if (player.mana > 35)
        {
            if (dado > 18)
            {
                int dano = player.magia + 25;
                if (dano < 0) dano = 0; // O dano não pode ser negativo
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
                if (dano < 0) dano = 0; // O dano não pode ser negativo
                cout << "Lanca de raio foi conjurada! \nCausando: " << dano << " de dano" << endl;
                player.mana -= 35;
                inimigo.vida -= dano;
            }
        }else{
            cout << "Você não tem mana suficiente para conjurar a lanca de raio!" << endl;
        }
    }
}

int main()
{
    Player player;
    Inimigo inimigo;

    // Adicionar alguns itens iniciais na mochila
    player.adicionarItem("escudo");
    player.adicionarItem("Pocao de cura");
    player.adicionarItem("Pocao de mana");

    int escolha;
    

    do
    {
        if (inimigo.vida < 1)
        {
            inimigoAleatorio(player, inimigo);
            player.xp += 50;
        }
        if (player.xp >= 100)
        {
            player.sobeNivel();
            player.xp = 0;
        }

        // system("cls; clear");
        cout << "Vida do inimigo: " << inimigo.vida << endl;
        cout << "Defesa do inimigo: " << inimigo.defesa << endl
             << endl;
        cout << "Vida do jogador: " << player.vida << endl;
        cout << "Ataque do jogador: " << player.ataque << endl;
        cout << "Defesa do jogador: " << player.defesa << endl;
        cout << "Mana do jogador: " << player.mana << endl;
        cout << "XP do jogador: " << player.xp << endl
             << endl;
        cout << "O que deseja fazer? \n1- Atacar\n2- Magia\n3- Usar item\n4- Fugir\n";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            atacarInimigo(inimigo, player);
            if(inimigo.vida > 0) atacarPlayer(inimigo, player);
            break;
        case 2:
            conjuraMagia(player, inimigo);
            atacarPlayer(inimigo, player);
            break;
        case 3:
            player.usarItem();
            break;
        case 4:
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

    } while (player.vida > 0);

    if (player.vida < 1)
    {

        cout << "Você perdeu!!" << endl;
    }
}
