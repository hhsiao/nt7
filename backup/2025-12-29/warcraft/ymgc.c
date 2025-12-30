// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("酒井法子妹[2;37;0m[2;37;0m", ({"plgj"}));        
        set("gender", "男性");                
        set("long", "@miaoshu[2;37;0m
它是搗藥三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ymgc");
        set("owner_name", "搗藥三");
        set_temp("owner", "ymgc");
        set_temp("owner_name", "搗藥三");
        ::setup();
}
