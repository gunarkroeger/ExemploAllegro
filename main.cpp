/* 
########################################################################
# Exemplo de Allegro orientado a objetos elaborado por:                #
# Jorge Leandro Francisco                                              # 
# Monitor da Disciplina Fundamentos de Programa��o 2                   #
# do curso de Engenharia Eletr�nica da UTFPR                           #
# Prof. Jean M. Sim�o                                                  #
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
Para trocar o �cone do execut�vel:
     
1 - Escolher um �cone (.ico) personalizado e coloc�-lo em uma 
    pasta � escolha. De prefer�ncia na pasta onde est�o os arquivos do 
    jogo, como as imagens.     

2 - Abrir o projeto do jogo e ir no menu 
    "Projeto -> Op��es do Projeto -> Geral -> Navegar" 
    
3 - Procurar o �cone e abrir.
*/

/* 
Para que o c�digo fique mais coerente com os princ�pios de orienta��o 
a objetos, as fun��es de inicializa��o da biblioteca gr�fica foram 
retiradas do 'main' onde estavam implementadas de forma procedural e 
incorporadas em uma classe GerenciadorGr�fico. 
O objeto gerenciador � agregado � classe Principal. 
*/
