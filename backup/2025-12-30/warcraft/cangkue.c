// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小溜溜[2;37;0m[2;37;0m", ({"xll"}));        
        set("gender", "女性");                
        set("long", "小溜溜[2;37;0m
它是腕倉庫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangkue");
        set("owner_name", "腕倉庫");
        set_temp("owner", "cangkue");
        set_temp("owner_name", "腕倉庫");
        ::setup();
}
