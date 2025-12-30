// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("波多結衣子[2;37;0m[2;37;0m", ({"plg"}));        
        set("gender", "男性");                
        set("long", "@miaoshu[2;37;0m
它是立庫六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ltkf");
        set("owner_name", "立庫六");
        set_temp("owner", "ltkf");
        set_temp("owner_name", "立庫六");
        ::setup();
}
