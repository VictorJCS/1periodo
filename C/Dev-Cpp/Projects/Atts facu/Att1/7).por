programa
{
	
	funcao inicio()
	{
		real peso, peso_m, peso_g

		escreva(" Informe o peso: ")
		leia(peso)

		peso_g = peso + (peso * 0.15)

		peso_m = peso - (peso * 0.20)

		escreva(" O seu peso caso engorde 15% e: ",peso_g)
		
		escreva("\n O seu peso caso emagreca 20% e: ",peso_m)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 289; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */