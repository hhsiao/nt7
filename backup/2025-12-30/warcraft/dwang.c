// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m萬古[1;36m青天[1;33m獸[2;37;0m[2;37;0m", ({"dwlin"}));        
        set("gender", "女性");                
        set("long", "萬古青天獸[2;37;0m
它是水冰玉的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "dwang");
        set("owner_name", "水冰玉");
        set_temp("owner", "dwang");
        set_temp("owner_name", "水冰玉");
        ::setup();
}
