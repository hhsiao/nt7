// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青龍[2;37;0m[2;37;0m", ({"qil"}));        
        set("gender", "男性");                
        set("long", "一隻小青龍[2;37;0m
它是軒轅三光的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iamhy");
        set("owner_name", "軒轅三光");
        set_temp("owner", "iamhy");
        set_temp("owner_name", "軒轅三光");
        ::setup();
}
