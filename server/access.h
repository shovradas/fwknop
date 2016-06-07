/*
 ******************************************************************************
 *
 * File:    access.h
 *
 * Purpose: Header file for fwknopd access.c.
 *
 *  Fwknop is developed primarily by the people listed in the file 'AUTHORS'.
 *  Copyright (C) 2009-2014 fwknop developers and contributors. For a full
 *  list of contributors, see the file 'CREDITS'.
 *
 *  License (GNU General Public License):
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 ******************************************************************************
*/
#include <json/json.h>

#ifndef ACCESS_H
#define ACCESS_H

#define PROTO_TCP   6
#define PROTO_UDP   17

/* Allow strings as large as 123.123.123.123/255.255.255.255
*/
#define ACCESS_BUF_LEN  33

#define MIN_ACC_STANZA_HASH_TABLE_LENGTH  10
#define MAX_ACC_STANZA_HASH_TABLE_LENGTH  10000
#define DEF_HASH_TABLE_LENGTH             100
#define DEF_HASH_TABLE_LENGTH_STR         "100"


/* Function Prototypes
*/
int process_access_msg(fko_srv_options_t *opts, json_object *jdata);
void parse_access_file(fko_srv_options_t *opts);
int compare_addr_list(acc_int_list_t *source_list, const uint32_t ip);
int acc_check_port_access(acc_stanza_t *acc, char *port_str);
void dump_access_list(fko_srv_options_t *opts);
int expand_acc_port_list(acc_port_list_t **plist, char *plist_str);
void free_acc_stanzas(fko_srv_options_t *opts);
void free_acc_port_list(acc_port_list_t *plist);

#ifdef HAVE_C_UNIT_TESTS
int register_ts_access(void);
#endif

#endif /* ACCESS_H */

/***EOF***/
