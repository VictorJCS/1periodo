
programa{
	funcao inicio(){

		real peso, peso_ema, peso_eng

		escreva(" Informe o peso: ")
		leia(peso)

		peso_ema = peso - (peso * 0.15)

		peso_eng = peso + (peso * 0.20)

		escreva(" O peso se o paciente engordar 20 porcento e: ", peso_eng," kg")
		
		escreva(" O peso se o paciente emagrecer 15 porcento e: ", peso_ema," kg")
		
		}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 249; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */