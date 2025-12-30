// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血之盟約[2;37;0m[2;37;0m", ({"sleeppbag"}));        
        set("gender", "男性");                
        set("long", "於一身的強大生物，幻獸呀！請你以最深的靈性，聆聽我的傾訴[2;37;0m
它是地面親爹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "donggaua");
        set("owner_name", "地面親爹");
        set_temp("owner", "donggaua");
        set_temp("owner_name", "地面親爹");
        ::setup();
}
