#!/usr/bin/perl
# Update all wudang room z-levels in graph_mapd.c to strict compound-direction values
use strict;
use warnings;

my %new_z = (
    # z=0: base level (no change needed for these)
    "wdroad1" => 0, "wdroad2" => 0, "wdroad3" => 0, "wdroad4" => 0,
    "wdroad5" => 0, "wdroad6" => 0, "wdroad7" => 0, "wdroad8" => 0,
    "wdroad9" => 0, "wdroad10" => 0,
    "house" => 0, "sanbuguan" => 0,
    "slxl1" => 0, "slxl2" => 0,
    "songlin1" => 0, "songlin2" => 0, "songlin3" => 0, "songlin4" => 0,

    # z=1
    "tufeiwo1" => 1, "tufeiwo2" => 1, "tufeiwo3" => 1,
    "jiejianyan" => 1,

    # z=2
    "slxl3" => 2, "xuanyuegate" => 2,
    "pine_road" => 2, "pine_road1" => 2, "pine_road2" => 2,
    "pine_forest" => 2, "pine_forest0" => 2, "pine_forest1" => 2,
    "pine_forest2" => 2, "pine_forest3" => 2, "pine_forest4" => 2,
    "pine_forest5" => 2, "pine_forest6" => 2, "pine_forest7" => 2,
    "pine_forest8" => 2, "pine_forest9" => 2, "pine_forest10" => 2,

    # z=3
    "shijie1" => 3,
    "tyroad8" => 3, "tyroad9" => 3, "tyroad10" => 3,
    "tyroad11" => 3, "tyroad12" => 3, "tyroad13" => 3,
    "tynroad" => 3, "tysroad" => 3,
    "tygate1" => 3, "tygate2" => 3,
    "gyroad1" => 3, "gyroad2" => 3,

    # z=4
    "yuzhengong" => 4, "tyroad7" => 4,

    # z=5
    "wdbl" => 5, "wdbl1" => 5, "wdbl2" => 5,
    "shanlu1" => 5, "mozhenjing" => 5, "shiliang" => 5, "shop" => 5,
    "tyroad6" => 5,

    # z=6
    "haohanpo" => 6, "taizipo" => 6, "fuzhenguan" => 6,
    "shibapan" => 6, "tyroad5" => 6,

    # z=7
    "shijie2" => 7, "tyroad4" => 7,

    # z=8
    "zixiaogate" => 8, "tyroad1" => 8, "tyroad2" => 8, "tyroad3" => 8,

    # z=9
    "guangchang" => 9, "sanqingdian" => 9, "houyuan" => 9,
    "xiaolu1" => 9, "xiaolu2" => 9, "xiaoyuan" => 9,
    "xilang" => 9, "donglang1" => 9, "donglang2" => 9,
    "xiuxishi" => 9, "chashi" => 9, "liangongfang" => 9,
    "shanlu2" => 9, "shanlu3" => 9,
    "nanyan0" => 9, "nanyan1" => 9, "nanyan2" => 9,
    "nanyan3" => 9, "nanyan4" => 9,

    # z=10
    "cangjingge" => 10, "caolianfang" => 10,
    "caolian1" => 10, "caolian2" => 10, "caolian3" => 10,
    "langmeiyuan" => 10, "nanyangong" => 10, "shanlu4" => 10, "shizhu" => 10,

    # z=11
    "taiziyan" => 11, "gaotai" => 11, "nanyanfeng" => 11,
    "sheshenya" => 11, "wuyaling" => 11,

    # z=12-19: summit
    "sanlaofeng" => 12,
    "wulaofeng" => 13,
    "hutouyan" => 14,
    "chaotiangong" => 15, "huixianqiao" => 15, "toutiangate" => 15,
    "ertiangate" => 16,
    "santiangate" => 17,
    "jinding" => 18, "shierliantai" => 18, "zijincheng" => 18, "jindian" => 18,
    "guanyuntai" => 19,
);

# Read the file
my $file = 'adm/daemons/graph_mapd.c';
open my $fh, '<', $file or die "Cannot open $file: $!";
my @lines = <$fh>;
close $fh;

my $changes = 0;
my $total_wudang = 0;

for my $i (0..$#lines) {
    my $line = $lines[$i];
    # Match wudang room entries
    if ($line =~ m{"/d/wudang/(\w+)"}) {
        my $name = $1;
        next unless exists $new_z{$name};
        $total_wudang++;

        # Match the coordinate tuple: ({ x, y, z, l, w, h })
        # Capture: prefix ({ x, y,  THEN z  THEN , l, w, h }) suffix
        if ($line =~ m{^(.*\(\{\s*-?\d+\s*,\s*-?\d+\s*,\s*)(-?\d+)(\s*,\s*\d+\s*,\s*\d+\s*,\s*\d+\s*\}\).*)$}) {
            my ($pre, $z_old, $post) = ($1, $2, $3);
            my $z_new = $new_z{$name};
            if ($z_old != $z_new) {
                # Format z_new with similar width
                my $z_str;
                if ($z_new >= 0 && $z_new < 10) {
                    $z_str = " $z_new";
                } elsif ($z_new >= 10) {
                    $z_str = "$z_new";
                } else {
                    $z_str = "$z_new";
                }
                $lines[$i] = "$pre$z_str$post\n";
                printf "CHANGED: /d/wudang/%-20s z: %3d -> %2d\n", $name, $z_old, $z_new;
                $changes++;
            }
        }
    }
}

# Write the file back
open my $out, '>', $file or die "Cannot write $file: $!";
print $out @lines;
close $out;

printf "\nTotal wudang rooms found: %d\n", $total_wudang;
printf "Changes made: %d\n", $changes;
