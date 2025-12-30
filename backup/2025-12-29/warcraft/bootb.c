// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("喔唷[2;37;0m[2;37;0m", ({"bootblong"}));        
        set("gender", "男性");                
        set("long", "粘田[2;37;0m
它是隔壁小孫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bootb");
        set("owner_name", "隔壁小孫");
        set_temp("owner", "bootb");
        set_temp("owner_name", "隔壁小孫");
        ::setup();
}
