// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m烏雲踏雪[2;37;0m[2;37;0m", ({"fggg"}));        
        set("gender", "男性");                
        set("long", "戰國名駒[2;37;0m
它是歐陽風兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kiki");
        set("owner_name", "歐陽風兒");
        set_temp("owner", "kiki");
        set_temp("owner_name", "歐陽風兒");
        ::setup();
}
