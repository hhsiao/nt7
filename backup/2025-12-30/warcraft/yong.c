// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xiaolong"}));        
        set("gender", "女性");                
        set("long", "一隻可愛的小龍[2;37;0m
它是小姐大的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yong");
        set("owner_name", "小姐大");
        set_temp("owner", "yong");
        set_temp("owner_name", "小姐大");
        ::setup();
}
