// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m善[1;31m解[1;36m人[1;35m衣[2;37;0m[2;37;0m[2;37;0m", ({"sexy"}));        
        set("gender", "男性");                
        set("long", "激情！[2;37;0m
它是激情瞬間的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gentle");
        set("owner_name", "激情瞬間");
        set_temp("owner", "gentle");
        set_temp("owner_name", "激情瞬間");
        ::setup();
}
