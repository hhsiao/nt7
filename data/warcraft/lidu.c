// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"lidsa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是星萬的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidu");
        set("owner_name", "星萬");
        set_temp("owner", "lidu");
        set_temp("owner_name", "星萬");
        ::setup();
}
