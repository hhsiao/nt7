// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m亂紅蓮[2;37;0m[2;37;0m", ({"nue"}));        
        set("gender", "女性");                
        set("long", "這是一隻有著許多眼睛紅色獅子，尾巴變成了許多條響尾蛇。[2;37;0m
它是諫山黃泉的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yomi");
        set("owner_name", "諫山黃泉");
        set_temp("owner", "yomi");
        set_temp("owner_name", "諫山黃泉");
        ::setup();
}
