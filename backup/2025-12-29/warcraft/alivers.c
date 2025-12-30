// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m追尋人生[2;37;0m[2;37;0m", ({"life"}));        
        set("gender", "男性");                
        set("long", "追尋人生[2;37;0m
它是阿爾烏斯的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "alivers");
        set("owner_name", "阿爾烏斯");
        set_temp("owner", "alivers");
        set_temp("owner_name", "阿爾烏斯");
        ::setup();
}
