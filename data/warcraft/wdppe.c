// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛的[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "愛的[2;37;0m
它是武當師五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppe");
        set("owner_name", "武當師五");
        set_temp("owner", "wdppe");
        set_temp("owner_name", "武當師五");
        ::setup();
}
