// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m南海狂尼[2;37;0m[2;37;0m", ({"call"}));        
        set("gender", "男性");                
        set("long", "南海狂尼[2;37;0m
它是邵三豐的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "winjoeone");
        set("owner_name", "邵三豐");
        set_temp("owner", "winjoeone");
        set_temp("owner_name", "邵三豐");
        ::setup();
}
