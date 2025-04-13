/**
 * @file recomendador.h
 * @author Equipa de LI3
 * @date 25 Nov 2024
 * @brief Header file do recomendador
 */
#ifndef RECOMENDER_H
#define RECOMENDER_H

/**
 * @brief Calcula recomendações de utilizadores
 *
 * @param idUtilizadorAlvo Id do utilizador alvo para gerar recomendações
 * @param matrizClassificacaoMusicas Uma matriz contendo para cada utilizador
 * (linhas) o número de vezes que ouviu músicas de cada género de música
 * (colunas)
 * @param idsUtilizadores Um array contendo os ids de cada utilizador seguindo a
 * mesma ordem da matriz
 * @param nomesGeneros Um array contendo o nome de cada género de música
 * seguindo a mesma ordem da matriz
 * @param numUtilizadores O número total de utilizadores
 * @param numGeneros O número total de géneros de música
 * @param numRecomendacoes O número de recomendações para calcular
 * @return Um array de ids de utilizadores recomendados com tamanho
 * <b>numRecomendacoes</b>
 * @note O número máximo de recomendações é <b>numUtilizadores - 1</b>. Caso
 * <b>numRecomendacoes</b> ultrapasse este valor, o mesmo será automaticamente
 * truncado.
 */
char **recomendaUtilizadores(char *idUtilizadorAlvo,
                             int **matrizClassificacaoMusicas,
                             char **idsUtilizadores, char **nomesGeneros,
                             int numUtilizadores, int numGeneros,
                             int numRecomendacoes);

#endif
