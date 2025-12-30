// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小青蛇[2;37;0m[2;37;0m", ({"xiaoqing"}));        
        set("gender", "女性");                
        set("long", "一條小蛇而已。[2;37;0m
它是護舒寶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hushubao");
        set("owner_name", "護舒寶");
        set_temp("owner", "hushubao");
        set_temp("owner_name", "護舒寶");
        ::setup();
}
