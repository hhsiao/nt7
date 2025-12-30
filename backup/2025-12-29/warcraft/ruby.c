// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小寶貝[2;37;0m[2;37;0m", ({"baby"}));        
        set("gender", "男性");                
        set("long", "小寶貝[2;37;0m
它是寶貝熊熊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ruby");
        set("owner_name", "寶貝熊熊");
        set_temp("owner", "ruby");
        set_temp("owner_name", "寶貝熊熊");
        ::setup();
}
