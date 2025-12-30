// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m龍龍[2;37;0m[2;37;0m", ({"lone"}));        
        set("gender", "男性");                
        set("long", "龍龍降世，白龍天下[2;37;0m
它是龍的煩惱的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "terry");
        set("owner_name", "龍的煩惱");
        set_temp("owner", "terry");
        set_temp("owner_name", "龍的煩惱");
        ::setup();
}
