// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m極度[5m[1;36m誘[1;33m惑[2;37;0m[2;37;0m[2;37;0m", ({"lovely"}));        
        set("gender", "女性");                
        set("long", "極度誘惑！[2;37;0m
它是冷豔小妞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evildamsel");
        set("owner_name", "冷豔小妞");
        set_temp("owner", "evildamsel");
        set_temp("owner_name", "冷豔小妞");
        ::setup();
}
