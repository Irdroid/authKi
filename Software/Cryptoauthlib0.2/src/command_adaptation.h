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

#ifndef COMMAND_ADAPTATION_H
#define COMMAND_ADAPTATION_H

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

struct Command_ATSHA204
{
    uint8_t command;
    uint8_t count;
    uint8_t opcode;
    uint8_t param1;
    uint8_t param2[2];
    uint8_t *data;
    unsigned int data_len;
    uint8_t checksum[2];
    struct timespec exec_time;
};

enum LCA_STATUS_RESPONSE
  {
    RSP_SUCCESS = 0,            /**< The command succeeded. */
    RSP_CHECKMAC_MISCOMPARE = 0x01, /**< The CHECKMAC Command failed */
    RSP_PARSE_ERROR = 0x03,     /**< Command was received but length,
                                   opcode or parameters are illegal
                                   regardless of device state */
    ECC_FAULT = 0x05,
    RSP_EXECUTION_ERROR = 0x0F, /**< Command was received but can't
                                   be executed in the current state */
    RSP_AWAKE = 0x11,           /**< The device is awake */
    RSP_COMM_ERROR = 0xFF,       /**< Command was not received properly
                                  */
    RSP_NAK = 0xAA,     /**< Response was NAKed and a retry should occur */
  };


enum LCA_STATUS_RESPONSE
lca_process_command (int fd,
                      struct Command_ATSHA204 *c,
                      uint8_t* rec_buf,
                      unsigned int recv_len);

enum LCA_STATUS_RESPONSE
lca_send_and_receive (int fd,
                       const uint8_t *send_buf,
                       unsigned int send_buf_len,
                       uint8_t *recv_buf,
                       unsigned int recv_buf_len,
                       struct timespec *wait_time);

unsigned int
lca_serialize_command (struct Command_ATSHA204 *c,
                        uint8_t **serialized);

enum LCA_STATUS_RESPONSE
lca_read_and_validate (int fd,
                        uint8_t *buf,
                        unsigned int len);

/**
 * Returns a string for the enumerated response code. Useful for
 * debugging and logging functions.
 *
 * @param rsp The response code.
 *
 * @return A pointer to a static string.
 */
const char*
status_to_string (enum LCA_STATUS_RESPONSE rsp) __attribute__ ((pure));

struct lca_octet_buffer
lca_send_and_get_rsp (int fd,
                       const uint8_t *send_buf,
                       const unsigned int send_buf_len,
                       struct timespec wait_time,
                       const int MAX_RECV_LEN);

#endif /* COMMAND_ADAPTATION_H */
