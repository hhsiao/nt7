// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m西[1;31m方[1;32m極[1;35m樂[2;37;0m[2;37;0m", ({"liudao"}));        
        set("gender", "男性");                
        set("long", "如夢似幻的西方極樂淨土，不沾一絲人間煙塵。[2;37;0m
它是神話的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lockwxb");
        set("owner_name", "神話");
        set_temp("owner", "lockwxb");
        set_temp("owner_name", "神話");
        ::setup();
}
