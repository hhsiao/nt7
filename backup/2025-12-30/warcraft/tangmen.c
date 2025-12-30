// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("呆子[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "呆子[2;37;0m
它是哈欠兒的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "tangmen");
        set("owner_name", "哈欠兒");
        set_temp("owner", "tangmen");
        set_temp("owner_name", "哈欠兒");
        ::setup();
}
