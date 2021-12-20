#include "trem.h"
#include <QtCore>
#include <iostream>

#define QTD 7
int estado_0[2];

QMutex regiao_trem[QTD];
QMutex mutex;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::updateVelocity(int value){
    velocidade = value;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(x == 420 && y == 20){ // entrar no trilho 0
                regiao_trem[0].lock();
            }
            else if(x == 440 && y == 120){ // vai sair do trilho 0 e usar trilhos: 1 e 2
                regiao_trem[1].lock();
                regiao_trem[2].lock();
            }
            else if(x == 420 && y == 140){ // saiu do trilho 0
                regiao_trem[0].unlock();
            }
            else if(x == 280  && y == 140){ // saiu do trilho 2
                regiao_trem[2].unlock();
            }
            else if(x == 170 && y == 120){ // saiu do trilho 1
                regiao_trem[1].unlock();
            }
            move();
            break;
        case 2:
            if(x == 710 && y == 120){ // usar trilhos: 3 e 4
                regiao_trem[3].lock();
                regiao_trem[4].lock();
            }
            else if(x == 550 && y == 140){ // saiu do trilho 4
                regiao_trem[4].unlock();
            }
            else if(x == 460 && y == 140){ // entrar no trilho 0
                regiao_trem[0].lock();
            }
            else if(x == 440 && y == 120){ // saiu do trilho 3
                regiao_trem[3].unlock();
            }
            else if(x == 460 && y == 20){  // saiu do trilho 0
                regiao_trem[0].unlock();
            }
            move();
            break;
        case 3:
            if(x == 150 && y == 140){ // entrar no trilho 1
                regiao_trem[1].lock();
            }
            else if(x == 280 && y == 140){ // sair do trilho 1 e entrar no trilho 5
                regiao_trem[1].unlock();
                regiao_trem[2].lock();
                regiao_trem[5].lock();
            }
            else if(x == 300 && y == 160){ // entrou no trilho 5 e saiu do trilho 2
                regiao_trem[2].unlock();
            }
            else if(x == 280 && y == 270){ // saiu do trilho 5
                regiao_trem[5].unlock();
            }
            move();
            break;
        case 4:
            if(x == 300 && y == 160){ // entrar no trilho 2
                regiao_trem[1].lock();
                regiao_trem[2].lock();
                regiao_trem[3].lock();
            }
            else if(x == 320 && y == 140){ // entrou no trilho 2
                regiao_trem[1].unlock();
                regiao_trem[5].unlock();
            }
            else if(x == 460 && y == 140){ // saiu do trilho 2 e entrou no trilho 3
                regiao_trem[2].unlock();
            }
            else if(x == 550 && y == 140){ // entrar no trilho 6
                regiao_trem[4].lock();
                regiao_trem[6].lock();
            }
            else if(x == 570 && y == 160){ // saiu do trilho 3 e entrou no trilho 6
                regiao_trem[3].unlock();
                regiao_trem[4].unlock();
            }
            else if(x == 550 && y == 270){ // saiu do trilho 6
                regiao_trem[6].unlock();
            }
            else if(x == 320 && y == 270){ // entrar no trilho 5
                regiao_trem[5].lock();
            }
            move();
            break;
        case 5:
            move();
            break;
        default:
            break;
        }
    }
}


/*
    if(((x >= 410 && x <= 440) || (x >= 460 && x <= 480))
            && (y >= 20 && y <= 140)){
        regiao_trem[0].lock();
        move();
        regiao_trem[0].unlock();
    }
    else if((x == 170 && (y >= 120 || y <= 170)) || ((x >= 150 && x <= 340) && y == 140)){
        regiao_trem[1].lock();
        move();
        regiao_trem[1].unlock();
    }
    else if(((x >= 280 && x <= 300) || (x >= 320 && x <= 340))
            && (y >= 140 && y <= 270)){
        regiao_trem[5].lock();
        move();
        regiao_trem[5].unlock();
    }
    else if(((x >= 550 && x <= 570) || (x >= 590 && x <= 610))
            && (y >= 140 && y <= 270)){
        regiao_trem[6].lock();
        move();
        regiao_trem[6].unlock();
    }
    else if(((x >= 550 && x <= 570) || (x >= 590 && x <= 610))
            && (y >= 140 && y <= 270)){
        regiao_trem[6].lock();
        move();
        regiao_trem[6].unlock();
    }
    else{
        move();
    }
*/

void Trem::move(){
    switch(ID){
    case 1:     //Trem 1
        if (y == 20 && x <440)
            x+=10;
        else if (x == 440 && y < 140)
            y+=10;
        else if (x > 170 && y == 140)
            x-=10;
        else{
            y-=10;
        }
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 2: //Trem 2
        if (y == 20 && x <710)
            x+=10;
        else if (x == 710 && y < 140)
            y+=10;
        else if (x > 440 && y == 140)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 3: //Trem 3
        if (y == 140 && x <300)
            x+=10;
        else if (x == 300 && y < 270)
            y+=10;
        else if (x > 50 && y == 270)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 4: //Trem 4
        if (y == 140 && x <570)
            x+=10;
        else if (x == 570 && y < 270)
            y+=10;
        else if (x > 300 && y == 270)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    case 5: //Trem 5
        if (y == 140 && x <830)
            x+=10;
        else if (x == 830 && y < 270)
            y+=10;
        else if (x > 570 && y == 270)
            x-=10;
        else
            y-=10;
        emit updateGUI(ID, x,y);    //Emite um sinal
        break;
    default:
        break;
    }
    msleep(velocidade);
}




