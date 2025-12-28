// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("好飛翔[2;37;0m[2;37;0m", ({"xixihhh"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是習好的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixih");
        set("owner_name", "習好");
        set_temp("owner", "xixih");
        set_temp("owner_name", "習好");
        ::setup();
}
