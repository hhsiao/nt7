// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("月津梅帶子[2;37;0m[2;37;0m", ({"plgt"}));        
        set("gender", "男性");                
        set("long", "@miaoshu[2;37;0m
它是押運三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yygc");
        set("owner_name", "押運三");
        set_temp("owner", "yygc");
        set_temp("owner_name", "押運三");
        ::setup();
}
