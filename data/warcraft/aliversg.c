// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("隱形轟炸機[2;37;0m[2;37;0m", ({"pesie"}));        
        set("gender", "男性");                
        set("long", "隱形轟炸機[2;37;0m
它是阿爾七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aliversg");
        set("owner_name", "阿爾七");
        set_temp("owner", "aliversg");
        set_temp("owner_name", "阿爾七");
        ::setup();
}
