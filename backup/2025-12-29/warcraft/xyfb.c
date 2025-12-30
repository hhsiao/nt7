// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是葉秋雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyfb");
        set("owner_name", "葉秋雨");
        set_temp("owner", "xyfb");
        set_temp("owner_name", "葉秋雨");
        ::setup();
}
