/*********************************************************
 * Project : ETMod
 *
 * File    : be_ai_gen.h
 * Desc    : Genetic selection.
 *
 * Status  : Accepted
 *
 *********************************************************/

#ifndef __BE_AI_GEN_H__
#define __BE_AI_GEN_H__

int GeneticParentsAndChildSelection(int numranks, float *ranks,
                                    int *parent1, int *parent2,
                                    int *child);

#endif /* __BE_AI_GEN_H__ */
