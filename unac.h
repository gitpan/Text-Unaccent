/*
 * Copyright (C) 2000 Loic Dachary
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * Provides functions to strip accents from a string in all the charset
 * supported by iconv(3). See the unac(3) manual page for more information.
 */

#ifndef _unac_h
#define _unac_h

#ifdef __cplusplus
extern "C" {
#endif

/* Generated by builder. Do not modify. Start defines */
#define UNAC_BLOCK_SHIFT 5
#define UNAC_BLOCK_MASK ((1 << UNAC_BLOCK_SHIFT) - 1)
#define UNAC_BLOCK_SIZE (1 << UNAC_BLOCK_SHIFT)
#define UNAC_BLOCK_COUNT 173
#define UNAC_INDEXES_SIZE (0x10000 >> UNAC_BLOCK_SHIFT)
/* Generated by builder. Do not modify. End defines */

/*
 * Return the unaccented equivalent of the UTF-16 character <c>
 * in the pointer <p>. The length of the unsigned short array pointed
 * by <p> is returned in the <l> argument.
 * The C prototype of this macro would be:
 *
 * void unac_char(const unsigned short c, unsigned short* p, unsigned short l)
 */ 
#define unac_char_utf16(c,p,l) \
  { \
    unsigned short index = unac_indexes[(c) >> UNAC_BLOCK_SHIFT]; \
    unsigned char position = (c) & UNAC_BLOCK_MASK; \
    (p) = &(unac_data_table[index][unac_positions[index][(c) & UNAC_BLOCK_MASK]]); \
    (l) = unac_positions[index][position + 1] - unac_positions[index][position]; \
    if((l) == 1 && *(p) == 0xFFFF) { \
      (p) = 0; \
      (l) = 0; \
    } \
  }

/*
 * Return the unaccented equivalent of the UTF-16 string <in> of length
 * <in_length> in the pointer <out>. The length of the UTF-16 string returned
 * in <out> is stored in <out_length>. If the pointer *out is null, a new
 * string is allocated using malloc(3). If the pointer *out is not null, 
 * the available length must also be given in the *out_length argument. 
 * The pointer passed to *out must have been allocated by malloc(3) and
 * may be reallocated by realloc(3) if needs be. It is the responsibility
 * of the caller to free the pointer returned in *out.
 * The return value is 0 on success and -1 on error, in which case
 * the errno variable is set to the corresponding error code.
 */
int unac_string_utf16(const char* in, int in_length,
		char** out, int* out_length);

/*
 * The semantic of this function is stricly equal to the function
 * unac_string_utf16. The <charset> argument applies to the content of the
 * input string. It is converted to UTF-16 using iconv(3) before calling
 * the unac_string function and the result is converted from UTF-16 to
 * the specified <charset> before returning it in the <out> pointer.
 * For efficiency purpose it is recommended that the caller uses
 * unac_string and iconv(3) to save buffer allocations overhead. 
 * The return value is 0 on success and -1 on error, in which case
 * the errno variable is set to the corresponding error code.
 */
int unac_string(const char* charset,
		const char* in, int in_length,
		char** out, int* out_length);

/* Generated by builder. Do not modify. Start declarations */
extern unsigned short unac_indexes[UNAC_INDEXES_SIZE];
extern unsigned char unac_positions[UNAC_BLOCK_COUNT][UNAC_BLOCK_SIZE + 1];
extern unsigned short* unac_data_table[UNAC_BLOCK_COUNT];
extern unsigned short unac_data0[];
extern unsigned short unac_data1[];
extern unsigned short unac_data2[];
extern unsigned short unac_data3[];
extern unsigned short unac_data4[];
extern unsigned short unac_data5[];
extern unsigned short unac_data6[];
extern unsigned short unac_data7[];
extern unsigned short unac_data8[];
extern unsigned short unac_data9[];
extern unsigned short unac_data10[];
extern unsigned short unac_data11[];
extern unsigned short unac_data12[];
extern unsigned short unac_data13[];
extern unsigned short unac_data14[];
extern unsigned short unac_data15[];
extern unsigned short unac_data16[];
extern unsigned short unac_data17[];
extern unsigned short unac_data18[];
extern unsigned short unac_data19[];
extern unsigned short unac_data20[];
extern unsigned short unac_data21[];
extern unsigned short unac_data22[];
extern unsigned short unac_data23[];
extern unsigned short unac_data24[];
extern unsigned short unac_data25[];
extern unsigned short unac_data26[];
extern unsigned short unac_data27[];
extern unsigned short unac_data28[];
extern unsigned short unac_data29[];
extern unsigned short unac_data30[];
extern unsigned short unac_data31[];
extern unsigned short unac_data32[];
extern unsigned short unac_data33[];
extern unsigned short unac_data34[];
extern unsigned short unac_data35[];
extern unsigned short unac_data36[];
extern unsigned short unac_data37[];
extern unsigned short unac_data38[];
extern unsigned short unac_data39[];
extern unsigned short unac_data40[];
extern unsigned short unac_data41[];
extern unsigned short unac_data42[];
extern unsigned short unac_data43[];
extern unsigned short unac_data44[];
extern unsigned short unac_data45[];
extern unsigned short unac_data46[];
extern unsigned short unac_data47[];
extern unsigned short unac_data48[];
extern unsigned short unac_data49[];
extern unsigned short unac_data50[];
extern unsigned short unac_data51[];
extern unsigned short unac_data52[];
extern unsigned short unac_data53[];
extern unsigned short unac_data54[];
extern unsigned short unac_data55[];
extern unsigned short unac_data56[];
extern unsigned short unac_data57[];
extern unsigned short unac_data58[];
extern unsigned short unac_data59[];
extern unsigned short unac_data60[];
extern unsigned short unac_data61[];
extern unsigned short unac_data62[];
extern unsigned short unac_data63[];
extern unsigned short unac_data64[];
extern unsigned short unac_data65[];
extern unsigned short unac_data66[];
extern unsigned short unac_data67[];
extern unsigned short unac_data68[];
extern unsigned short unac_data69[];
extern unsigned short unac_data70[];
extern unsigned short unac_data71[];
extern unsigned short unac_data72[];
extern unsigned short unac_data73[];
extern unsigned short unac_data74[];
extern unsigned short unac_data75[];
extern unsigned short unac_data76[];
extern unsigned short unac_data77[];
extern unsigned short unac_data78[];
extern unsigned short unac_data79[];
extern unsigned short unac_data80[];
extern unsigned short unac_data81[];
extern unsigned short unac_data82[];
extern unsigned short unac_data83[];
extern unsigned short unac_data84[];
extern unsigned short unac_data85[];
extern unsigned short unac_data86[];
extern unsigned short unac_data87[];
extern unsigned short unac_data88[];
extern unsigned short unac_data89[];
extern unsigned short unac_data90[];
extern unsigned short unac_data91[];
extern unsigned short unac_data92[];
extern unsigned short unac_data93[];
extern unsigned short unac_data94[];
extern unsigned short unac_data95[];
extern unsigned short unac_data96[];
extern unsigned short unac_data97[];
extern unsigned short unac_data98[];
extern unsigned short unac_data99[];
extern unsigned short unac_data100[];
extern unsigned short unac_data101[];
extern unsigned short unac_data102[];
extern unsigned short unac_data103[];
extern unsigned short unac_data104[];
extern unsigned short unac_data105[];
extern unsigned short unac_data106[];
extern unsigned short unac_data107[];
extern unsigned short unac_data108[];
extern unsigned short unac_data109[];
extern unsigned short unac_data110[];
extern unsigned short unac_data111[];
extern unsigned short unac_data112[];
extern unsigned short unac_data113[];
extern unsigned short unac_data114[];
extern unsigned short unac_data115[];
extern unsigned short unac_data116[];
extern unsigned short unac_data117[];
extern unsigned short unac_data118[];
extern unsigned short unac_data119[];
extern unsigned short unac_data120[];
extern unsigned short unac_data121[];
extern unsigned short unac_data122[];
extern unsigned short unac_data123[];
extern unsigned short unac_data124[];
extern unsigned short unac_data125[];
extern unsigned short unac_data126[];
extern unsigned short unac_data127[];
extern unsigned short unac_data128[];
extern unsigned short unac_data129[];
extern unsigned short unac_data130[];
extern unsigned short unac_data131[];
extern unsigned short unac_data132[];
extern unsigned short unac_data133[];
extern unsigned short unac_data134[];
extern unsigned short unac_data135[];
extern unsigned short unac_data136[];
extern unsigned short unac_data137[];
extern unsigned short unac_data138[];
extern unsigned short unac_data139[];
extern unsigned short unac_data140[];
extern unsigned short unac_data141[];
extern unsigned short unac_data142[];
extern unsigned short unac_data143[];
extern unsigned short unac_data144[];
extern unsigned short unac_data145[];
extern unsigned short unac_data146[];
extern unsigned short unac_data147[];
extern unsigned short unac_data148[];
extern unsigned short unac_data149[];
extern unsigned short unac_data150[];
extern unsigned short unac_data151[];
extern unsigned short unac_data152[];
extern unsigned short unac_data153[];
extern unsigned short unac_data154[];
extern unsigned short unac_data155[];
extern unsigned short unac_data156[];
extern unsigned short unac_data157[];
extern unsigned short unac_data158[];
extern unsigned short unac_data159[];
extern unsigned short unac_data160[];
extern unsigned short unac_data161[];
extern unsigned short unac_data162[];
extern unsigned short unac_data163[];
extern unsigned short unac_data164[];
extern unsigned short unac_data165[];
extern unsigned short unac_data166[];
extern unsigned short unac_data167[];
extern unsigned short unac_data168[];
extern unsigned short unac_data169[];
extern unsigned short unac_data170[];
extern unsigned short unac_data171[];
extern unsigned short unac_data172[];
/* Generated by builder. Do not modify. End declarations */

#ifdef __cplusplus
}
#endif

#endif /* _unac_h */
