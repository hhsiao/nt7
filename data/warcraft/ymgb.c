// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("波多結衣子妹[2;37;0m[2;37;0m", ({"plgb"}));        
        set("gender", "男性");                
        set("long", "@miaoshu[2;37;0m
它是搗藥二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ymgb");
        set("owner_name", "搗藥二");
        set_temp("owner", "ymgb");
        set_temp("owner_name", "搗藥二");
        ::setup();
}
