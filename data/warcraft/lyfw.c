// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m飛豬[2;37;0m[2;37;0m", ({"wdcat"}));        
        set("gender", "女性");                
        set("long", "豬在天上飛[2;37;0m
它是櫻飛雪的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lyfw");
        set("owner_name", "櫻飛雪");
        set_temp("owner", "lyfw");
        set_temp("owner_name", "櫻飛雪");
        ::setup();
}
