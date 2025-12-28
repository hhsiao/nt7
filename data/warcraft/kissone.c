// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("傲之追獵者[2;37;0m[2;37;0m", ({"scp"}));        
        set("gender", "男性");                
        set("long", "這個主人很懶，什麼都沒留下。[2;37;0m
它是挪威小鳥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kissone");
        set("owner_name", "挪威小鳥");
        set_temp("owner", "kissone");
        set_temp("owner_name", "挪威小鳥");
        ::setup();
}
