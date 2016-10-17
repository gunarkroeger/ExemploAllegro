#include "Jogo.h"

Jogo::Jogo()
{
     
}

Jogo::~Jogo()
{
   destroy_bitmap(buffer);  // Destr�i a imagem;       
}

void Jogo::Inicializar()
{
     buffer = create_bitmap(800, 600); 
     M1.setbuffer(buffer);  
     M1.Inicializar();
     /* As fun��es foram colocardas nesse m�todo "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gr�fica est� sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     t�m suas construtoras 'lidas' antes da inicializa��o da biblioteca,
     portanto o programa n�o reconhece as fun��es e ocorre o erro.
        Desta forma, os objetos s�o inicializados depois da biblioteca gr�fica
     portanto, n�o h� problemas. */          
}

void Jogo::Iniciar()
{
    M1.setjogadores(P1, P2); // Associa os jogadores ao Mapa. 
    M1.setmenu(M);           // Associa o Menu ao mapa. 
    M1.Entrar();             // 'entra' na �rea do mapa. (inicia o mapa)
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
