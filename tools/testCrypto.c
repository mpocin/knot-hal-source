/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include <errno.h>
#include <unistd.h>
#include "src/hal/sec/security.h"
#include "src/hal/sec/nanoecc/ecc.h"

#define _MIN(a, b)		((a) < (b) ? (a) : (b))
#define MESSAGE                 "T"
#define MESSAGE_SIZE            (sizeof(MESSAGE))
/*Hard-coded Keys*/

/* key pairs labeled 3 and 4, for secp256r1 curves */
/*Local Key Pair*/
uint8_t private_key[NUM_ECC_DIGITS] = {
  0xA8, 0x78, 0x51, 0x3A, 0x5D, 0xDA, 0x9C, 0x33, \
    0x35, 0xB4, 0x05, 0x06, 0xE1, 0x1E, 0x88, 0xD9, \
    0x52, 0xBF, 0x4F, 0x98, 0xF3, 0xB3, 0x0E, 0xB8, \
  0x64, 0x35, 0x0F, 0x9D, 0xB7, 0x35, 0x0C, 0xAE \
};
EccPoint public_key= {
  {0x1F, 0x37, 0x66, 0xC9, 0x8A, 0xDB, 0x2D, 0x0C, \
  0xAF, 0x8C, 0x02, 0xE4, 0x47, 0x05, 0x9C, 0xB0, \
  0xFE, 0x6F, 0x1A, 0x40, 0x3D, 0x57, 0x70, 0x0D, \
  0x9B, 0x3F, 0x34, 0xCD, 0xD4, 0xCF, 0xDC, 0x8C  }, \
  {0x36, 0x6D, 0x48, 0x58, 0xAD, 0x64, 0xE5, 0xE4,  \
  	0xAE, 0x9A, 0xC1, 0x49, 0xEF, 0xD9, 0x94, 0x75, \
  0xF8, 0x24, 0x7B, 0x9A, 0xCF, 0x18, 0x53, 0xF9,  \
  0x41, 0xB0, 0xC5, 0x5A, 0x86, 0xB9, 0x60, 0xF4  }
};
/* Foreign Key */
EccPoint foreign_key= {
  {0x06, 0xE6, 0x9C, 0xFE, 0x72, 0x2A, 0xAC, 0x71, \
  	0x55, 0xA3, 0x4A, 0x9A, 0xD1, 0x6B, 0x21, 0xA7, \
  0x51, 0xCC, 0xE8, 0xA0, 0x5C, 0x65, 0xC2, 0xA8, \
  0x77, 0xDD, 0x9D, 0x4C, 0x3D, 0xDC, 0x7A, 0x03}, \
  {0x84, 0x7E, 0x37, 0xC3, 0x08, 0x70, 0x17, 0xDB, \
  	0xCD, 0xF1, 0x31, 0xD0, 0x79, 0xEF, 0x2E, 0xB0, \
  0xF2, 0x09, 0xBA, 0xDF, 0x57, 0xE8, 0xA5, 0x3D, \
  0x47, 0xE1, 0x1D, 0x42, 0x1B, 0x32, 0x3F, 0x96}
};

  /*Local and Foreign Keys for Enc/Decription*/
//local key pair
uint8_t private_4[NUM_ECC_DIGITS] = {0xA3, 0xB0, 0x24, 0xBB, 0xA9, \
	0xA2, 0xC2, 0xC0, 0xB2, 0xE6, 0xEB, 0x32, 0xF7, 0x40, 0xF3, 0xD7, \
	0xB6, 0xFA, 0x27, 0x2F, 0xA8, 0x09, 0xE7, 0x6D, 0xF7, 0x7F, 0xF8, \
	0xB5, 0x7F, 0x0D, 0xDF, 0xBE};
uint8_t public_4x[NUM_ECC_DIGITS] = {0x03, 0x7A, 0xDC, 0x3D, 0x4C, \
	0x9D, 0xDD, 0x77, 0xA8, 0xC2, 0x65, 0x5C, 0xA0, 0xE8, 0xCC, 0x51, \
	0xA7, 0x21, 0x6B, 0xD1, 0x9A, 0x4A, 0xA3, 0x55, 0x71, 0xAC, 0x2A, \
	0x72, 0xFE, 0x9C, 0xE6, 0x06};
uint8_t public_4y[NUM_ECC_DIGITS] = {0x96, 0x3F, 0x32, 0x1B, 0x42, 0x1D, \
	0xE1, 0x47, 0x3D, 0xA5, 0xE8, 0x57, 0xDF, 0xBA, 0x09, 0xF2, 0xB0, 0x2E, \
	0xEF, 0x79, 0xD0, 0x31, 0xF1, 0xCD, 0xDB, 0x17, 0x70, 0x08, 0xC3, 0x37, \
	0x7E, 0x84};
// public foreign key
uint8_t public_3x[NUM_ECC_DIGITS] = {0x8C, 0xDC, 0xCF, 0xD4, 0xCD, 0x34, \
	0x3F, 0x9B, 0x0D, 0x70, 0x57, 0x3D, 0x40, 0x1A, 0x6F, 0xFE, 0xB0, 0x9C, \
	0x05, 0x47, 0xE4, 0x02, 0x8C, 0xAF, 0x0C, 0x2D, 0xDB, 0x8A, 0xC9, 0x66, \
	0x37, 0x1F};
uint8_t public_3y[NUM_ECC_DIGITS] = {0xF4, 0x60, 0xB9, 0x86, 0x5A, 0xC5, \
	0xB0, 0x41, 0xF9, 0x53, 0x18, 0xCF, 0x9A, 0x7B, 0x24, 0xF8, 0x75, 0x94, \
	0xD9, 0xEF, 0x49, 0xC1, 0x9A, 0xAE, 0xE4, 0xE5, 0x64, 0xAD, 0x58, 0x48, \
	0x6D, 0x36};
/*uint8_t private_3[NUM_ECC_DIGITS] = { 0x8C, 0xDC, 0xCF, 0xD4, 0xCD, 0x34,
0x3F, 0x9B, 0x0D, 0x70, 0x57, 0x3D, 0x40, 0x1A, 0x6F, 0xFE, 0xB0, 0x9C,
0x05, 0x47, 0xE4, 0x02, 0x8C, 0xAF, 0x0C, 0x2D, 0xDB, 0x8A, 0xC9, 0x66,
0x37, 0x1F};
*/
// set IV
uint8_t iv = 0x00;
uint8_t i;

int main(int argc, char *argv[])
{
	/*secret key and auxiliar buffer*/
	uint8_t bytebuffer[32];
	uint8_t skey[32];
	int ciphertext_len, decryptedtext_len, err;
	uint8_t keys[96];

	if (generate_keys(keys) != 1)
		return -1;

	err = derive_secret(public_3x, public_3y, private_4, public_4x, public_4y,
									skey, &iv);

	printf("Derive Err: %d\n", err);

	printf("Secret key:\n");
	for (i = 0; i < 32; i++)
		printf("0x%02X ", (unsigned) skey[i]);

	memcpy(bytebuffer, MESSAGE, MESSAGE_SIZE);

	printf("\nPlain text in hexa:\n");
	for (i = 0; i < MESSAGE_SIZE; i++)
		printf("0x%02X ", (unsigned) bytebuffer[i]);

	ciphertext_len = encrypt(bytebuffer, MESSAGE_SIZE, skey, &iv);

	printf("\nciphertext:  len(%d):\n", ciphertext_len);
	for (i = 0; i < ciphertext_len; i++)
		printf("0x%02X ", (unsigned) bytebuffer[i]);
	printf("\n");
	/*End of Encryption*/

	decryptedtext_len = decrypt(bytebuffer, ciphertext_len, skey, &iv);
	printf("decipheredtext:  len(%d):\n", decryptedtext_len);

	for (i = 0; i < decryptedtext_len; i++)
		printf("0x%02X ", (unsigned) bytebuffer[i]);
	printf("\n");

	/*End of Decryption*/
	return 0;
}
