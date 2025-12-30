// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("甲拖車[2;37;0m[2;37;0m", ({"tttc"}));        
        set("gender", "男性");                
        set("long", "甲拖車[2;37;0m
它是甲倉庫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangkuc");
        set("owner_name", "甲倉庫");
        set_temp("owner", "cangkuc");
        set_temp("owner_name", "甲倉庫");
        ::setup();
}
