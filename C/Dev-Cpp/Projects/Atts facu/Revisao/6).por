
programa{
	funcao inicio(){

		real salario, comissao, salario_t, vendas

		escreva(" Informe o salario: R$")
		leia(salario)

		escreva(" Informe o total em vendas: R$")
		leia(vendas)
		
		comissao = (vendas * 0.04)

		salario_t = salario + comissao

		escreva(" O salario total e: R$", salario_t)
		
		}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 252; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */