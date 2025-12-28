// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m咫尺千里[2;37;0m[2;37;0m", ({"huoniao"}));        
        set("gender", "女性");                
        set("long", "咫尺千里[2;37;0m
它是水冰煙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dlinwy");
        set("owner_name", "水冰煙");
        set_temp("owner", "dlinwy");
        set_temp("owner_name", "水冰煙");
        ::setup();
}
