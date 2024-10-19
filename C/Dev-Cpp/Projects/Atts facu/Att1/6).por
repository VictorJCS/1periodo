programa
{
	
	funcao inicio()
	{
	real salario, vendas, comissao, salario_t

	escreva(" Informe o salario: ")
	leia(salario)

	escreva(" Informe as vendas efetuadas:: ")
	leia(vendas)

	comissao = (vendas * 0.04)

	escreva(" Sua comissao foi: ", comissao)

	salario_t = salario + comissao
	
	escreva("\n Seu salario total foi: ", salario_t)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 32; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */