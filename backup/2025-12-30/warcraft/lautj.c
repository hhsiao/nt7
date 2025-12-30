// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m老爺車[2;37;0m[2;37;0m", ({"lautjbb"}));        
        set("gender", "男性");                
        set("long", "尼瑪臥槽樂[2;37;0m
它是不辣公公的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lautj");
        set("owner_name", "不辣公公");
        set_temp("owner", "lautj");
        set_temp("owner_name", "不辣公公");
        ::setup();
}
