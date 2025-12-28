// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "女性");                
        set("long", "一隻憨厚的百萬年海龜。[2;37;0m
它是胡天侃地的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "nsla");
        set("owner_name", "胡天侃地");
        set_temp("owner", "nsla");
        set_temp("owner_name", "胡天侃地");
        ::setup();
}
