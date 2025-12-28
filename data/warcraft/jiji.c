// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m囚牛[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "女性");                
        set("long", "龍老大[2;37;0m
它是做了就愛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jiji");
        set("owner_name", "做了就愛");
        set_temp("owner", "jiji");
        set_temp("owner_name", "做了就愛");
        ::setup();
}
