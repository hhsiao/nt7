// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("咕嚕咕嚕[2;37;0m[2;37;0m", ({"yamaha"}));        
        set("gender", "男性");                
        set("long", "一二三四五六七[2;37;0m
它是逆天的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "uemc");
        set("owner_name", "逆天");
        set_temp("owner", "uemc");
        set_temp("owner_name", "逆天");
        ::setup();
}
