#!/usr/bin/perl
# Check compound direction exits against manual_coords in graph_mapd.c
use strict;
use warnings;

# Parse manual_coords from graph_mapd.c
my %coords;
open my $fh, '<', 'adm/daemons/graph_mapd.c' or die "Cannot open graph_mapd.c: $!";
while (<$fh>) {
    if (m{"(/d/wudang/\w+)":\s*\(\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*\}\)}) {
        $coords{$1} = { x => $2, y => $3, z => $4, len => $5, wid => $6, hgt => $7 };
    }
}
close $fh;

# Parse compound direction exits from wudang room files
my @issues;
my @entries;
for my $file (glob('d/wudang/*.c')) {
    my $room = $file;
    $room =~ s|\.c$||;
    $room = "/$room";  # e.g., /d/wudang/foo

    open my $rf, '<', $file or next;
    while (<$rf>) {
        if (m{"(north|south|east|west)(up|down)"\s*:\s*(?:__DIR__)?"([^"]+)"}) {
            my ($cardinal, $vertical, $dest_name) = ($1, $2, $3);
            # Resolve destination path
            my $dest;
            if ($dest_name =~ m{^/}) {
                $dest = $dest_name;  # absolute path
            } else {
                $dest = "/d/wudang/$dest_name";
            }

            push @entries, {
                from => $room,
                dir  => "$cardinal$vertical",
                cardinal => $cardinal,
                vertical => $vertical,
                to   => $dest,
            };
        }
    }
    close $rf;
}

# Check each compound direction
print "=== Compound Direction Analysis ===\n\n";
for my $e (sort { $a->{from} cmp $b->{from} || $a->{dir} cmp $b->{dir} } @entries) {
    my $from = $e->{from};
    my $to   = $e->{to};
    my $dir  = $e->{dir};
    my $card = $e->{cardinal};
    my $vert = $e->{vertical};

    my $fc = $coords{$from};
    my $tc = $coords{$to};

    unless ($fc) {
        print "MISSING: $from not in manual_coords\n";
        next;
    }
    unless ($tc) {
        # Skip cross-zone destinations
        next if $to !~ m{^/d/wudang/};
        print "MISSING: $to not in manual_coords\n";
        next;
    }

    my $dx = $tc->{x} - $fc->{x};  # east = +x
    my $dy = $tc->{y} - $fc->{y};  # north = +y
    my $dz = $tc->{z} - $fc->{z};

    # Expected cardinal offset
    my ($exp_dx, $exp_dy) = (0, 0);
    if ($card eq 'north') { $exp_dy = 1; }
    elsif ($card eq 'south') { $exp_dy = -1; }
    elsif ($card eq 'east')  { $exp_dx = 1; }
    elsif ($card eq 'west')  { $exp_dx = -1; }

    # Expected vertical offset
    my $exp_dz = ($vert eq 'up') ? 1 : -1;

    # Check cardinal direction
    my $card_ok = 0;
    if ($exp_dx != 0) {
        # East/west: destination x should be in the expected direction
        $card_ok = ($dx * $exp_dx > 0) || ($dx == 0 && $dz != 0);
    } else {
        # North/south: destination y should be in the expected direction
        $card_ok = ($dy * $exp_dy > 0) || ($dy == 0 && $dz != 0);
    }

    # For same-z rooms, cardinal direction MUST be correct
    my $same_z = ($dz == 0);
    my $cross_z = ($dz != 0);

    # Build status
    my $status = "";

    if ($same_z) {
        # Same z-level: cardinal direction must be correct
        if ($exp_dx != 0 && $dx * $exp_dx <= 0) {
            $status = "WRONG_CARDINAL";
        } elsif ($exp_dy != 0 && $dy * $exp_dy <= 0) {
            $status = "WRONG_CARDINAL";
        } else {
            $status = "OK_SAME_Z";
        }
    } else {
        # Cross z-level: check cardinal relationship AND z direction
        my $z_ok = ($dz * $exp_dz > 0);

        if (!$z_ok) {
            $status = "WRONG_Z";
        } elsif ($exp_dx != 0 && $dx * $exp_dx < 0) {
            $status = "WRONG_CARDINAL_CROSS_Z";
        } elsif ($exp_dy != 0 && $dy * $exp_dy < 0) {
            $status = "WRONG_CARDINAL_CROSS_Z";
        } elsif ($dx == 0 && $dy == 0) {
            $status = "SAME_XY_CROSS_Z";
        } else {
            $status = "OK_CROSS_Z";
        }
    }

    # Print non-OK entries
    if ($status !~ /^OK/) {
        printf "%-8s %-30s %-12s %-30s  dx=%-3d dy=%-3d dz=%-2d\n",
            $status, $from, $dir, $to, $dx, $dy, $dz;
    }
}

print "\n=== All entries (for reference) ===\n\n";
for my $e (sort { $a->{from} cmp $b->{from} || $a->{dir} cmp $b->{dir} } @entries) {
    my $from = $e->{from};
    my $to   = $e->{to};
    my $fc = $coords{$from};
    my $tc = $coords{$to};
    next unless $fc && $tc;

    my $dx = $tc->{x} - $fc->{x};
    my $dy = $tc->{y} - $fc->{y};
    my $dz = $tc->{z} - $fc->{z};

    printf "%-30s %-12s %-30s  (%d,%d,z%d) -> (%d,%d,z%d)  dx=%-3d dy=%-3d dz=%-2d\n",
        $from, $e->{dir}, $to,
        $fc->{x}, $fc->{y}, $fc->{z},
        $tc->{x}, $tc->{y}, $tc->{z},
        $dx, $dy, $dz;
}
