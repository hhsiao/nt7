// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m火氣[1;32m騰[1;35m騰[2;37;0m[2;37;0m[2;37;0m", ({"blazing"}));        
        set("gender", "男性");                
        set("long", "火氣騰騰！[2;37;0m
它是火炎焱的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "blaze");
        set("owner_name", "火炎焱");
        set_temp("owner", "blaze");
        set_temp("owner_name", "火炎焱");
        ::setup();
}
