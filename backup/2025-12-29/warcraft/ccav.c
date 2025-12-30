// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"cnn"}));        
        set("gender", "男性");                
        set("long", "這個是條龍[2;37;0m
它是綣閬氚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ccav");
        set("owner_name", "綣閬氚");
        set_temp("owner", "ccav");
        set_temp("owner_name", "綣閬氚");
        ::setup();
}
