#ifndef _MENU_H_
#define _MENU_H_

#include "Jogo.h"

class Menu
{
    private:
           BITMAP* buffer;
           BITMAP* fundoR; // Fundo do menu de raiz.
           BITMAP* fundoC; // Fundo do menu de créditos.
           BITMAP* cursor; // O imagem do navio que indica qual opção está selecionada.
           Jogo* J;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           
           
           
           
    public:
           Menu();
           ~Menu();
           
           void Inicializar();
           void Iniciar();
           void Raiz();       // Menu principal.
           void Creditos();   // Tela de créditos.
           
           /* Sets */
           void setbuffer( BITMAP* B);
           void setfundoraiz( BITMAP* R);
           void setfundocreditos( BITMAP* C);
           void setcursor( BITMAP* C);
           void setjogo( Jogo* Jo);
           /* Gets */

};

#endif
