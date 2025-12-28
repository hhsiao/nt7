// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小強[2;37;0m[2;37;0m", ({"redleaf"}));        
        set("gender", "男性");                
        set("long", "小強[2;37;0m
它是小樣兒的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "mate");
        set("owner_name", "小樣兒");
        set_temp("owner", "mate");
        set_temp("owner_name", "小樣兒");
        ::setup();
}
