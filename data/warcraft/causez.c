// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大頭一號[2;37;0m[2;37;0m", ({"causeq"}));        
        set("gender", "女性");                
        set("long", "大頭一號[2;37;0m
它是牛大的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "causez");
        set("owner_name", "牛大");
        set_temp("owner", "causez");
        set_temp("owner_name", "牛大");
        ::setup();
}
