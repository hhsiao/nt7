// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m極度[5m[1;35m誘[1;31m惑[2;37;0m[2;37;0m[2;37;0m", ({"lovely"}));        
        set("gender", "女性");                
        set("long", "極度誘惑[2;37;0m
它是銷魂小妞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilgirl");
        set("owner_name", "銷魂小妞");
        set_temp("owner", "evilgirl");
        set_temp("owner_name", "銷魂小妞");
        ::setup();
}
