// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"suoni"}));        
        set("gender", "男性");                
        set("long", "龍頭、鹿角、獅眼、虎背、熊腰、蛇鱗、馬蹄、豬尾。[2;37;0m
它是弟子白的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nodust");
        set("owner_name", "弟子白");
        set_temp("owner", "nodust");
        set_temp("owner_name", "弟子白");
        ::setup();
}
