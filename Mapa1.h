#ifndef _MAPA1_H_
#define _MAPA1_H_

#include "Jogador.h"
#include "Cenario.h"
#include "Tanque.h"
#include "Peixe.h" 

class Menu;

/*
  A classe Mapa1 representa um conjunto de várias telas. 
Um conceito de cenário mais amplo, a localidade do jogador no mundo do jogo.
O mundo do jogo seria composto por vários Mapas e esses mapas compostos
por várias telas.  
  Tela é a porção do mapa que está momentaneamente sendo exibida.
*/

class Mapa1
{
    private:
           BITMAP* buffer;
           Menu* M;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           Jogador* P1;   // Jogador 1;
           Jogador* P2;   // Jogaodr 2;
           Cenario Mar;   // Parte de água no cenário do jogo.
           Cenario Terra; // Parte terrestre no cenario do jogo.
           Tanque T1;     // Inimigo Tanque.
           Peixe Px1;     // Inimigo Peixe.
           Peixe Px2;     // Inimigo Peixe.
           Peixe Px3;     // Inimigo Peixe.
           bool inicio;
           
    public:
           Mapa1();
           ~Mapa1();
           
           void Inicializar();
           void Entrar();
           bool Sair();
           void Tela1();
           void Tela2();
           void Tela3();
           
           /* Sets */
           void setjogadores(Jogador* P, Jogador* PP);
           void setbuffer( BITMAP* B );
           void setmenu( Menu* ME);
           
           /* Gets */
           BITMAP* getbuffer();
};

#endif
