// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大白[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "大白[2;37;0m
它是夢夢帝的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aiwr");
        set("owner_name", "夢夢帝");
        set_temp("owner", "aiwr");
        set_temp("owner_name", "夢夢帝");
        ::setup();
}
