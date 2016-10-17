#ifndef _MENU_H_
#define _MENU_H_

#include "Jogo.h"

class Menu
{
    private:
           BITMAP* buffer;           
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jog�-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           BITMAP* fundoR; // Fundo do menu de raiz.
           BITMAP* fundoC; // Fundo do menu de cr�ditos.
           BITMAP* fundoS; // Fundo do menu de sair.
           BITMAP* cursor; // O imagem do navio que indica qual op��o est� selecionada.
           Jogo* J;
           bool sair;      // Vari�vel para indicar o processo de sa�da
                           // e evitar que o menu seja aberto novamente quando
                           // o bot�o sair for pressionado.
           
           
    public:
           Menu();
           ~Menu();
           
           void Inicializar();
           void Iniciar();
           void Raiz();       // Menu principal.
           void Creditos();   // Tela de cr�ditos.
           bool Sair();       // Menu de pergunta para confirma��o de sa�da.
           
           /* Sets */
           void setbuffer( BITMAP* B);
           void setfundoraiz( BITMAP* R);
           void setfundocreditos( BITMAP* C);
           void setfundosair( BITMAP* S);
           void setcursor( BITMAP* C);
           void setjogo( Jogo* Jo);
           /* Gets */

};

#endif
