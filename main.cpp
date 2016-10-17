/* 
########################################################################
# Exemplo de Allegro orientado a objetos elaborado por:                #
# Jorge Leandro Francisco                                              # 
# Monitor da Disciplina Fundamentos de Programação 2                   #
# do curso de Engenharia Eletrônica da UTFPR                           #
# Prof. Jean M. Simão                                                  #
########################################################################
*/

#include "Principal.h"

int main() 
{
    
    Principal ObjPrincipal;
    
	return 0;
	
}
END_OF_MAIN()

/*
Para trocar o ícone do executável:
     
1 - Escolher um ícone (.ico) personalizado e colocá-lo em uma 
    pasta à escolha. De preferência na pasta onde estão os arquivos do 
    jogo, como as imagens.     

2 - Abrir o projeto do jogo e ir no menu 
    "Projeto -> Opções do Projeto -> Geral -> Navegar" 
    
3 - Procurar o ícone e abrir.
*/

/* 
Para que o código fique mais coerente com os princípios de orientação 
a objetos, as funções de inicialização da biblioteca gráfica foram 
retiradas do 'main' onde estavam implementadas de forma procedural e 
incorporadas em uma classe GerenciadorGráfico. 
O objeto gerenciador é agregado à classe Principal. 
*/
