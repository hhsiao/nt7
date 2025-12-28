// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m專殺鬼子[2;37;0m[2;37;0m", ({"leguia"}));        
        set("gender", "男性");                
        set("long", "$HIC$專殺鬼子[2;37;0m
它是踏平東京的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "legui");
        set("owner_name", "踏平東京");
        set_temp("owner", "legui");
        set_temp("owner_name", "踏平東京");
        ::setup();
}
