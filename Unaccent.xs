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
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "unac.h"

static char* buffer;
static int buffer_length;

MODULE = Text::Unaccent PACKAGE = Text::Unaccent PREFIX = perl_

BOOT:
	buffer = 0;
	buffer_length = 0;

char*
perl_unac_string(charset,in)
	char* charset
	char* in
	PROTOTYPE: $$
	CODE:
		STRLEN in_length;
		in = (char*)SvPV(ST(1), in_length);
		ST(0) = sv_newmortal();
		if(unac_string(charset,
			       in, in_length,
			       &buffer, &buffer_length) == 0) {
		  sv_setpvn((SV*)ST(0), buffer, buffer_length);
		} else {
		  perror("unac_string");
		  ST(0) = &PL_sv_undef;
		}

char*
perl_unac_string_utf16(in)
	char* in
	PROTOTYPE: $
	CODE:
		STRLEN in_length;
		in = (char*)SvPV(ST(0), in_length);
		ST(0) = sv_newmortal();
		if(unac_string_utf16(in, in_length,
				     &buffer, &buffer_length) == 0) {
		  sv_setpvn((SV*)ST(0), buffer, buffer_length);
		} else {
		  perror("unac_string_utf16");
		  ST(0) = &PL_sv_undef;
		}
