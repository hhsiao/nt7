// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍十八[2;37;0m[2;37;0m", ({"haoh"}));        
        set("gender", "女性");                
        set("long", "這是一條美麗的龍。三圍1000 － 500 － 1000[2;37;0m
它是李十八的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "clrak");
        set("owner_name", "李十八");
        set_temp("owner", "clrak");
        set_temp("owner_name", "李十八");
        ::setup();
}
