// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m潛龍[2;37;0m[2;37;0m", ({"qianlong"}));        
        set("gender", "男性");                
        set("long", "上天入地 無所不及[2;37;0m
它是閒來無事的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "relaxing");
        set("owner_name", "閒來無事");
        set_temp("owner", "relaxing");
        set_temp("owner_name", "閒來無事");
        ::setup();
}
