#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H

#include "Jogo.h"

class Principal
{
    private:
           Jogo J;       // O Jogo em si.
           Personagem P; // O Personagem.
    public:
           Principal();
           ~Principal();
           void Executar();      
};

#endif
