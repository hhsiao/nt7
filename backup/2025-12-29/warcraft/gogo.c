// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("貓[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "女性");                
        set("long", "小花貓[2;37;0m
它是行雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "gogo");
        set("owner_name", "行雲");
        set_temp("owner", "gogo");
        set_temp("owner_name", "行雲");
        ::setup();
}
