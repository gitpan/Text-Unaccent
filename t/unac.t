use Test;

use Text::Unaccent;

plan test => 3;

ok(unac_string("ISO-8859-1", "�t�"), "ete", "removing accents from �t� (1)");
ok(unac_string("ISO-8859-1", "�t�"), "ete", "removing accents from �t� (2)");
ok(unac_string_utf16(" � t �"), " e t e", "removing accents from �t� utf16");

# Local Variables: ***
# mode: perl ***
# End: ***
