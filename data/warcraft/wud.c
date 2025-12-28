// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m戰[36m龍[2;37;0m[2;37;0m", ({"zlong"}));        
        set("gender", "女性");                
        set("long", "一隻強大的遠古$MAG$戰$CYN$龍[2;37;0m
它是武當小子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wud");
        set("owner_name", "武當小子");
        set_temp("owner", "wud");
        set_temp("owner_name", "武當小子");
        ::setup();
}
