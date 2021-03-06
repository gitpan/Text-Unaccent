#
# Copyright (C) 2000, 2001, 2002 Loic Dachary <loic@senga.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
use Test;

use Text::Unaccent;

plan test => 4;

ok(unac_string("ISO-8859-1", "�t�"), "ete", "removing accents from �t� (1)");
ok(unac_string("ISO-8859-1", "�t�"), "ete", "removing accents from �t� (2)");
ok(unac_string_utf16(" � t �"), " e t e", "removing accents from �t� utf16");
#
# If somethings goes wrong in the tests above, move the following line
# at the very beginning and get ready for verbose information.
#
ok(unac_debug($Text::Unaccent::DEBUG_HIGH), undef, "setting debug level");

# Local Variables: ***
# mode: perl ***
# End: ***
