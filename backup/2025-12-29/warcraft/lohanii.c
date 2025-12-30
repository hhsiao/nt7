// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m皮卡丘[2;37;0m[2;37;0m", ({"pikachu"}));        
        set("gender", "女性");                
        set("long", "魔幻獸[2;37;0m
它是明羅的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lohanii");
        set("owner_name", "明羅");
        set_temp("owner", "lohanii");
        set_temp("owner_name", "明羅");
        ::setup();
}
