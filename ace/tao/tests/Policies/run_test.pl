eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# run_test.pl,v 1.2 2001/03/05 03:23:48 brunsch Exp
# -*- perl -*-

use lib '../../../bin';
use PerlACE::Run_Test;

$threads = '10';

$T = new PerlACE::Process ("Manipulation", "-n $threads");

$test = $T->SpawnWaitKill (60);

if ($test != 0) {
    print STDERR "ERROR: test returned $test\n";
    exit 1;
}

exit 0;
