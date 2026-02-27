#!/usr/bin/perl
use strict;
my %occ;
open my $f, '<', 'adm/daemons/graph_mapd.c' or die;
while (<$f>) {
  if (m{"(/d/wudang/\w+)":\s*\(\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(\d+)\s*,\s*(\d+)}) {
    my ($r,$x,$y,$z,$l,$w) = ($1,$2,$3,$4,$5,$6);
    for my $dx (0..$l-1) { for my $dy (0..$w-1) {
      my $k = sprintf("%d,%d,z%d", $x+$dx, $y+$dy, $z);
      $occ{$k} = $r;
    }}
  }
}
# Check candidate positions for new layout
my @checks = (
  "-3,-28,z1", "-3,-29,z1", "-4,-29,z1", "-5,-29,z1",
  "-4,-30,z1", "-3,-30,z1", "-3,-31,z1",
  "-5,-31,z1", "-6,-31,z1",
);
for my $pos (@checks) {
  if ($occ{$pos}) { print "TAKEN: $pos = $occ{$pos}\n"; }
  else { print "FREE:  $pos\n"; }
}
