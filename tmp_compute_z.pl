#!/usr/bin/perl
# Compute z-levels for wudang rooms by strictly applying compound direction rules.
# "up" in compound dir = destination z+1, "down" = destination z-1
# Regular cardinal dirs = same z
use strict;
use warnings;

# Parse all exits from wudang room files
my %exits;  # room => { dir => dest }
for my $file (glob('d/wudang/*.c')) {
    my $room = $file;
    $room =~ s|\.c$||;
    $room = "/$room";

    open my $fh, '<', $file or next;
    my $content = do { local $/; <$fh> };
    close $fh;

    # Match exit mappings
    while ($content =~ /"(\w+)"\s*:\s*(?:__DIR__)?"([^"]+)"/g) {
        my ($dir, $dest_name) = ($1, $2);
        my $dest;
        if ($dest_name =~ m{^/}) {
            $dest = $dest_name;
        } else {
            $dest = "/d/wudang/$dest_name";
        }
        $exits{$room}{$dir} = $dest;
    }
}

# Build z-constraints from exits
# Each compound direction creates a z-offset constraint
my @constraints;  # [ from, to, dz ]
my %rooms_seen;

for my $room (sort keys %exits) {
    $rooms_seen{$room} = 1;
    for my $dir (sort keys %{$exits{$room}}) {
        my $dest = $exits{$room}{$dir};
        next unless $dest =~ m{^/d/wudang/};  # skip cross-zone
        $rooms_seen{$dest} = 1;

        my $dz = 0;
        if ($dir =~ /up$/ && $dir ne "up") {
            $dz = 1;  # compound up
        } elsif ($dir =~ /down$/ && $dir ne "down") {
            $dz = -1;  # compound down
        } elsif ($dir eq "up") {
            $dz = 1;
        } elsif ($dir eq "down") {
            $dz = -1;
        }
        # Regular directions: dz = 0 (same z)

        push @constraints, [$room, $dest, $dz];
    }
}

# BFS to assign z-levels starting from wdroad1 = 0
my %z_level;
my @queue = ("/d/wudang/wdroad1");
$z_level{"/d/wudang/wdroad1"} = 0;
my @conflicts;

while (@queue) {
    my $room = shift @queue;
    my $cur_z = $z_level{$room};

    for my $c (@constraints) {
        my ($from, $to, $dz) = @$c;
        next unless $from eq $room;

        my $expected_z = $cur_z + $dz;
        if (exists $z_level{$to}) {
            if ($z_level{$to} != $expected_z) {
                push @conflicts, sprintf("CONFLICT: %s(z=%d) -%s-> %s: expected z=%d but already z=%d",
                    $from, $cur_z, ($dz > 0 ? "up" : $dz < 0 ? "down" : "same"), $to, $expected_z, $z_level{$to});
            }
        } else {
            $z_level{$to} = $expected_z;
            push @queue, $to;
        }
    }
}

# Report conflicts
if (@conflicts) {
    print "=== CONFLICTS ===\n";
    for my $c (sort @conflicts) { print "$c\n"; }
    print "\n";
}

# Report z-levels
my %by_z;
for my $room (sort keys %z_level) {
    push @{$by_z{$z_level{$room}}}, $room;
}

print "=== Z-Level Assignments ===\n\n";
for my $z (sort { $a <=> $b } keys %by_z) {
    my @rooms = sort @{$by_z{$z}};
    printf "z=%d (%d rooms):\n", $z, scalar @rooms;
    for my $r (@rooms) {
        printf "  %s\n", $r;
    }
    print "\n";
}

# Report unreachable rooms
my @unreachable;
for my $r (sort keys %rooms_seen) {
    push @unreachable, $r unless exists $z_level{$r};
}
if (@unreachable) {
    print "=== UNREACHABLE from wdroad1 ===\n";
    for my $r (@unreachable) { print "  $r\n"; }
}

# Summary
my $min_z = (sort { $a <=> $b } keys %by_z)[0];
my $max_z = (sort { $b <=> $a } keys %by_z)[0];
printf "\nTotal: %d rooms across z=%d to z=%d (%d levels)\n",
    scalar(keys %z_level), $min_z, $max_z, $max_z - $min_z + 1;
