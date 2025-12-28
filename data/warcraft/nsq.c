// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m煙花[2;37;0m[2;37;0m", ({"yhh"}));        
        set("gender", "女性");                
        set("long", "火紅的煙花[2;37;0m
它是聶霜卿的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nsq");
        set("owner_name", "聶霜卿");
        set_temp("owner", "nsq");
        set_temp("owner_name", "聶霜卿");
        ::setup();
}
