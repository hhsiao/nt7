#!/usr/bin/perl
use strict;
use warnings;
my %seen;
while (<>) {
    if (/"([^"]+)"\s*:\s*\(\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)/) {
        my ($id,$x,$y,$z,$l,$w,$h) = ($1,$2,$3,$4,$5,$6,$7);
        for my $dx (0..$l-1) {
            for my $dy (0..$w-1) {
                my $cx = $x+$dx;
                my $cy = $y+$dy;
                my $key = "$cx,$cy,$z";
                if (exists $seen{$key}) {
                    print "OVERLAP at ($cx,$cy,$z): $seen{$key} vs $id\n";
                }
                $seen{$key} = $id;
            }
        }
    }
}
print "Check complete. Total cells: " . scalar(keys %seen) . "\n";
