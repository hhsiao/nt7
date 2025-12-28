// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m桑原玲[2;37;0m[2;37;0m", ({"jbl"}));        
        set("gender", "男性");                
        set("long", "$HIM$桑原玲[2;37;0m
它是無根公子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pxj");
        set("owner_name", "無根公子");
        set_temp("owner", "pxj");
        set_temp("owner_name", "無根公子");
        ::setup();
}
