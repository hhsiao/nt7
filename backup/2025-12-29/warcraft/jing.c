// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("草莓[2;37;0m[2;37;0m", ({"caomao"}));        
        set("gender", "女性");                
        set("long", "好吃ㄉ水果[2;37;0m
它是靜玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jing");
        set("owner_name", "靜玉");
        set_temp("owner", "jing");
        set_temp("owner_name", "靜玉");
        ::setup();
}
