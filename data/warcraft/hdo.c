// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天寵[2;37;0m[2;37;0m", ({"dsf"}));        
        set("gender", "男性");                
        set("long", "一隻仙獸，不知怎麼流落到了人間。[2;37;0m
它是橫刀的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hdo");
        set("owner_name", "橫刀");
        set_temp("owner", "hdo");
        set_temp("owner_name", "橫刀");
        ::setup();
}
