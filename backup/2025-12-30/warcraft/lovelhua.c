// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m麒麟真龍[2;37;0m[2;37;0m", ({"dragonn"}));        
        set("gender", "女性");                
        set("long", "魔幻獸[2;37;0m
它是神劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lovelhua");
        set("owner_name", "神劍");
        set_temp("owner", "lovelhua");
        set_temp("owner_name", "神劍");
        ::setup();
}
