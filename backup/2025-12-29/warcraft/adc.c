// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("剛剛[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "過來[2;37;0m
它是輸出的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "adc");
        set("owner_name", "輸出");
        set_temp("owner", "adc");
        set_temp("owner_name", "輸出");
        ::setup();
}
