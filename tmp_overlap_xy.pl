#!/usr/bin/perl
use strict;
my %cells;
my @dupes;
while (<STDIN>) {
    if (m{"(/d/xiangyang/\S+)".*\(\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)}) {
        my $room = $1;
        my $x = $2; my $y = $3; my $z = $4;
        my $len = $5; my $wid = $6;
        for my $cx ($x .. $x+$len-1) {
            for my $cy ($y .. $y+$wid-1) {
                my $key = "$cx,$cy,$z";
                if (exists $cells{$key}) {
                    push @dupes, "OVERLAP at ($key): $cells{$key} vs $room";
                }
                $cells{$key} = $room;
            }
        }
    }
}
if (@dupes) { print join("\n", @dupes), "\n"; }
else { print "No overlaps found among " . scalar(keys %cells) . " cells\n"; }
