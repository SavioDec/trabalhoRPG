#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <fstream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits



using namespace std;

#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

struct Classes
//cria os objetos das classes do personagem
{
    int vida = 100;
    int vidaMax = 100;
    int ataque = 10;
    int defesa = 5;
    int magia = 15;
    int manaMaxima = 50;
};

void PausaJogo(){
    // pausa o jogo

    #ifdef _WIN32
            system("pause");
    #else
        cout << "...Presione Enter para continuar..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    #endif
}
void limpaTela() {
    // limpa o prompt
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void HistoriaPerson(int &person){
    //historia dos personagens
    
    if(person == 1) {
        cout << endl <<"Elenion nasceu em uma familia de estudiosos e se dedicou a magia desde jovem. Em sua torre isolada, ele buscava desvendar os segredos antigos, acumulando vasto conhecimento.\nEm uma noite de estudo, Elenion invocou acidentalmente uma entidade sombria que comecou a distorcer a realidade ao seu redor, ameaçando destrui-lo." << endl;
    }
    if(person == 2) {
        cout << endl << "Sir Aldric cresceu em uma vila humilde, treinado por seu pai, um cavaleiro que servia o rei. Ele aprendeu desde cedo o valor da honra e jurou proteger os fracos, sempre fiel ao dever.\nEm uma missão para recuperar um artefato sagrado, Aldric e caiu em uma emboscada\nSozinho e ferido, ele se escondeu em uma caverna, onde pediu forças aos deuses." << endl;
    }
    if(person == 3) {
        
        cout << endl << "Kael cresceu nas ruas caoticas de Eldorath, sobrevivendo como ladrao. Conhecido como 'Mao-leve' por sua destreza, ele se tornou uma lenda local, especialista em furtos e esquemas\nKael foi contratado para roubar um artefato magico, mas caiu em uma armadilha que o transportou para uma dimensao ilusoria.\nPreso, ele precisava escapar..." << endl;
    }
    if(person == 4) {
        cout << endl <<"Thalia foi criada em um templo dedicado a deusa da justica. Ela jurou proteger os inocentes e lutar contra o mal, guiada pela fe e pela espada.\nDurante uma missão, Thalia enfrentou um poderoso demonio que dominava um vilarejo.\nFerida e com sua espada quebrada, ela se viu enfraquecida, mas não derrotada." << endl;
    }
    if(person == 5) {
        cout << endl << "Gromak nasceu nas gelidas planicies de Tharok, onde a força era a unica lei. Ele se tornou lider de sua tribo apos a morte de seu pai, conhecido por sua ferocidade em batalha.\nDurante uma cacada, Gromak e seus guerreiros enfrentaram uma criatura colossal, o 'Devorador de Montanhas'. Quase todos foram mortos, mas Gromak não recuou.\nAo ataca-lo novamente o 'Devorador de Montanhas' o pega e arremessa Gromak para muito longe." << endl;
    }

    // Cenario inicial
    cout << endl << "Voce entrou na Floresta Enfeiticada" << endl;
    cout <<"Voce caminha por uma trilha sinuosa, cercado por arvores altas e uma nevoa densa. A sensacao de estar sendo observado e constante, e algo se move nas sombras, mas voce nao consegue ver o que eh." << endl;
    cout << "Ao verem sua situacao os deuses lhe favorecem concedendo-o duas pocoes" << endl;
    PausaJogo();
};

//cadastra o nome do personagem
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
        arquivo.close();
    }else{
    
        arquivo.open("Personagem.txt", ios::out);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "Digite o nome do seu Personagem (Escolha um nome bem criativo): ";
        getline(cin, userName);

        cout<<"Data de hoje(DD/MM/AAAA) : ";
        getline(cin, data);

        arquivo<<"Nome do personagem : "<< userName << endl << "Data de Login : "<<data;
        cout<<"Personagem cadastrado com sucesso !!"<<endl;
        arquivo.close();
    }
    cout<<"Boa aventura !"<<endl<<endl;

}

//function para escolha da classe do jogado
Classes personagens()
{

    

    Classes classe;
    int person;
    
    cout << "Escolha sua classe: " << endl;
    cout << "1- Mago - Elenion, o Sabio (Poder Magico: 35 ; Mana: 150 ; vida: 100 ; defesa: 5 ; ataque: 10; )" << endl;
    cout << "2- Cavaleiro - Sir Aldric de Valon (Poder Magico: 10 ; Mana: 50 ; vida: 100 ; defesa: 15 ; ataque: 20 )" << endl;
    cout << "3- Ladino - Kael 'Mao-Leve' (Poder Magico: 10 ; Mana: 50 ; vida: 100 ;defesa: 7 ; ataque: 30 )" << endl;
    cout << "4- Paladino - Thalia, a Portadora da Luz (Poder Magico: 25 ; Mana: 70 ; vida : 100 ; defesa: 10 ; ataque: 15 )" << endl;
    cout << "5- Barbaro - Gromak, o Impiedoso (Poder Magico: 0 ; Mana: 5 ; vida: 130 ; defesa: 5 ; ataque: 35 )" << endl;
    cin >> person;

    CadastrarPlayer();
    
    switch (person)
    {
    case 1:
    {
        //Mago
        HistoriaPerson(person);
        classe.vidaMax = 100;
        classe.magia = 35;
        classe.manaMaxima = 150;
        classe.defesa = 5;
        classe.ataque = 10;
        return classe;
        break;
    }
    case 2:
    {
        //cavaleiro
        HistoriaPerson(person);
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
        HistoriaPerson(person);
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
        HistoriaPerson(person);
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
        HistoriaPerson(person);
        classe.vidaMax = 130;
        classe.magia = 0;
        classe.manaMaxima = 5;
        classe.defesa = 5;
        classe.ataque = 35;
        return classe;
        break;
    }
    case 2808:
    {
        //Modo desenvolvedor 
        classe.vidaMax = 1000;
        classe.magia = 350;
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
