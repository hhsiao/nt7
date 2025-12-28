// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小五[2;37;0m[2;37;0m", ({"tmblong"}));        
        set("gender", "男性");                
        set("long", "喔唷[2;37;0m
它是無情的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tmb");
        set("owner_name", "無情");
        set_temp("owner", "tmb");
        set_temp("owner_name", "無情");
        ::setup();
}
