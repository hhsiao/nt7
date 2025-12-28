// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("笨頭虎[2;37;0m[2;37;0m", ({"littletiger"}));        
        set("gender", "女性");                
        set("long", "笨頭虎[2;37;0m
它是胖頭胖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pangtou");
        set("owner_name", "胖頭胖");
        set_temp("owner", "pangtou");
        set_temp("owner_name", "胖頭胖");
        ::setup();
}
