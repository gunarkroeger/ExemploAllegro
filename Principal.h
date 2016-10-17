#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H

#include "Menu.h"

class Principal
{
    private:
           GerenciadorGrafico Allegro; // Gerenciador do Allegro.
           Menu M;       // Menu principal do jogo.
           Jogo J;       // O Jogo em si.
           Jogador  P1;  // O Jogador 1.
           Jogador2 P2;  // O Jogador 2.
            
    public:
           Principal();
           ~Principal();
           void Executar();      
           void Inicializar();
};

#endif
