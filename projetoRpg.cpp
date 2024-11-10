#include "Player.hpp"
#include "Inimigo.hpp"
#include "Bau.hpp"

using namespace std;


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
    //Sistema de Magias "Bola de Fogo"
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
    //Sistema de Magias "Cura"
    {
        if (player.mana > 4)
        {
            if (dado > 18)
            {
                int cura = player.magia + 15;
                player.mana -= 5;
                player.vida += cura;
                if (player.vida > 100)
                    player.vida = 100;
                cout << "voce curou: " << cura << " de vida" << endl;
            }
            else if (dado > 5)
            {
                player.mana -= 5;
                int cura = player.magia + 6;
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
    //Sistema de Magias "lanca de raio"
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





int main()
{
    // variaveis para funcionamente
    Player player;
    Inimigo inimigo;
    unsigned seed = time(0);
    srand(seed);
    int opcao;
    int cenarios = 0;
    Bau meuBau;
    int escolha;
    int flag = 0;

    player.adicionarItem("Pocao de cura");
    player.adicionarItem("Pocao de mana");
    PausaJogo();

    do
    {
        //Gerador de vida do inimigo
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int dado = rand() % 100;
        if (inimigo.vida < 1)
        {
            cout << "Inimigo derrotado!!" << endl;
            inimigoAleatorio(player, inimigo);
            player.xp += 50;
        }
        //Sistema de Nivel do jogador
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
        //Gerador de Encontros
        dado = rand() % 100;
        if (dado < 70)
        {
            cenarios++;
            limpaTela();
            cout << "Um inimigo apareceu!!!!!!" << endl<<endl;; 

            while (inimigo.vida > 0)
            {
                // Sistema de combate
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
                 // Sistema de Combate
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
                    // Codigos de teste
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
                    //mensagem apos a morte

                    limpaTela();
                    cout << "Voce perdeu!!" << endl << endl;
                    PausaJogo();
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
        if(cenarios > 1 && flag == 0 ){
            //segundo cenario
            flag = 1;
            limpaTela();
            cout << "Entrando na Fortaleza Abandonada" << endl;
            cout <<"Ao entrar na antiga fortaleza, voce observa que tudo está em ruinas.\nVoce sente o ar frio enquanto explora o salao principal, onde o silencio e interrompido apenas pelos ecos dos seus passos. Algo, ou alguem, parece estar escondido nas sombras." << endl;
            PausaJogo();
        }
        if(cenarios > 3 && flag == 1){
            //terceiro cenario
            flag = 2;
            limpaTela();
            cout << "Entrando na Caverna dos Goblins" << endl;
            cout <<"Ao entrar na caverna onde ouve tambores a frente e uma quantidade enorme de sombras se movendo.\nA decisao agora e sua: fugir ou enfrenta-los diretamente." << endl;
            PausaJogo();
        }
        if(cenarios > 7 && flag == 2){
            //quarto cenario
            flag = 3;
            limpaTela();
            cout << "Entrando na Vila Abandonada" << endl;
            cout << "A pequena vila abandonada esta mergulhada em um silencio absoluto; um calafrio percorre sua espinha, e voce percebe que nao esta sozinho." << endl;
            PausaJogo();
        }
        if(cenarios > 15 && flag == 3){
            //finalizacao do jogo
            cout << "Entrando na cidade de Arvendral" << endl;
            cout << "Apos tantas provacoes, seu caminho chega ao fim diante dos portoes de Arvendral.\n A cidade acolhe voce em silencio, como se reconhecesse o peso de cada batalha travada.\n Em seus muros, voce encontra não so o descanso merecido, mas o encerramento de uma jornada que agora faz parte das lendas." << endl;
            PausaJogo();
            opcao = 5;
            return 0;
        }
        
    } while (opcao != 5);

    
}
