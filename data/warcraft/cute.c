// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小可愛[2;37;0m[2;37;0m", ({"waa"}));        
        set("gender", "女性");                
        set("long", "小可愛[2;37;0m
它是媧娃的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cute");
        set("owner_name", "媧娃");
        set_temp("owner", "cute");
        set_temp("owner_name", "媧娃");
        ::setup();
}
