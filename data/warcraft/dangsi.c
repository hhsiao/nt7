// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m情絲[2;37;0m[2;37;0m", ({"qingsi"}));        
        set("gender", "男性");                
        set("long", "情絲[2;37;0m
它是肆無忌憚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangsi");
        set("owner_name", "肆無忌憚");
        set_temp("owner", "dangsi");
        set_temp("owner_name", "肆無忌憚");
        ::setup();
}
