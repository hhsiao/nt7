// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "居家旅行必備之物。[2;37;0m
它是魔首領的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mpurena");
        set("owner_name", "魔首領");
        set_temp("owner", "mpurena");
        set_temp("owner_name", "魔首領");
        ::setup();
}
