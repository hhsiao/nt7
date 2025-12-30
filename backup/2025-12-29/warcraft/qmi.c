// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m禿頭[2;37;0m[2;37;0m", ({"qmii"}));        
        set("gender", "男性");                
        set("long", "禿頭[2;37;0m
它是水幫主的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "qmi");
        set("owner_name", "水幫主");
        set_temp("owner", "qmi");
        set_temp("owner_name", "水幫主");
        ::setup();
}
