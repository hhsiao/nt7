// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是昌海逸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tdgpkxrti");
        set("owner_name", "昌海逸");
        set_temp("owner", "tdgpkxrti");
        set_temp("owner_name", "昌海逸");
        ::setup();
}
