#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Player{
    int vida = 100;
    int ataque = 10;
    int defesa;
    int magia;
    int xp;
};
struct Inimigo{
    int vida;
    int ataque;
    int defesa;
};

void SobeNivel(Player &player){
    
    int escolha;
    cout << "Subiu de nível!!" <<endl << "qual atributo deseja upar?"<< endl;
    cout << "1- Ataque - " << player.ataque << endl;
    cout << "2- defesa - " << player.defesa << endl;
    cout << "3- magia(cura) - " << player.defesa << endl;
    cin >> escolha;
    switch (escolha)
    {
    
    case 1:
        player.ataque += 1;
        break;
    case 2:
        player.defesa += 1;
        break;
    case 3:
        player.magia += 1;
        break;
    
    default:
        break;
    }
}
int ataqueInimigo(Inimigo &inimigo, Player &player){
    unsigned seed = time(0);

    srand(seed);
    int danoInimigo = rand()%14;
    player.vida -= danoInimigo; 
    cout << "inimigo atacou, causando: " << danoInimigo << endl;
    return danoInimigo;
    
}

int ataca(Player &player, Inimigo &inimigo){
    int dano = player.ataque - inimigo.defesa;
    return dano;
}
void magia(Player &player){
    if(player.vida < 100){ 
        player.vida += 15 + player.magia;
        if(player.vida > 100){
            player.vida = 100;
        }
    }else{
        cout << "Sua vida está cheia!" << endl;
    }
}



int main(){
    Player player;
    Inimigo inimigo;
    player.vida = 0;
    player.ataque = 10;
    player.defesa = 5;
    player.magia = 0;
    player.xp = 0;
    inimigo.vida = 50;
    inimigo.defesa = 5;
    inimigo.ataque = 40;
    int escolha;
    
    do{
    system("cls");
    if(inimigo.vida < 1){
        char opcao;
        cout << "Você venceu!!" << endl << "deseja continuar?[s/n]";
        cin >> opcao;
        system("cls");
        if(opcao == 's' || opcao == 'S'){
            inimigo.vida = 100; 
            player.xp +=50; 
            
        }else{
            return 0;
        }
        
    }
    
    if(player.xp == 100){
        SobeNivel(player);
        player.xp = 0;
    }
    cout << "vida do inimigo: " << inimigo.vida << endl;
    cout << "defesa do inimigo: " << inimigo.defesa << endl << endl << endl;
    cout << "vida do jogador: " << player.vida << endl;
    cout << "ataque do jogador: " << player.ataque << endl;
    cout << "defesa do jogador: " << player.defesa << endl;
    cout << "xp do jogador: " << player.xp << endl << endl << endl;
    cout << "deseja: \n" << "1- atacar" << endl << "2- curar" << endl << "3- fugir" << endl;
    cin >> escolha;

    switch (escolha)
    {
    case 1:
        inimigo.vida -= ataca(player , inimigo);
        ataqueInimigo(inimigo, player);
        break;
    case 2:
    {
        magia(player);
        break;
    }
    case 3: 
        return 0;
    default:
        break;
    }
    
    }while(player.vida > 0);
    
        cout << "Você perdeu!!" << endl;
        return 0;
  

}