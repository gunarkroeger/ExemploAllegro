#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"

class Jogador : public Personagem
{
    private:
            const short int num; 
            // Varável que informa qual é o número do jogador
            // jogador 1, jogador 2 etc...
            
    public:
            Jogador();
            Jogador(const short int N);
            ~Jogador();
            
            /* Gets */
            const short int getnum();
            
            /* Movimentação */
            void Movimento();
            
            /* Colisão */
            void testecolisao(Jogador* P2, int Xmin, int Xmax, int Ymin, int Ymax);
           
};

#endif

/* coordenadas da imagem grande

BAIXO X 11 Y 5 ||  X 140 Y 358         -> L = 129
 
CIMA X 173 Y 5 ||  X 302 Y 358         -> A = 353


ESQUERDA X 349 Y 3 ||  X  702  Y 132   -> L = 353

DIREITA X 348 Y 154 || X = 701 Y 283   -> A = 129

*/
