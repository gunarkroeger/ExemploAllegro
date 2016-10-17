#include "Jogo.h"

Jogo::Jogo()
{
     
}

Jogo::~Jogo()
{
   destroy_bitmap(buffer);  // Destrói a imagem;       
}

void Jogo::Inicializar()
{
     buffer = create_bitmap(800, 600); 
     M1.setbuffer(buffer);  
     M1.Inicializar();
     /* As funções foram colocardas nesse método "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gráfica está sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     têm suas construtoras 'lidas' antes da inicialização da biblioteca,
     portanto o programa não reconhece as funções e ocorre o erro.
        Desta forma, os objetos são inicializados depois da biblioteca gráfica
     portanto, não há problemas. */          
}

void Jogo::Iniciar()
{
    M1.setjogadores(P1, P2); // Associa os jogadores ao Mapa. 
    M1.setmenu(M);           // Associa o Menu ao mapa. 
    M1.Entrar();             // 'entra' na área do mapa. (inicia o mapa)
}


/* Sets */
    void Jogo::setjogadores(Jogador* P, Jogador* PP)
    {
        P1 = P;
        P2 = PP;
    }
    
    void Jogo::setmenu(Menu* ME)
    {
        M = ME;
    }
    
/* Gets */
    BITMAP* Jogo::getbuffer()
    {
        return buffer;        
    }
