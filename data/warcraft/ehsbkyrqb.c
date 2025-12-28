// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是塗婷泰的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ehsbkyrqb");
        set("owner_name", "塗婷泰");
        set_temp("owner", "ehsbkyrqb");
        set_temp("owner_name", "塗婷泰");
        ::setup();
}
