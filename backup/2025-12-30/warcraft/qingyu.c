// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青靈[2;37;0m[2;37;0m", ({"asd"}));        
        set("gender", "女性");                
        set("long", "青靈[2;37;0m
它是張青玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qingyu");
        set("owner_name", "張青玉");
        set_temp("owner", "qingyu");
        set_temp("owner_name", "張青玉");
        ::setup();
}
