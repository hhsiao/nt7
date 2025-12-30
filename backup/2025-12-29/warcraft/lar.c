// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m八[1;33m抬[1;34m大[1;32m轎[2;37;0m[2;37;0m", ({"ars"}));        
        set("gender", "男性");                
        set("long", "拉芳專用[2;37;0m
它是拉芳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lar");
        set("owner_name", "拉芳");
        set_temp("owner", "lar");
        set_temp("owner_name", "拉芳");
        ::setup();
}
