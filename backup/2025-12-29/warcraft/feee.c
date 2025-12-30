// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m檬薜鬧[2;37;0m[2;37;0m", ({"xxbook"}));        
        set("gender", "男性");                
        set("long", "一隻檬薜鬧[2;37;0m
它是菲燕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "feee");
        set("owner_name", "菲燕");
        set_temp("owner", "feee");
        set_temp("owner_name", "菲燕");
        ::setup();
}
