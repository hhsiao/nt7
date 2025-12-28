// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m極[1;32m度[5m[35m誘[1;33m惑[2;37;0m[2;37;0m[2;37;0m", ({"lovely"}));        
        set("gender", "女性");                
        set("long", "極度誘惑！[2;37;0m
它是俊俏小妞的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilbeauty");
        set("owner_name", "俊俏小妞");
        set_temp("owner", "evilbeauty");
        set_temp("owner_name", "俊俏小妞");
        ::setup();
}
