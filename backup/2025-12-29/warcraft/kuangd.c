// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蒼井已空[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "冇碼[2;37;0m
它是狂四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kuangd");
        set("owner_name", "狂四");
        set_temp("owner", "kuangd");
        set_temp("owner_name", "狂四");
        ::setup();
}
