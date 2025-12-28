// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m濤濤[2;37;0m[2;37;0m", ({"xuets"}));        
        set("gender", "男性");                
        set("long", "嘿嘿[2;37;0m
它是薛濤的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xuet");
        set("owner_name", "薛濤");
        set_temp("owner", "xuet");
        set_temp("owner_name", "薛濤");
        ::setup();
}
