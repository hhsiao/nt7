// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白龍[2;37;0m[2;37;0m", ({"woca"}));        
        set("gender", "男性");                
        set("long", "小龍瓏[2;37;0m
它是笑笑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lqb");
        set("owner_name", "笑笑");
        set_temp("owner", "lqb");
        set_temp("owner_name", "笑笑");
        ::setup();
}
