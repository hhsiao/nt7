// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m看劍[2;37;0m[2;37;0m", ({"qiji"}));        
        set("gender", "男性");                
        set("long", "夢迴吹角連營[2;37;0m
它是辛棄疾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xinqiji");
        set("owner_name", "辛棄疾");
        set_temp("owner", "xinqiji");
        set_temp("owner_name", "辛棄疾");
        ::setup();
}
