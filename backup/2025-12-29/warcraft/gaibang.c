// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是丐幫小號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gaibang");
        set("owner_name", "丐幫小號");
        set_temp("owner", "gaibang");
        set_temp("owner_name", "丐幫小號");
        ::setup();
}
