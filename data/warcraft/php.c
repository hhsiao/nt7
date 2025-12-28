// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m虛空[2;37;0m[2;37;0m", ({"bool"}));        
        set("gender", "男性");                
        set("long", "暫無[2;37;0m
它是趙錢孫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "php");
        set("owner_name", "趙錢孫");
        set_temp("owner", "php");
        set_temp("owner_name", "趙錢孫");
        ::setup();
}
