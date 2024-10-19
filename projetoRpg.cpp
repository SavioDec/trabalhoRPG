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
    int mana = manaMaxima;
    int xp = 0;
    array<string, 5> mochila;
    array<string, 5> equipamentos;

    void sobeNivel()
    {
        if (xp >= 100)
        {

            int escolha;
            cout << "Subiu de nivel!!" << endl
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
            cout << "Item nao encontrado." << endl;
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

    inimigo.vida = (rand() % 50) + 50; // Reiniciar a vida do inimigo
    if (player.ataque < inimigo.defesa)
    {
        inimigo.defesa = (rand() % 20) + 5; // Definicao de defesa aleatória
    }
    else
    {
        inimigo.defesa = (rand() % 5) + 5; // Definicao de defesa aleatória
    }
}

void atacarInimigo(Inimigo &inimigo, Player &player)
{
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
        dano;
    }
    else
    {
        cout << "inimigo desviou!!" << endl;
        dano = 0;
    }

    inimigo.vida -= dano;
}

void atacarPlayer(Inimigo &inimigo, Player &player)
{
    int danoInimigo = inimigo.atacar(player);
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

class Bau
{
public:
    string nome;

    void bau(Player &player)
    {

        int item = rand() % 5;

        if (item == 0)
        {
            nome = "Espada";
            player.ataque += 10;
            player.adicionarEquipamento("Espada");
        }
        else if (item == 1)
        {
            nome = "Pocao de cura";
            player.adicionarItem("Pocao de cura");
        }
        else if (item == 2)
        {
            nome = "Escudo";
            player.defesa += 4;
            player.adicionarEquipamento("Escudo");
        }
        else if (item == 3)
        {
            nome = "Anel Magico";
            player.magia += 5;
            player.manaMaxima += 10;
            player.adicionarEquipamento("Anel Magico");
        }
        else if (item == 4)
        {
            nome = "Pocao de mana";
            player.adicionarItem("Pocao de mana");
        }
        else
        {
            nome = "Armadura";
            player.defesa += 5;
            player.adicionarEquipamento("armadura");
        }
    }

    void mostrarItem(Player &player)
    {
        cout << "Voce encontrou um(a) " << nome << "!" << endl;
        cout << "Dano: " << player.ataque << endl;
        cout << "Defesa: " << player.defesa << endl;
        cout << "Magia: " << player.magia << endl;
        cout << "Mana maxima: " << player.manaMaxima << endl;

        
    }
};

int main()
{
    Player player;
    Inimigo inimigo;
    unsigned seed = time(0);
    srand(seed);
    int opcao;
    


     Bau meuBau;

    int escolha;
    int dado;
    do
    {
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
        dado = rand() % 100;
        if (dado < 40)
        {
            system("clear; cls");
            while (inimigo.vida > 0)
            {

                cout << "Um inimigo apareceu!!!!!!" << endl<<endl;; 
                cout << "Vida do inimigo: " << inimigo.vida << endl;
                cout << "Defesa do inimigo: " << inimigo.defesa << endl << endl;
                cout << "Vida do jogador: " << player.vida << endl;
                cout << "Ataque do jogador: " << player.ataque << endl;
                cout << "Defesa do jogador: " << player.defesa << endl;
                cout << "Mana do jogador: " << player.mana << endl;
                cout << "XP do jogador: " << player.xp << endl << endl;
                cout << "O que deseja fazer? \n1- Atacar\n2- Magia\n3- Usar item\n4- Mostrar equipamentos\n5- Fugir\n";
                cin >> escolha;

                switch (escolha)
                {
                case 1:
                    atacarInimigo(inimigo, player);
                    if (inimigo.vida > 0) atacarPlayer(inimigo, player);
                    break;
                case 2:
                    conjuraMagia(player, inimigo);
                    if (inimigo.vida > 0) atacarPlayer(inimigo, player);
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
                    cout << "Voce perdeu!!" << endl;
                    return 0;
                }
            }
        }else{
            //colocar o bau aqui
            meuBau.bau(player);
            meuBau.mostrarItem(player);

        }

    } while (opcao != 5);
}
