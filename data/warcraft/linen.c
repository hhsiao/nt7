// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m遠古猛虎[2;37;0m[2;37;0m[2;37;0m", ({"lao"}));        
        set("gender", "男性");                
        set("long", "一隻兇猛的大老虎，一看就知道是遠古血脈。[2;37;0m
它是蕭爻的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "linen");
        set("owner_name", "蕭爻");
        set_temp("owner", "linen");
        set_temp("owner_name", "蕭爻");
        ::setup();
}
