// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m開天混沌獸[1;37m[2;37;0m[2;37;0m", ({"flyer"}));        
        set("gender", "女性");                
        set("long", "宇宙初開時的曠世神獸，傳說為萬物之源！[2;37;0m
它是馬行空的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tairan");
        set("owner_name", "馬行空");
        set_temp("owner", "tairan");
        set_temp("owner_name", "馬行空");
        ::setup();
}
