// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("名無[2;37;0m[2;37;0m", ({"pop"}));        
        set("gender", "男性");                
        set("long", "啊[2;37;0m
它是丁打雜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ipxd");
        set("owner_name", "丁打雜");
        set_temp("owner", "ipxd");
        set_temp("owner_name", "丁打雜");
        ::setup();
}
