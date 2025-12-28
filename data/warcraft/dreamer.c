// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是築夢者的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dreamer");
        set("owner_name", "築夢者");
        set_temp("owner", "dreamer");
        set_temp("owner_name", "築夢者");
        ::setup();
}
