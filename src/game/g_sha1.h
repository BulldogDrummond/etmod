/*********************************************************
 * Project : ETMod
 *
 * File    : g_sha1.h
 * Desc    : Sha-1 declarations.
 *
 * Note    : Original source was sha1.h
 *           Copyright (C) 1998, 2009
 *           Paul E. Jones <paulej@packetizer.com>
 *           All Rights Reserved
 *
 * Status  : Pending
 *
 *********************************************************/

#ifndef _SHA1_H_
#define _SHA1_H_

/*
 *  This structure will hold context information for the hashing
 *  operation
 */
typedef struct SHA1Context
{
    unsigned Message_Digest[5]; /* Message Digest (output)          */

    unsigned Length_Low;        /* Message length in bits           */
    unsigned Length_High;       /* Message length in bits           */

    unsigned char Message_Block[64]; /* 512-bit message blocks      */
    int Message_Block_Index;    /* Index into message block array   */

    int Computed;               /* Is the digest computed?          */
    int Corrupted;              /* Is the message digest corruped?  */
} SHA1Context;

/*
 *  Function Prototypes
 */
void SHA1Reset(SHA1Context *);
int SHA1Result(SHA1Context *);
void SHA1Input(SHA1Context *,
               const unsigned char *,
               unsigned);

#endif
