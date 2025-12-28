// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m麒麟[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "女性");                
        set("long", "這是一隻麒麟[2;37;0m
它是快樂小董的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dongyaowei");
        set("owner_name", "快樂小董");
        set_temp("owner", "dongyaowei");
        set_temp("owner_name", "快樂小董");
        ::setup();
}
