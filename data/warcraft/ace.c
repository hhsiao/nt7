// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m千王之王[2;37;0m[2;37;0m", ({"aoe"}));        
        set("gender", "女性");                
        set("long", "千王之王[2;37;0m
它是豬五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ace");
        set("owner_name", "豬五");
        set_temp("owner", "ace");
        set_temp("owner_name", "豬五");
        ::setup();
}
