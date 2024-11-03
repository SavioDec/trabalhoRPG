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
{
    int vida = 100;
    int vidaMax = 100;
    int ataque = 10;
    int defesa = 5;
    int magia = 15;
    int manaMaxima = 50;
};

void PausaJogo(){
    #ifdef _WIN32
            system("pause");
        #else
        cout << "...Presione Enter para continuar...";
            int c = getchar();
        #endif
}
void limpaTela() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
}

void HistoriaPerson(int &person){
    //historia dos personagens

    if(person == 1) {
        cout << endl << "Sir Aldric cresceu em uma vila humilde, treinado por seu pai, um cavaleiro que servia o rei. Ele aprendeu desde cedo o valor da honra e jurou proteger os fracos, sempre fiel ao dever." << endl;
    }
    if(person == 2) {
        cout << endl << "Kael cresceu nas ruas caoticas de Eldorath, sobrevivendo como ladrao. Conhecido como 'Mao-leve' por sua destreza, ele se tornou uma lenda local, especialista em furtos e esquemas" << endl;
    }
    if(person == 3) {
        cout << endl <<"Elenion nasceu em uma familia de estudiosos e se dedicou a magia desde jovem. Em sua torre isolada, ele buscava desvendar os segredos antigos, acumulando vasto conhecimento." << endl;
    }
    if(person == 4) {
        cout << endl <<"Thalia foi criada em um templo dedicado a deusa da justica. Ela jurou proteger os inocentes e lutar contra o mal, guiada pela fe e pela espada." << endl;
    }
    if(person == 5) {
        cout << endl << "Gromak nasceu nas gelidas planicies de Tharok, onde a força era a unica lei. Ele se tornou lider de sua tribo apos a morte de seu pai, conhecido por sua ferocidade em batalha." << endl;
    }
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
    cout << "1- Mago - Elenion, o Sabio (Poder Magico: 35 ; Mana: 120 ; vida: 100 ; defesa: 5 ; ataque: 10; )" << endl;
    cout << "2- Cavaleiro - Sir Aldric de Valon (Poder Magico: 10 ; Mana: 50 ; vida: 100 ; defesa: 15 ; ataque: 20 )" << endl;
    cout << "3- Ladino - Kael 'Mao-Leve' (Poder Magico: 10 ; Mana: 50 ; vida: 100 ;defesa: 7 ; ataque: 30 )" << endl;
    cout << "4- Paladino - Thalia, a Portadora da Luz (Poder Magico: 25 ; Mana: 70 ; vida : 100 ; defesa: 10 ; ataque: 15 )" << endl;
    cout << "5- Barbaro - Gromak, o Impiedoso (Poder Magico: 0 ; Mana: 0 ; vida: 150 ; defesa: 5 ; ataque: 45 )" << endl;
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
        classe.manaMaxima = 120;
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
