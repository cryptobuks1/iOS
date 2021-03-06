/* dsa-sha256-verify.c

   The DSA publickey algorithm, using SHA-256 (FIPS186-3).

   Copyright (C) 2010 Niels Möller

   This file is part of GNU Nettle.

   GNU Nettle is free software: you can redistribute it and/or
   modify it under the terms of either:

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at your
       option) any later version.

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at your
       option) any later version.

   or both in parallel, as here.

   GNU Nettle is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see http://www.gnu.org/licenses/.
*/

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include "dsa-compat.h"

int
dsa_sha256_verify_digest(const struct dsa_public_key *key,
			 const uint8_t *digest,
			 const struct dsa_signature *signature)
{
  return dsa_verify((const struct dsa_params *) key, key->y,
		    SHA256_DIGEST_SIZE, digest, signature);
}

int
dsa_sha256_verify(const struct dsa_public_key *key,
		  struct sha256_ctx *hash,
		  const struct dsa_signature *signature)
{
  uint8_t digest[SHA256_DIGEST_SIZE];
  sha256_digest(hash, sizeof(digest), digest);

  return dsa_verify((const struct dsa_params *) key, key->y,
		    sizeof(digest), digest, signature);
}
