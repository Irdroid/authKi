/* -*- mode: c; c-file-style: "gnu" -*-
 * Copyright (C) 2014-2015 Cryptotronix, LLC.
 *
 * This file is part of libcryptoauth.
 *
 * libcryptoauth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * libcryptoauth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libcryptoauth.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ATECC108_COMMAND_H
#define ATECC108_COMMAND_H


/**
 * Generates a private or public key in the specified slot. If private
 * is true, it will generate a new private key. If false, it will
 * return the *public* key from the *existing* private key in that slot.
 *
 * @param fd The open file descriptor.
 * @param key_id The key ID on which to operate.
 * @param private True if a new private key is desired, otherwise false.
 *
 * @return In either case, this will return the *public* key of the
 * specified key slot. The caller should check if the pointer is null,
 * which signifies an error.
 */struct lca_octet_buffer
lca_gen_ecc_key (int fd,
                      uint8_t key_id,
                      bool private);

/**
 * Performs an ECC signature over the data loaded in tempkey
 * register. You must run the load nonce command first to populate
 * this register.
 *
 * @param fd The open file descriptor.
 * @param key_id The key ID for the key you want to use.
 *
 * @return The signature as one buffer: R + S.
 */
struct lca_octet_buffer
lca_ecc_sign (int fd,
                   uint8_t key_id);

/**
 * Verifies an ECDSA Signature. Requires that the data, which was
 * signed, was first loaded with the nonce command.
 *
 * @param fd The open file descriptor.
 * @param pub_key The Public Key matching the private key that signed
 * the data.
 * @param signature The resultant signature.
 *
 * @return True if the signature is valid otherwise false
 */
bool
lca_ecc_verify (int fd,
                     struct lca_octet_buffer pub_key,
                     struct lca_octet_buffer signature);


#endif
