// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m財富寶[2;37;0m[2;37;0m", ({"cashsi"}));        
        set("gender", "男性");                
        set("long", "財富財富，劫貧濟富！[2;37;0m
它是淘寶不肆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taobaosi");
        set("owner_name", "淘寶不肆");
        set_temp("owner", "taobaosi");
        set_temp("owner_name", "淘寶不肆");
        ::setup();
}
