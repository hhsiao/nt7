// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m拖拉機[1;37m[2;37;0m[2;37;0m", ({"tlj"}));        
        set("gender", "男性");                
        set("long", "馬[2;37;0m
它是雷茲副的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lei");
        set("owner_name", "雷茲副");
        set_temp("owner", "lei");
        set_temp("owner_name", "雷茲副");
        ::setup();
}
