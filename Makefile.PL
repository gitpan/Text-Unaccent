#
# Copyright (C) 2000 Loic Dachary
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
use strict;

use ExtUtils::MakeMaker;

sub MY::postamble {
return '
#
# Get unac sources from the unac project CVS tree
#
sync:
	cvs -z3 -d:pserver:anonymous@cvs.unac.sourceforge.net:/cvsroot/unac co unac/unac.c unac/unac.h
	mv unac/*.[ch] .
	rm -fr unac
';
}

WriteMakefile(
    'NAME'	=> 'Text::Unaccent',
    'VERSION_FROM' => 'Unaccent.pm', # finds $VERSION
    'OBJECT'	=> '$(O_FILES)',
    'C'		=> [ 'Unaccent.c', 'unac.c' ],
    'LIBS'	=> [ '-liconv' ], 
    'INC'	=> '-I.',
);
