// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"moto"}));        
        set("gender", "女性");                
        set("long", "這是木大哥的專屬坐騎[2;37;0m
它是沐大哥的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mudlet");
        set("owner_name", "沐大哥");
        set_temp("owner", "mudlet");
        set_temp("owner_name", "沐大哥");
        ::setup();
}
