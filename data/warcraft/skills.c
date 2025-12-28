// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("思密達[2;37;0m[2;37;0m", ({"super"}));        
        set("gender", "男性");                
        set("long", "喲喲，蒼茫的天涯是我的愛[2;37;0m
它是歐陽弗血的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "skills");
        set("owner_name", "歐陽弗血");
        set_temp("owner", "skills");
        set_temp("owner_name", "歐陽弗血");
        ::setup();
}
