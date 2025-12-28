// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m囚牛[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "龍老大[2;37;0m
它是有愛就做的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jij");
        set("owner_name", "有愛就做");
        set_temp("owner", "jij");
        set_temp("owner_name", "有愛就做");
        ::setup();
}
