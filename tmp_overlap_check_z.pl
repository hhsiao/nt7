#!/usr/bin/perl
# Check for overlapping rooms on the same z-level in wudang
use strict;
use warnings;

my %rooms;
open my $fh, '<', 'adm/daemons/graph_mapd.c' or die;
while (<$fh>) {
    if (m{"(/d/wudang/\w+)":\s*\(\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*\}\)}) {
        $rooms{$1} = { x => $2, y => $3, z => $4, l => $5, w => $6, h => $7 };
    }
}
close $fh;

# Check overlaps per z-level
my %by_z;
for my $r (keys %rooms) {
    push @{$by_z{$rooms{$r}{z}}}, $r;
}

my $total_overlaps = 0;
for my $z (sort { $a <=> $b } keys %by_z) {
    my @rms = sort @{$by_z{$z}};
    my %grid;  # "x,y" => room
    for my $r (@rms) {
        my $d = $rooms{$r};
        for my $dx (0..$d->{l}-1) {
            for my $dy (0..$d->{w}-1) {
                my $key = sprintf("%d,%d", $d->{x}+$dx, $d->{y}+$dy);
                if ($grid{$key}) {
                    printf "OVERLAP z=%2d: cell (%s) claimed by %s AND %s\n",
                        $z, $key, $grid{$key}, $r;
                    $total_overlaps++;
                } else {
                    $grid{$key} = $r;
                }
            }
        }
    }
}

if ($total_overlaps == 0) {
    print "No overlaps found!\n";
} else {
    printf "\nTotal overlaps: %d\n", $total_overlaps;
}

# Summary per z-level
print "\n=== Rooms per z-level ===\n";
for my $z (sort { $a <=> $b } keys %by_z) {
    printf "z=%2d: %d rooms\n", $z, scalar @{$by_z{$z}};
}
