// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小蟲子[2;37;0m[2;37;0m", ({"icq"}));        
        set("gender", "女性");                
        set("long", "喵嗚[2;37;0m
它是小阿的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiao");
        set("owner_name", "小阿");
        set_temp("owner", "xiao");
        set_temp("owner_name", "小阿");
        ::setup();
}
